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

#define N 510

int mark[N], link[N], mp[N][N], boy, girl;

int bdfs( int t ){
	int i;

	for(i=1; i<=girl; i++){
		if(mark[i]==0 && mp[t][i]){
			mark[i] = 1;
			if(link[i] == -1 || bdfs(link[i])){
				link[i] = t;
				return 1;
			}
		}
	}
	return 0;
}

int maxmatch(void){
	int i, num = 0;
	memset(link, 0xff, sizeof(link));
	for(i=1; i<=boy; i++){
		memset(mark, 0, sizeof(mark));
		if(bdfs(i)) num ++;
	}
	return num;
}

int a[2*N], b[2*N];
int n, m;
int ans = intmax;
int ot[N], in[N];

int gao(int c){
	int cnt = 0;
	mem(ot, 0);
	mem(in, 0);
	for (int i=0; i<m; ++i){
		if (a[i] == c) in[b[i]] ++;
		if (b[i] == c) ot[a[i]] ++;
	}
	for (int i=1; i<=n; ++i){
		if (i == c){
			cnt += abs(1 - ot[i]);
		}else {
			cnt += abs(1 - ot[i]);
			cnt += abs(1 - in[i]);
		}
	}
	if (cnt >= ans) return cnt;
	boy = girl = n;
	mem(mp, 0);
	int num = 0;
	for (int i=0; i<m; ++i){
		if (a[i] == c || b[i] == c) continue;
		if (mp[a[i]][b[i]] == 1) cnt ++;
		else mp[a[i]][b[i]] = 1, num ++;
	}
	int lst = maxmatch();
	cnt += num - lst;
	cnt += n - 1 - lst;
	return cnt;
}

int main(){
	cin >> n >> m;
	for (int i=0; i<m; ++i) cin >> a[i] >> b[i];
	for (int i=1; i<=n; ++i){
		checkmin(ans, gao(i));
	}
	cout << ans << endl;
	return 0;
}