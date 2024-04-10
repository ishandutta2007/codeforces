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
#define ff(i, n) for(i=0; i<n; ++i)

const int N = 110000;
lld ip[N] = {0};
int n, k;
int count(lld mask){
	lld last = -1;
	int ans = 0, cnt=0;
	for (int i=0; i<n; ++i){
		if ((ip[i] & mask) == last){
		}else {
			last = ip[i] & mask;
			ans ++;
		}
	}
	return ans;
}

int main(){
	int a;
	cin >> n >> k;
	for (int i=0; i<n; ++i){
		for (int j=0; j<4; ++j) {
			scanf("%d", &a);
			getchar();
			ip[i] = (ip[i] << 8) | a;
		}
	}
	sort(ip, ip+n);
	lld mask = (1LL << 32) - 1;
	lld tmp = -1;
	for (int i=0; i<31; ++i){
		mask ^= 1LL << i;
		if (count(mask) == k) {
			tmp = mask;
		}
	}
	if (tmp == -1){
		puts("-1");
		return 0;
	}
	int ans[4];
	mask = tmp;
	for (int i=3; i>=0; --i){
		ans[i] = mask & 255;
		mask >>= 8;
	}
	printf("%d.%d.%d.%d\n", ans[0], ans[1], ans[2], ans[3]);
	return 0;
}