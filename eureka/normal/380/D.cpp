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
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define pdef int l, int r, int rt
template<class T> T modDivide(T a, T b, T p){
	T x, y, g;
	g = euclid(b, p, x, y);
	if(a%g) return -1;
	return a/g*checkmod(x, p)%p;
}
const int N = 110000;
const lld P = 1000000007;
lld fac[N], inv[N];

lld comb(int n, int m){
	return fac[n] * inv[m] % P * inv[n-m] % P;
}

lld p2(int n){
	lld ans = 1;
	for (int i=0; i<n; ++i){
		ans = ans * 2 % P;
	}
	return ans;
}
lld dp[N][2];
vector<PII > a;
int n, t;
void gao(int l, int r, int p, int nn, lld cur, lld nxt[2]){
	if (l < 1 || r > n) return;
	int m, j;
	if (p > r){
		m = p - r - 1;
		j = 0;
	}else if (l > p){
		m = l - p - 1;
		j = 1;
	}else return;
	if (m > nn) return;
	cur = cur * comb(nn, m) % P;
	nxt[j] += cur;
}
int he[N];
int main(){
	fac[0] = 1, inv[0] = 1;
	for (int i=1; i<N; ++i){
		fac[i] = fac[i-1] * i % P;
		inv[i] = modDivide(1LL, fac[i], P);
	}
	cin >> n;
	for (int i=1; i<=n; ++i){
		cin >> t;
		he[t] = i;
	}
	for (int i=1; i<=n; ++i){
		if (he[i] == 0) continue;
		a.push_back(make_pair(i, he[i]));
	}
	a.push_back(make_pair(n+1, n+1));
	dp[0][0] = p2(a[0].first-2);
	dp[0][1] = p2(a[0].first-2);
	for (int i=0; i+1<a.size(); ++i){
		int f = a[i].first, s = a[i].second;
		int ff = a[i+1].first, ss = a[i+1].second;
		gao(s-f+1, s, ss, ff-1-f, dp[i][0], dp[i+1]);
		if (f!=1) gao(s, s+f-1, ss, ff-1-f, dp[i][1], dp[i+1]);
	}
	for (int i=0; i<a.size(); ++i){
		//cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
	}
	cout << dp[a.size()-1][0] << endl;
	return 0;
}