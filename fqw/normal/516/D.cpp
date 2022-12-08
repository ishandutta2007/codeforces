// 20:00 - 20:10
// 20:31 - 20:38 - wa sample
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
typedef pair<LL,int> PLI;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
const int MAXN=100010;
const LL INFI=1LL<<50;

int g[MAXN], g_lnk[MAXN*2], g_nxt[MAXN*2]; LL g_cst[MAXN*2];
int n;

LL d[MAXN];
PLI ds[MAXN];
PLI h1[MAXN], h2[MAXN];
LL u[MAXN];
void dfs(int x, int fa) {
	h1[x]=h2[x]=MP(0, 0);
	for(int i=g[x], y; i; i=g_nxt[i])
		if((y=g_lnk[i])!=fa) {
			dfs(y, x);
			if(h1[y].fi+g_cst[i]>h2[x].fi) {
				h2[x]=MP(h1[y].fi+g_cst[i], y);
				if(h2[x]>h1[x]) swap(h1[x], h2[x]);
			}
		}
}
void dfs2(int x, int fa) {
	for(int i=g[x], y; i; i=g_nxt[i])
		if((y=g_lnk[i])!=fa) {
			LL c=g_cst[i];
			LL p=(h1[x].se!=y ? h1[x].fi : h2[x].fi);
			u[y]=max(u[x], p)+c;
			dfs2(y, x);
		}
}
void cal_d() {
	if(n==2) {
		d[1]=d[2]=g_cst[1];
	}
	else {
		int root=1;
		while(g_nxt[g[root]]==0)
			++root;
		dfs(root, 0);
		u[root]=-INFI;
		dfs2(root, 0);
		forint(i, 1, n) d[i]=max(u[i], h1[i].fi);
		//forint(i, 1, n) printf("u[%d]=%d\n",i,(int)u[i]);
	}
	forint(i, 1, n) ds[i]=MP(d[i], i);
	sort(ds+1, ds+n+1);
}

int st[MAXN], en[MAXN], cnt;
void pre_dfs(int x, int fa) {
	st[x]=++cnt;
	for(int i=g[x], y; i; i=g_nxt[i])
		if((y=g_lnk[i])!=fa)
			pre_dfs(y, x);
	en[x]=cnt;
}
void pre() {
	int root=1;
	forint(i, 1, n)
		if(d[i]<d[root])
			root=i;
	cnt=0;
	pre_dfs(root, 0);
}

struct Seg {
	int tr[MAXN];
	void clear() { fillchar(tr, 0); }
	void add(int i, int v) {
		for(; i<=n; i+=(i&-i)) tr[_ i]+=v;
	}
	int get(int i) {
		int s=0;
		for(; i>=1; i-=(i&-i)) s+=tr[_ i];
		return s;
	}
	int sum(int i, int j) {
		return get(j)-get(i-1);
	}
};

int main() {
	scanf("%d", &n);
	forn(_, n-1) {
		int a, b, c; scanf("%d%d%d", &a,&b,&c);
		static int e=0;
		g_lnk[++e]=b, g_cst[e]=c, g_nxt[e]=g[a], g[a]=e;
		g_lnk[++e]=a, g_cst[e]=c, g_nxt[e]=g[b], g[b]=e;
	}

	cal_d();
	//forint(i, 1, n) printf("d[%d]=%d\n",i,(int)d[i]);
	pre();
	//forint(i, 1, n) printf("%d: [%d,%d]\n",i,st[i],en[i]);

	int op; scanf("%d", &op);
	static Seg seg;
	seg.clear();
	forn(_, op) {
		LL lim; cin>>lim;
		int j=0;
		int ans=0;
		//printf("case #%d\n", _);
		forint(i, 1, n) {
			while(j<n && ds[j+1].fi<=ds[i].fi+lim) {
				++j;
				seg.add(st[ds[j].se], 1);
			}
			//printf("  i=%d j=%d\n",i,j);
			setmax(ans, seg.sum(st[ds[i].se], en[ds[i].se]));
			seg.add(st[ds[i].se], -1);
		}
		printf("%d\n", ans);
	}
	return 0;
}