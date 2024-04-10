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

const int N = 102;
const lld P = 1000000007;
//max, r, num of max, k
lld dp[53][N][52][N];
int comb[N][N];
int main(){
	for (int i=0; i<N; ++i){
		comb[i][0] = comb[i][i] = 1;
		for (int j=1; j<i; ++j){
			comb[i][j] = min(N, comb[i-1][j] + comb[i-1][j-1]);
		}
	}
	int n, m, kind;
	cin >> n >> m >> kind;
	lld ans = -m;
	dp[1][0][1][1] = 1;
	for (int i=1; i<=n/2+1 && i <= m; ++i) for (int j=0; j<=n; ++j) for (int l=0; l<=n/2+1; ++l) for (int k=1; k<=kind; ++k){
		dp[i][j][l][k] %= P;
		if (dp[i][j][l][k] == 0) continue;
		ans += dp[i][j][l][k] * (m - i + 1);
		ans %= P;
		for (int nl=1; 2*nl+j<=n && comb[l+nl-1][nl] * k <= kind; ++nl){
			dp[i+1][j+2*nl][nl][comb[l+nl-1][nl]*k] += dp[i][j][l][k];
			dp[i+1][j+2*nl][nl][comb[l+nl-1][nl]*k] %= P;
		}
	}
	cout << ans << endl;
	return 0;
}