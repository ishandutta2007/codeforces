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

const int N = 1100;
int r[N][N], d[N][N];
int a[N][N];
int h, w, k;

int init(char *ch, int *ans){
	for (int i=0; ch[i]; ++i){
		if (ch[i] == 'E') ans[i] = 0;
		else ans[i] = 1;
	}
}

int count(){
	int ans = 0;
	for (int i=0; i<h; ++i) for (int j=0; j<w; ++j){
		if (j+1 != w && (a[i][j] ^ a[i][j+1]) == r[i][j]) ans ++;
		if (i+1 != h && (a[i][j] ^ a[i+1][j]) == d[i][j]) ans ++;
	}
	return ans;
}

void color1(){
	for (int i=0; i<h; ++i){
		int cnt = 0;
		a[i][0] = 0;
		for (int j=1; j<w; ++j) a[i][j] = a[i][j-1] ^ r[i][j-1];
		if (i) for (int j=0; j<w; ++j) cnt += a[i-1][j] ^ a[i][j] ^ d[i-1][j];
		if (2 * cnt > w) for (int j=0; j<w; ++j) a[i][j] ^= 1;
	}
}

void color2(){
	for (int j=0; j<w; ++j){
		int cnt = 0;
		a[0][j] = 0;
		for (int i=1; i<h; ++i) a[i][j] = a[i-1][j] ^ d[i-1][j];
		if (j) for (int i=0; i<h; ++i) cnt += a[i][j-1] ^ a[i][j] ^ r[i][j-1];
		if (2 * cnt > h) for (int i=0; i<h; ++i) a[i][j] ^= 1;
	}
}

int main(){
	char ch[N];
	cin >> h >> w >> k;
	for (int i=0; i<h; ++i){
		scanf("%s", ch);
		init(ch, r[i]);
		if (i+1 != h){
			scanf("%s", ch);
		   	init(ch, d[i]);
		}
	}
	int tot = (((h - 1) * w + (w - 1) * h) * 3 + 3) / 4;
	if (k == 1){
		if (count() < tot){
			puts("NO");
			return 0;
		}
	}else {
		color1();
		if (count() < tot) color2();
		if (count() < tot){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i=0; i<h; ++i){
		for (int j=0; j<w; ++j){
			printf("%d ", a[i][j] + 1);
		}
		puts("");
	}
	return 0;
}