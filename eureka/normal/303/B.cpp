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

lld ans[4];
lld x, y;
lld n, m, a, b;
lld dis(lld x1, lld y1, lld x2, lld y2){
	return sqr(x*2 - x1 - x2) + sqr(y*2 - y1 - y2);
}

void update(lld x1, lld y1, lld x2, lld y2){
	bool copy = false;
	lld tmp[4];
	tmp[0] = x1, tmp[1] = y1, tmp[2] = x2, tmp[3] = y2;
	if (x1 < 0 || x1 > n) return;
	if (x2 < 0 || x2 > n) return;
	if (y1 < 0 || y1 > m) return;
	if (y2 < 0 || y2 > m) return;
	if (x1 > x || x2 < x) return;
	if (y1 > y || y2 < y) return;
	if (x1 == x2 || y1 == y2) return;
	lld dy = y2 - y1, dx = x2 - x1;
	lld g = gcd(dy, dx);
	dy /= g, dx /= g;
	if (dy * a != dx * b) {
		return;
	}
	if (ans[0] == -1){
		copy = true;
	}else{
		lld da = dis(ans[0], ans[1], ans[2], ans[3]);
		lld db = dis(x1, y1, x2, y2);
		if (db < da){
			copy = true;
		}else if (db == da){
			for (lld i=0; i<4; ++i){
				if (tmp[i] < ans[i]){
					copy = true;
				}
				if (tmp[i] != ans[i]) break;
			}
		}
	}
	if (copy){
		for (lld i=0; i<4; ++i) ans[i] = tmp[i];
	}
}

int main(){
	mem(ans, 0xff);
	cin >> n >> m >> x >> y >> a >> b;
	lld g = gcd(a, b);
	a /= g;
	b /= g;

	lld mul = lldmax;
	checkmin(mul, n/a);
	checkmin(mul, m/b);
	a *= mul, b *= mul;
	update(0, 0, a, b);
	update(0, m-b, a, m);
	update(n-a, 0, n, b);
	update(n-a, m-b, n, m);

	int ta = a/2, tb=b/2;
	update(x-ta, y-tb, x+a-ta, y+b-tb);
	update(0, y-tb, a, y+b-tb);
	update(n-a, y-tb, n, y+b-tb);
	update(x-ta, 0, x+a-ta, b);
	update(x-ta, m-b, x+a-ta, m);
	ta ++;
	update(x-ta, y-tb, x+a-ta, y+b-tb);
	update(0, y-tb, a, y+b-tb);
	update(n-a, y-tb, n, y+b-tb);
	update(x-ta, 0, x+a-ta, b);
	update(x-ta, m-b, x+a-ta, m);
	tb ++;
	update(x-ta, y-tb, x+a-ta, y+b-tb);
	update(0, y-tb, a, y+b-tb);
	update(n-a, y-tb, n, y+b-tb);
	update(x-ta, 0, x+a-ta, b);
	update(x-ta, m-b, x+a-ta, m);
	ta --;
	update(x-ta, y-tb, x+a-ta, y+b-tb);
	update(0, y-tb, a, y+b-tb);
	update(n-a, y-tb, n, y+b-tb);
	update(x-ta, 0, x+a-ta, b);
	update(x-ta, m-b, x+a-ta, m);
	for (int i=0; i<4; ++i){
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}