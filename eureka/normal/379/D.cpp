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
real eps=1e-8;//NOTES:eps
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
#define MP(a, b) make_pair(a, b)
#define PII pair<int, int>

const int N = 110;
int k, x, n, m;
lld dp[N];
char ca[N], cb[N];
bool gao(int nn, int mm, int sa, int ta, int sb, int tb){
	if (2 * nn + sa + ta > n) return false;
	if (2 * mm + sb + tb > m) return false;
	dp[1] = nn;
	dp[2] = mm;
	dp[3] = nn + mm + (ta & sb);
	for (int i=4; i<=k; ++i){
		dp[i] = dp[i-1] + dp[i-2];
		if (i % 2 == 0) dp[i] += tb & sa;
		else dp[i] += tb & sb;
		checkmin(dp[i], x+1LL);
	}
	return dp[k] == x;
}

bool print(int nn, int mm, int sa, int ta, int sb, int tb){
	mem(ca, 'B');
	mem(cb, 'B');
	ca[n] = 0, cb[m] = 0;
	int s = 0;
	if (sa) {
		ca[s++] = 'C';
	}
	for (int i=0; i<nn; ++i){
		ca[s++] = 'A';
		ca[s++] = 'C';
	}
	if (ta) ca[n-1] = 'A';

	s = 0;
	if (sb) {
		cb[s++] = 'C';
	}
	for (int i=0; i<mm; ++i){
		cb[s++] = 'A';
		cb[s++] = 'C';
	}
	if (tb) cb[m-1] = 'A';
	puts(ca);
	puts(cb);
}

int main(){
	cin >> k >> x >> n >> m;
	for (int i=0; 2*i<=n; ++i){
		for (int j=0; 2*j<=m; ++j){
			for (int k=0; k<=1; ++k) for (int l=0; l<=1; ++l)
				for (int kk=0; kk<=1; ++kk) for (int ll=0; ll<=1; ll++){
				if (gao(i, j, k, l, kk, ll)){
					print(i, j, k, l, kk, ll);
					return 0;
				}
			}
		}
	}
	puts("Happy new year!");
	return 0;
}