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

#define VP vector<pair<int, int> >
const int N = 210000;
typedef int T;
struct BIT{
	BIT(){
		init(N-1);
	}
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
}ba, bb;
VP seq;
vector<pair<pair<int, int>, int> > in;
int rev[N], a[N];
int ans[N];
map<pair<int,int>, int> mp;
int main(){
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		rev[a[i]] = i;
	}
	int l, r, tl, tr;
	for (int i=1; i<=m; ++i){
		cin >> l >> r;
		if (l > r) swap(l, r);
		in.PB(MP(MP(l, r), i));
	}
	sort(in.begin(), in.end());
	for (int i=1; i<=n; ++i){
		for (int j=i; j<=n; j+=i){
			int a = rev[i];
			int b = rev[j];
			if (a > b) swap(a, b);
			ba.update(a, 1), ba.update(b, 1);
			bb.update(a, 1), bb.update(b, -1);
			seq.PB(MP(a, b));
		}
	}
	sort(seq.begin(), seq.end());
	int j = 0, len = seq.size();
	int id;
	pair<pair<int, int>, int> tmp;
	for (int i=0; i<m; ++i){
		tmp = in[i];
		l = in[i].first.first;
		r = in[i].first.second;
		id = in[i].second;
		for (;j<len && seq[j].first<l; ++j){
			tl = seq[j].first;
			tr = seq[j].second;
			ba.update(tl, -1), ba.update(tr, -1);
			bb.update(tl, -1), bb.update(tr, 1);
		}
		ans[id] = (ba.get(r) - bb.get(r)) / 2;
	}
	for (int i=1; i<=m; ++i){
		cout << ans[i] << endl;
	}
	return 0;
}