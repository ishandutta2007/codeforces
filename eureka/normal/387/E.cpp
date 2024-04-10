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
real eps=1e-8;//NOTES:eps
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
#define MP(a, b) make_pair(a, b)
#define PII pair<int, int>

const int N = 1100000;
int a[N];
int b[N];
int l[N], r[N];
int mk[N];
#define T int
struct BIT{
	void init(T n){
		memset(a, 0, sizeof(a));
		this->n = n;
	}
	void update(T i, T b){
		while(i <= n){
			a[i] += b;
			i += i&(-i);
		}
	}
	T get(T i){
		T ans=0;
		while(i){
			ans += a[i];
			i &= i-1;
		}
		return ans;
	}
	T a[N], n;
}bit;

int main(){
	vector<PII > q;
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; ++i) cin >> a[i];
	for (int i=1; i<=m; ++i) cin >> b[i];
	for (int i=1, j=1; i<=n; ++i){
		if (a[i] == b[j]){
			j ++;
		}else {
			mk[i] = 1;
			q.push_back(make_pair(a[i], i));
		}
	}
	sort(q.begin(), q.end());
	a[0] = a[n+1] = 0;
	int lst = 0;
	for (int i=1; i<=n; ++i){
		for(l[i] = lst; a[l[i]] > a[i]; l[i] = l[l[i]]);
		if (mk[i] == 0) lst = i;
	}
	lst = n + 1;
	for (int i=n; i>=1; --i){
		for(r[i] = lst; a[r[i]] > a[i]; r[i] = r[r[i]]);
		if (mk[i] == 0) lst = i;
	}
	lld ans = 0;
	bit.init(n);
	for (int i=1; i<=n; ++i) bit.update(i, 1);
	for (int j=0; j<q.size(); ++j){
		int i = q[j].second;
		ans += bit.get(r[i]-1) - bit.get(l[i]);
		bit.update(i, -1);
	}
	cout << ans << endl;
	return 0;
}