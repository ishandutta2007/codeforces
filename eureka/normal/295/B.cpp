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

const int N = 520;
lld mat[N][N], in[N][N];
lld ans[N] = {0};
int main(){
	int n, a;
	int has[N];
	cin >> n;
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			cin >> in[i][j];
		}
	}
	for (int i=1; i<=n; ++i){
		cin >> a;
		has[a] = n+1-i;
	}
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			mat[has[i]][has[j]] = in[i][j];
		}
	}
	for (int k=1; k<=n; ++k){
		for (int i=1; i<=n; ++i){
			for (int j=1; j<=n; ++j){
				checkmin(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
		for (int i=1; i<=k; ++i){
			for (int j=1; j<=k; ++j){
				ans[n-k] += mat[i][j];
			}
		}
	}
	for (int i=0; i<n; ++i) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}