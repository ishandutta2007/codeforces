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
#define cp complex<double>
#define comp complex<double>

const int N = 110;
const int M = 1100;
lld ans[N][M][2];
const lld P = 7340033;
lld gao(int n, int m, int b){
	if (ans[n][m][b] != -1) return ans[n][m][b];
	if (m == 0) return 1;
	if (n == 0) return 0;
	lld sum = 0;
	if (b == 1){
		for (int i=0; i<=m-1; ++i){
			sum += gao(n-1, i, 0) * gao(n-1, m-1-i, 0) % P;
		}
	}else {
		for (int i=0; i<=m; ++i){
			sum += gao(n, i, 1) * gao(n, m-i, 1) % P;
		}
	}
	return ans[n][m][b] = sum % P;
}

int main(){
	mem(ans, 0xff);
	int n, k, cnt;
	int cases;
	cin >> cases;
	while (cases --){
		cin >> n >> k;
		for (cnt=0; n>1 && (n&1)==1; n >>= 1, cnt ++);
		cout << gao(cnt, k, 1) << endl;
	}
	return 0;
}