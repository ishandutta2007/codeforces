#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bitset>
using namespace std;
typedef double real;
const real pi=acos(-1.0);//NOTES:pi
typedef long long lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
real eps=1e-6;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
inline int rand(int a, int b) {if(a >= b) return a; return rand() % (b-a) + a;}//NOTES:rand(
//Numberic Functions
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
{vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
{if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
{vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define FOR(I,A,B)    for(int I = (A); I < (B); ++I)
#define REP(I,N)    FOR(I,0,N)
#define shl(i)      ((lld)1 << (i))

const int N = 1100000;
const int M = 4000;
char t[N], s[M];
int k;
int lt, ls, td, tr, sd, sr;
int best[N] = {2, 0}, cur[N];

void update(int *a){
	bool flag = false;
	for (int i=0; i<k; ++i) {
		if (a[i] != best[i]){
			flag = (a[i] < best[i]);
			break;
		}
	}
	if (flag){
		for (int i=0; i<k; ++i) best[i] = a[i];
	}
}

void gao(int n, int m){
	int ln = k - tr, lm = tr;
	int cnt = 0;
	//cout << n << ' ' << m << endl;
	for (int i=0; i<k; ++i){
		if (i < ln && cnt == n){
			cur[k-1-i] = 0;
			continue;
		}else if (i == ln && cnt != n){
			return;
		}else if (cnt == n + m){
			cur[k-1-i] = 0;
			continue;
		}
		bool ok = true;
		for (int j=k-1-i, l=n+m-1-cnt; j<lt; j+=k, l+=n+m){
			if (t[j] != s[l]){
				ok = false;
				break;
			}
		}
		if (ok){
			cur[k-1-i] = 1;
			cnt ++;
		}else {
			cur[k-1-i] = 0;
		}
	}
	if (cnt != n + m) return;
	update(cur);
}

int main(){
	gets(t);
	gets(s);
	//cout << t << ' ' << s << endl;
	//scanf("%s%s", t, s);
	scanf("%d", &k);
	lt = strlen(t), ls = strlen(s);
	td = lt / k, tr = lt % k;
	for (int i=1; i<=ls && i <= k; ++i){
		sr = ls - td * i;
		if (sr < 0 || sr > i || sr > tr) continue;
		gao(i-sr, sr);
	}
	if (best[0] == 2){
		puts("0");
	}else {
		for (int i=0; i<k; ++i) putchar('0' + best[i]);
		puts("");
	}
	return 0;
}