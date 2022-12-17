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

const int N = 1100000;

lld a[N], cnt[N];
lld ch[N];
	int n, k;
bool check(int m){
	for (int i=0; i<m; ++i) ch[i] = 0;
	lld del = k;
	for (int i=0; i<n; ++i){
		ch[a[i] % m] ++;
		lld tmp = ch[a[i] % m];
		if (tmp > 1) del --;
		if (del < 0) break;
	}
	return del >= 0;
}

int main(){
	cin >> n >> k;
	if (n <= k+1){
		cout << 1 << endl;
		return 0;
	}

	for (int i=0; i<n; ++i) cin >> a[i];
	sort(a, a+n);
	for (int i=0; i<n; ++i){
		for (int j=i+1; j<n; ++j){
			cnt[a[j]-a[i]] ++;
		}
	}
	lld ans = N;
	for (int i=1; i<N; ++i){
		int tmp = 0;
		for (int j=i; j<N; j+=i){
			tmp += cnt[j];
		}
		if (tmp <=k*(k+1)/2  && check(i)){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}