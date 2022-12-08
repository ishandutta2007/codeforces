// 17:53 - 18:26
// 22:01 - 22:11 -> wa sample
// 23:16 -> tle
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
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //

const int MAXN=200010;
const int MAXE=800010;
const int MAXLog=21;

int g[MAXN], g_lnk[MAXE], g_nxt[MAXE], e;
int dep[MAXN], up[MAXN][MAXLog];
int n, m;

int go_up(int x, int d) {
	forn(i, MAXLog) if(d&(1<<i))
		x=up[x][i];
	return x;
}

int down_node(int x, int y) {
	return go_up(y, dep[y]-dep[x]-1);
}

struct SegmentTree {
	vector<int> tr, buf;
	int n;
	void init(int n) {
		this->n=n;
		tr.clear(); buf.clear();
		tr.resize(_ n*4+10, 0);
		buf.resize(_ n*4+10, 0);
	}
	void release(int x, int s, int t, int m) {
		if(buf[_ x]>0) {
			buf[_ x*2]=buf[_ x*2+1]=buf[_ x];
			tr[_ x*2]=tr[_ x*2+1]=buf[_ x];
			buf[_ x]=0;
		}
	}
	void set(int x, int s, int t, int l, int r, int c) {
		if(l<=s && t<=r) {
			tr[_ x]=buf[_ x]=c; return;
		}
		int m=(s+t)/2;
		release(x, s, t, m);
		if(l<=m) set(x*2, s, m, l, r, c);
		if(m+1<=r) set(x*2+1, m+1, t, l, r, c);
		tr[_ x]=max(tr[_ x*2], tr[_ x*2+1]);
	}
	void set(int l, int r, int c) {
	//printf("set [%d,%d]=%d\n",l,r,c);
		set(1, 1, n, l, r, c);
	}
	int get(int x, int s, int t, int l, int r) {
		if(l<=s && t<=r) return tr[_ x];
		int m=(s+t)/2, ans=0;
		release(x, s, t, m);
		if(l<=m) setmax(ans, get(x*2, s, m, l, r));
		if(m+1<=r) setmax(ans, get(x*2+1, m+1, t, l, r));
		return ans;
	}
	int get(int l, int r) {
	//printf("get [%d,%d]\n",l,r);
		return get(1, 1, n, l, r);
	}
};

struct CTree {
	int size[MAXN], pu[MAXN], pd[MAXN];
	int head[MAXN], ind[MAXN], tot;
	SegmentTree tr;

	void dfs(int x) {
	//static int cnt=0; printf("x=%d | %d\n",x,++cnt);
		size[x]=1; pd[x]=0;
		for(int i=g[x], y; i; i=g_nxt[i])
			if(up[y=g_lnk[i]][0]==x) {
				dfs(y);
				size[x]+=size[y];
				if(pd[x]==0 || size[y]>size[pd[x]])
					pd[x]=y;
			}
		if(pd[x]>0) pu[pd[x]]=x;
	}
	void init() {
		fillchar(pu, 0);
		//printf("dfs\n");
		dfs(1);
		//printf("dfs f\n");
		
		tot=0;
		forint(x, 1, n) if(pu[x]==0) {
			for(int y=x; y; y=pd[y]) {
			//printf("head[%d]=%d up=%d\n",y,x,up[y][0]);
				head[y]=x;
				ind[y]=++tot;
			}
		}
		tr.init(tot);
	}
	int get(int x, int y) {
	//printf("get %d %d\n", x,y);
		int ans=0;
		if(dep[x]>dep[y]) return ans;
		while(1) {
			int z=head[y];
			if(dep[z]>dep[x]) {
			//printf("z=%d y=%d\n",z,y);
			//printf("[%d,%d]\n",ind[z],ind[y]);
				setmax(ans, tr.get(ind[z], ind[y]));
				y=up[z][0];
			} else {
			//printf("x=%d y=%d\n",x,y);
			//printf("[%d,%d]\n",ind[x],ind[y]);
				setmax(ans, tr.get(ind[x], ind[y]));
			//printf("ok\n");fflush(stdout);
				break;
			}
		}
		return ans;
	}
	void paint(int x, int y, int c) {
	//printf("paint %d %d\n", x,y);
		if(dep[x]>dep[y]) return;
		while(1) {
			int z=head[y];
			if(dep[z]>dep[x]) {
				tr.set(ind[z], ind[y], c);
				y=up[z][0];
			} else {
				tr.set(ind[x], ind[y], c);
				break;
			}
		}
	}
} ctree;

