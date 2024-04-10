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
#define ff(I,N)    FOR(I,0,N)
#define shl(i)      ((lld)1 << (i))

const int N = 200;
int a[N], b[N], c[N];
int l[N], r[N];
int n, m;

void dfs(int d, int cl, int cr, int cost){
	if (d == n){
		if (cr == 0) checkmin(l[cl], cost);
		if (cl == 0) checkmin(r[cr], cost);
		return;
	}
	dfs(d+1, cl+1, cr, cost+a[d]);
	if (cl > 0){
		dfs(d+1, cl-1, cr, cost+b[d]);
	}else {
		dfs(d+1, cl, cr+1, cost+b[d]);
	}
}

int gao(int cl, int cr){
	int sum = 0;
	for (int i=0; i<n; ++i) sum += b[i] * m;
	for (int i=0; i<n; ++i){
		int t = min(cl, m);
		cl -= t;
		sum += c[i] * t;
	}
	return sum;
}

int main(){
	cin >> n >> m;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<n; ++i) cin >> b[i];

	for (int i=0; i<n; ++i){
		c[i] = a[i] - b[i];
	}
	sort(c, c+n);
	mem(l, 0x3f), mem(r, 0x3f);
	dfs(0, 0, 0, 0);
	m -= 2;
	lld ans = lldmax;
	lld all = n * (m+2) / 2;
	for (int i=0; i<=n; ++i) for (int j=0; j<=n; ++j){
		if (l[i] == intmax || r[j] == intmax) continue;
		lld t = (n - i + n - j) / 2;
		checkmin(ans, 0LL+gao(all-i-t, all-j-t)+l[i]+r[j]);
		//cout << l[i] + r[j] << ' ' << i << ' ' << j << ' ' << l[i] + r[j] + gao(all-i-t, all-j-t) << endl;
	}
	cout << ans << endl;
	int sum = 0;
	for (int i=0; i<n; ++i) sum += b[i];
	//cout << sum << ' ' << r[n] << endl;
	return 0;
}