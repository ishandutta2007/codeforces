#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bitset>
using namespace std;
typedef double real;
const real pi=acos(-1.0);//NOTES:pi
typedef long long lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
real eps=1e-6;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
inline int rand(int a, int b) {if(a >= b) return a; return rand() % (b-a) + a;}//NOTES:rand(
//Numberic Functions
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
{vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
{if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
{vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define FOR(I,A,B)    for(int I = (A); I < (B); ++I)
#define REP(I,N)    FOR(I,0,N)
#define shl(i)      ((lld)1 << (i))

const int N = 1100;
int n;
lld p[N][N], sx[N][N], sy[N][N], sp[N][N];
void update(int x, int y, lld v){
	if (x == 0 || y == 0) return;
	if (x & y & 1){
		for (int i=x; i<=n; i+=-i&i){
			for (int j=y; j<=n; j+=-j&j){
				sp[i][j] ^= v;
			}
		}
	}
	if (x & 1){
		for (int i=x; i<=n; i+=-i&i){
			for (int j=y; j>=1; j-=-j&j){
				sx[i][j] ^= v;
			}
		}
	}
	if (y & 1){
		for (int i=x; i>=1; i-=-i&i){
			for (int j=y; j<=n; j+=-j&j){
				sy[i][j] ^= v;
			}
		}
	}
	for (int i=x; i>=1; i-=-i&i){
		for (int j=y; j>=1; j-=-j&j){
			p[i][j] ^= v;
		}
	}
}
lld query(int x, int y){
	if (x == 0 || y == 0) return 0;
	lld ans = 0;
	for (int i=x; i>=1; i-=-i&i){
		for (int j=y; j>=1; j-=-j&j){
			ans ^= sp[i][j];
		}
	}
	if (y & 1){
		for (int i=x; i>=1; i-=-i&i){
			for (int j=y+1; j<=n; j+=-j&j){
				ans ^= sx[i][j];
			}
		}
	}
	if (x & 1){
		for (int i=x+1; i<=n; i+=-i&i){
			for (int j=y; j>=1; j-=-j&j){
				ans ^= sy[i][j];
			}
		}
	}
	if (x & y & 1){
		for (int i=x+1; i<=n; i+=-i&i){
			for (int j=y+1; j<=n; j+=-j&j){
				ans ^= p[i][j];
			}
		}
	}
	return ans;
}

int main(){
	int m;
	int k, x0, y0, x1, y1;
	lld v;
	//freopen("in", "r", stdin);
	cin >> n >> m;
	while(m --){
		cin >> k >> x0 >> y0 >> x1 >> y1;
		if (k == 1){
			lld ans = 0;
			ans ^= query(x0-1, y0-1);
			ans ^= query(x1, y0-1);
			ans ^= query(x0-1, y1);
			ans ^= query(x1, y1);
			cout << ans << endl;
		}else {
			cin >> v;
			update(x0-1, y0-1, v);
			update(x1, y0-1, v);
			update(x0-1, y1, v);
			update(x1, y1, v);
		}
	}
	return 0;
}