void add_edge(int a, int b) {
	g_lnk[++e]=b, g_nxt[e]=g[a], g[a]=e;
	g_lnk[++e]=a, g_nxt[e]=g[b], g[b]=e;
}

bool visited[MAXN];
void visit(int x) {
	if(visited[x]) return;
	visited[x]=true;
	for(int i=g[x]; i; i=g_nxt[i])
		visit(g_lnk[i]);
}
void init() {
	//n=100, m=400;
	scanf("%d%d", &n,&m);
	e=1; fillchar(g, 0);
	forint(i, 1, m) {
		int a, b; scanf("%d%d", &a,&b);
		//int a=rand()%n+1, b=rand()%n+1;
		add_edge(a, b);
	}
	// add edges
	int la=0; fillchar(visited, false);
	forint(i, 1, n) if(!visited[i]) {
		visit(i);
		if(la>0) add_edge(la, i);
		la=i;
	}
}

int be_n, be_x[MAXE], be_y[MAXE];

void dfs(int x, int fa) {
	if(fa==0) dep[x]=1;
	else dep[x]=dep[fa]+1;
	up[x][0]=fa;
	for(int i=1; i<MAXLog && up[x][i-1]>0; ++i)
		up[x][i]=up[up[x][i-1]][i-1];
	for(int i=g[x], y; i; i=g_nxt[i]) {
		if(dep[y=g_lnk[i]]==0)
			dfs(y, x);
		else if(dep[y]<dep[x] && y!=fa) {
			++be_n;
			be_y[be_n]=x;
			be_x[be_n]=y;
		}
	}
}

void answer(int x1, int y1, int x2, int y2) {
	vector<int> a, b, c;
	if(dep[x2]<dep[x1]) swap(x1, x2), swap(y1, y2);

	for(int x=x2; x!=up[x1][0]; x=up[x][0]) a.PB(x);
	b.PB(x2);
	while(y1!=y2) {
		if(dep[y1]>dep[y2]) {
			a.PB(y1); y1=up[y1][0];
		} else {
			b.PB(y2); y2=up[y2][0];
		}
	}
	a.PB(y1); b.PB(y1);
	reverse(all(a));
	reverse(all(b));
	for(int x=y1; x!=up[x2][0]; x=up[x][0]) c.PB(x);

	printf("YES\n");
	#define pr(u) do { \
		printf("%d ", (int)u.size()); \
		forn(i, u.size()) printf("%d ", u[_ i]); \
		printf("\n"); \
	} while (0)
	pr(a); pr(b); pr(c);
}

void solve() {
	//printf("@0\n"); fflush(stdout);
	fillchar(dep, 0);
	be_n=0;
	dfs(1, 0);
	//printf("@1\n"); fflush(stdout);
	ctree.init();
	//printf("@2\n"); fflush(stdout);
	forint(i, 1, be_n) {
		int x=be_x[i], y=be_y[i];
	//printf("@3 x=%d y=%d\n",x,y); fflush(stdout);
		int x2=down_node(x, y);
	//printf("@3 x=%d y=%d ..\n",x2,y); fflush(stdout);
		int j=ctree.get(x2, y);
	//printf("@3 x=%d y=%d --1\n",x,y); fflush(stdout);
		if(j>0) { // found
			answer(x, y, be_x[j], be_y[j]);
			return;
		}
	//printf("@3 x=%d y=%d --2\n",x,y); fflush(stdout);
		ctree.paint(x2, y, i);
	//printf("@3 x=%d y=%d --3\n",x,y); fflush(stdout);
	}
	printf("NO\n");
}

int main() {
	//printf("^0\n"); fflush(stdout);
	init();
	//printf("^1\n"); fflush(stdout);
	solve();
	return 0;
}