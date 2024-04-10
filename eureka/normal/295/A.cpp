#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
using namespace std;
typedef long long lld;
//typedef __int64 lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
double eps=1e-8;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define shl(i)      ((lld)1 << (i))
#define MP make_pair
#define PB push_back
#define ff(i, n) for(int i=0; i<n; ++i)

const int N = 210000;

lld a[N] = {0}, b[N] = {0};
int in[N][3];
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=1; i<=n; ++i) scanf("%I64d", &a[i]);
	for (int i=n; i>=1; --i) a[i] -= a[i-1];

	for (int i=1; i<=m; ++i){
		scanf("%d%d%d", &in[i][0], &in[i][1], &in[i][2]);
	}
	int ta, tb;
	for (int i=1; i<=k; ++i){
		scanf("%d%d", &ta, &tb);
		b[ta] ++;
		b[tb+1] --;
	}
	for (int i=1; i<=m; ++i) b[i] += b[i-1];

	for (int i=1; i<=m; ++i){
		a[in[i][0]] += in[i][2] * b[i];
		a[in[i][1]+1] -= in[i][2] * b[i];
	}
	for (int i=1; i<=n; ++i) a[i] += a[i-1];
	for (int i=1; i<=n; ++i) printf("%I64d ", a[i]);
	puts("");
	return 0;
}