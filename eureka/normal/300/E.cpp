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

const int pn = 11000000;
int mark[pn];
int p[pn];
int num;
int prime(int n = pn-1){
	int num = 0, i, j;
	mem(mark, 0xff);
	for(i=2; i<=n; i++){
		if(mark[i] == -1) {
			mark[i] = i;
			p[num++] = i;
		}
		for(j=0; j<num && i*p[j]<n; j++){
			mark[i*p[j]] = p[j];
			if(i%p[j] == 0) break;
		}
	}
	return num;
}
lld cnt[pn] = {0};

lld count(lld p, lld n){
	lld ans = 0;
	for (n /= p; n>0; n/=p)
		ans += n;
	return ans;
}

lld gao(lld p, lld n){
	lld l = 1, r = p * n;
	lld ans = r;
	while(l <= r){
		lld m = (l + r) / 2;
		if (count(p, m) >= n){
			ans = m;
			r = m - 1;
		}else {
			l = m + 1;
		}
	}
	return ans;
}

int main(){
	//freopen("in.txt", "r", stdin);
	prime();
	int n, a;
	cin >> n;
	for (int i=0; i<n; ++i){
		scanf("%d", &a);
		cnt[a] ++;
	}
	lld ans = 1;
	for (int i=pn-10; i>=2; --i){
		cnt[i-1] += cnt[i];
	}
	for (int i=pn-10; i>=2; --i){
		if (cnt[i] == 0) continue;
		if (mark[i] != i){
			cnt[mark[i]] += cnt[i];
			cnt[i/mark[i]] += cnt[i];
		}else {
			if (cnt[i] * i > ans) checkmax(ans, gao(i, cnt[i]));
		}
	}
	cout << ans << endl;
	return 0;
}