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

const int N = 110000;

double x[N], y[N];
pair<double, int> idx[N], idy[N];
int rx[N], ry[N];
bool flag[N];
int n;

double tl[N], tr[N], dl[N], dr[N];

void init(){
	int l, r, t;
	l = n+1, r = 0;
	tl[0] = dl[0] = 1e12;
	tr[0] = dr[0] = -1e12;
	tl[n+1] = dl[n+1] = 1e12;
	tr[n+1] = dr[n+1] = -1e12;
	for (int i=1; i<=n; ++i){
		t = rx[idy[i].second];
		checkmin(l, t);
		checkmax(r, t);
		tl[i] = idx[l].first;
		tr[i] = idx[r].first;
	}
	l = n+1, r = 0;
	for (int i=n; i>=1; --i){
		t = rx[idy[i].second];
		checkmin(l, t);
		checkmax(r, t);
		dl[i] = idx[l].first;
		dr[i] = idx[r].first;
	}
}

bool judge(double len){
	int j = 1, k = 1;
	double r, l;
	for (int i=1; i<=n; ++i){
		while (idy[k].first < idy[i].first - eps) ++k;
		while (j <= n && idy[j].first <= idy[i].first + len) ++j;
		if (k == 1 && j == n+1) return true;
		r = max(tr[k-1], dr[j]);
		l = min(tl[k-1], dl[j]);
		if (r-l <= len) return true;
	}
	return false;
}

int main(){
	double l, r;
	cin >> n;
	for (int i=1; i<=n; ++i){
		scanf("%lf %lf", &l, &r);
		x[i] = l + r;
		y[i] = l - r;
		idx[i] = make_pair(x[i], i);
		idy[i] = make_pair(y[i], i);
	}
	sort(idx+1, idx+1+n);
	sort(idy+1, idy+1+n);
	for (int i=1; i<=n; ++i){
		rx[idx[i].second] = i;
		ry[idy[i].second] = i;
	}
	init();
	l = 0;
	r = 1e11;
	while(r > 1e-7){
		r /= 2;
		if (!judge(l + r)){
			l += r;
		}
	}
	printf("%.9lf\n", l / 2);
	return 0;
}