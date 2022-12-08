// 15:27 - 15:51 - wa sample
//       - 15:57 - pass sample - tle 5
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
const int MAXN=200010;
const int MAXM=100010;
const LL INFI=1LL<<50;

struct Val {
	PLL v[2];
	Val() { v[0]=v[1]=MP(-INFI, 0); }
	void add(PLL b) {
		if(b.se==v[0].se || b.se==v[1].se)
			return;
		if(b>v[1]) {
			v[1]=b;
			if(v[1]>v[0]) swap(v[1], v[0]);
		}
	}
	void add(Val b) {
		add(b.v[0]);
		add(b.v[1]);
	}
};
struct SegTree {
	Val tr[MAXN*4];
	void add(int x, int s, int t, int ind, PLL v) {
		tr[x].add(v);
		if(s==t) return;
		int m=(s+t)/2;
		if(ind<=m) add(x*2, s, m, ind, v);
			else add(x*2+1, m+1, t, ind, v);
		tr[x]=tr[x*2]; tr[x].add(tr[x*2+1]);
	}
	Val get(int x, int s, int t, int l, int r) {
		int m=(s+t)/2;
		if(l<=s && t<=r) return tr[x];
		Val v;
		if(l<=m) v.add(get(x*2, s, m, l, r));
		if(m+1<=r) v.add(get(x*2+1, m+1, t, l, r));
		return v;
	}
} ta, tb;

LL pos[MAXN];
int d[MAXN], h[MAXN];
int n, m;

int main() {
//*
	scanf("%d%d", &n,&m);
	forint(i, 1, n) scanf("%d", &d[i]);
	forint(i, 1, n) scanf("%d", &h[i]), h[i+n]=h[i];
/*/
	n=m=10000;
	forint(i, 1, n) d[i]=rand()%10000+1;
	forint(i, 1, n) h[i]=rand()%10000+1;
//*/

	forint(i, 1, n) h[i+n]=h[i];
	pos[0]=pos[1]=0;
	forint(i, 1, n) pos[i+1]=pos[i]+d[i];
	forint(i, 1, n) pos[n+i+1]=pos[n+i]+d[i];

	forint(i, 1, n*2) {
		PLL a;
		a.fi=LL(h[i])*2+pos[i];
		a.se=LL(h[i])*2-pos[i];
		ta.add(1, 1, n*2, i, MP(a.fi, LL(i)));
		tb.add(1, 1, n*2, i, MP(a.se, LL(i)));
		//printf("a[%d]: %lld %lld\n",i,a[i].fi,a[i].se);
	}

	forint(i, 1, m) {
		int a, b; scanf("%d%d", &a,&b);
		int x, y;
		if(a<=b)
			x=b+1, y=n+a-1;
		else
			x=b+1, y=a-1;
		Val va=ta.get(1, 1, n*2, x, y);
		Val vb=tb.get(1, 1, n*2, x, y);
		LL ans=-INFI;
		forn(u, 2) forn(v, 2)
			if(va.v[u].se!=vb.v[v].se)
				setmax(ans, va.v[u].fi+vb.v[v].fi);
		cout<<ans<<endl;
	}

/*
	forint(i, 1, m) {
		int a, b; scanf("%d%d", &a,&b);
		int a=rand()%n+1, b=rand()%n+1;
		if(a<=b)
			queries[i]=Query(b+1, n+a-1, i);
		else
			queries[i]=Query(b+1, a-1, i);
	}
	sort(queries+1, queries+m+1, cmp_by_a);
	for(int i=1, j; i<=m; i=j+1) {
		j=min(i+300, m);
		sort(queries+i, queries+j+1, cmp_by_b);
	}

	forint(i, 1, n*2) {
		a[i].fi=LL(h[i])*2+pos[i];
		a[i].se=LL(h[i])*2-pos[i];
		//printf("a[%d]: %lld %lld\n",i,a[i].fi,a[i].se);
	}

	PairSet p; int ci=1, cj=0;
	forint(k, 1, m) {
		int i=queries[k].a, j=queries[k].b;
		while(cj<j) { ++cj; p.ins(a[cj], cj); }
		while(ci>i) { --ci; p.ins(a[ci], ci); }
		while(cj>j) { p.del(a[cj], cj); --cj; }
		while(ci<i) { p.del(a[ci], ci); ++ci; }
		//printf("ci=%d cj=%d\n",ci,cj);
		ans[queries[k].i]=p.get();
	}
	forint(k, 1, m) cout<<ans[k]<<endl;
*/

	return 0;
}