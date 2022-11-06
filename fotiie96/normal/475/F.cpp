#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl 
#define POP(x) (__builtin_popcount(x))
#define POPL(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
struct pointset {
	set<pair<int,int> > px,py;
	map<int,int> cntx,cnty;
	set<int> rx,ry;
	int queryx() {
		if (px.empty()) return -1;
		while (1) {
			int cx=*rx.begin();
			if (cx<px.begin()->fi) rx.erase(rx.begin());
			else {
				if (cx>px.rbegin()->fi) return -1;
				return cx;
			}
		}
	}
	int queryy() {
		if (py.empty()) return -1;
		while (1) {
			int cy=*ry.begin();
			if (cy<py.begin()->fi) ry.erase(ry.begin());
			else {
				if (cy>py.rbegin()->fi) return -1;
				return cy;
			}
		}
	}
	void build(VPII &c) {
		rep(i,0,SZ(c)) {
			cntx[c[i].fi]++,cnty[c[i].se]++;;
			px.insert(c[i]); py.insert(mp(c[i].se,c[i].fi));
		}
		rep(i,0,SZ(c)) {
			if (!cntx.count(c[i].fi+1)) rx.insert(c[i].fi+1);
			if (!cnty.count(c[i].se+1)) ry.insert(c[i].se+1);
		}
	}
	void del(PII p) {
		px.erase(p); py.erase(mp(p.se,p.fi));
		if ((--cntx[p.fi])==0) rx.insert(p.fi);
		if ((--cnty[p.se])==0) ry.insert(p.se);
	}
}tmp[N]; int tp=0;
int n,x,y,ret;
void gao(pointset &a) {
	int px=a.queryx(),py=a.queryy();
	if (px<0&&py<0) { ret+=1;return;}
	if (px>=0) {
		VPII pl,pr;
		set<PII>::iterator it=a.px.begin();
		set<PII>::reverse_iterator rit=a.px.rbegin();
		while (it->fi<px&&rit->fi>px) {
			pl.pb(*it); pr.pb(*rit);
			++it; ++rit;
		}
		if (it->fi<px) {
			pointset &b=tmp[tp++];
			b.build(pr);
			gao(b);
			rep(j,0,SZ(pr)) a.del(pr[j]);
			gao(a);
		} else {
			pointset &b=tmp[tp++];
			b.build(pl);
			gao(b);
			rep(j,0,SZ(pl)) a.del(pl[j]);
			gao(a);
		}
	} else {
		VPII pl,pr;
		set<PII>::iterator it=a.py.begin();
		set<PII>::reverse_iterator rit=a.py.rbegin();
		while (it->fi<py&&rit->fi>py) {
			pl.pb(mp(it->se,it->fi)); pr.pb(mp(rit->se,rit->fi));
			++it; ++rit;
		}
		if (it->fi<py) {
			pointset &b=tmp[tp++];
			b.build(pr);
			gao(b);
			rep(j,0,SZ(pr)) a.del(pr[j]);
			gao(a);
		} else {
			pointset &b=tmp[tp++];
			b.build(pl);
			gao(b);
			rep(j,0,SZ(pl)) a.del(pl[j]);
			gao(a);
		}
	}
}
VPII vr;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",&x,&y);
		x+=1000000000;
		y+=1000000000;
		vr.pb(mp(x,y));
	}
	pointset &p=tmp[tp++];
	p.build(vr);
	gao(p);
	printf("%d\n",ret);
}