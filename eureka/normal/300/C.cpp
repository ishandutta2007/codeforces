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

const lld P = 1000000007;
const int N = 1100000;
lld fac[N];
template<class T> T modDivide(T a, T b, T p){
	T x, y, g;
	g = euclid(b, p, x, y);
	if(a%g) return -1;
	return a/g*checkmod(x, p)%p;
}

lld comb(lld n, lld m){
	return modDivide(fac[n], fac[m] * fac[n-m] % P, P);
}

lld a, b;
bool is(lld n){
	while(n){
		if (n % 10 != a && n % 10 != b) return false;
		n /= 10;
	}
	return true;
}

int main(){
	fac[0] = 1;
	for (int i=1; i<N; ++i) fac[i] = fac[i-1] * i % P;
	lld ans = 0;
	lld n;
	cin >> a >> b >> n;
	for (int i=0; i<=n; ++i){
		if (is(i * a + (n-i) * b)){
			ans = (ans + comb(n, i)) % P;
		}
	}
	cout << ans << endl;
	return 0;
}