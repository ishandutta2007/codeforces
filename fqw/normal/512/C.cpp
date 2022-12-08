// 15:28 - 
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
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

const int INFI=1<<30;

template<size_t N, size_t E, class T> class Dinic {
	struct Edge {
		int y;  T w;
		Edge *next, *oppo;
	} edges[E*2];
	Edge *g[N], *ce[N];
	int e_cnt, n, src, dst;

	int d[N], q[N];
	bool build() {
		memset(d, 0, sizeof(d)); d[q[1]=src]=1;
		for(int ss=0, tt=1; ss<tt; ) {
			int x=q[++ss];
			for(Edge *e=ce[x]=g[x]; e; e=e->next)
				if(e->w>0 && d[e->y]==0) d[q[++tt]=e->y]=d[x]+1;
		}
		return d[dst]>0;
	}
	T find(int x, T rest) {
		if(x==dst) return rest;
		T ans=0;
		for(Edge *&e=ce[x]; e; e=e->next)
			if(e->w>0 && d[e->y]>d[x]) {
				T cur=find(e->y, min(e->w,rest));
				e->w-=cur; e->oppo->w+=cur;
				ans+=cur; rest-=cur;
				if(rest==0) break;
			}
		return ans;
	}
public:
	Dinic() { init(); }
	int s() { return src; }
	int t() { return dst; }
	void init() {
		memset(g, 0, sizeof(g)); e_cnt=0;
		n=2, src=1, dst=2;
	}
	int newNode() { return ++n; }
	void addEdge(int x, int y, T w1, T w2) {
		Edge *e1=&edges[e_cnt++], *e2=&edges[e_cnt++];
		e1->y=y, e1->w=w1, e1->oppo=e2, e1->next=g[x], g[x]=e1;
		e2->y=x, e2->w=w2, e2->oppo=e1, e2->next=g[y], g[y]=e2;
	}
	T compute() {
		T ans=0; while(build()) ans+=find(src, INFI); return ans;
	}
	T getFlow(int x, int y) {
		for(Edge *e=g[x]; e; e=e->next)
			if(e->y==y)
				return e->oppo->w;
		return 0;
	}
};

// ------------------------ template ends here ------------------------ //
const int MAXN=222;
const int MAXE=MAXN+MAXN*MAXN;

Dinic<MAXN, MAXE, int> dinic;
int n, a[MAXN], ai[MAXN];

bool isPrime(int x) {
	for(int y=2; y*y<=x; ++y)
		if(x%y==0)
			return false;
	return true;
}

int main() {
	cin>>n; forint(i, 1, n) cin>>a[i];
	dinic.init();
	forint(i, 1, n) ai[i]=dinic.newNode();
	forint(i, 1, n) if(a[i]%2==0) dinic.addEdge(dinic.s(), ai[i], 2, 0);
	forint(i, 1, n) if(a[i]%2==1) dinic.addEdge(ai[i], dinic.t(), 2, 0);
	forint(i, 1, n) if(a[i]%2==0)
		forint(j, 1, n) if(a[j]%2==1)
			if(isPrime(a[i]+a[j]))
				dinic.addEdge(ai[i], ai[j], 1, 0);
	int flow=dinic.compute();
	if(flow!=n) cout<<"Impossible"<<endl;
	else {
		vector<VI> ans;
		static bool vis[MAXN];
		fillchar(vis, false);
		forint(cur, 1, n) if(!vis[cur]) {
			int i=cur, la=0;
			VI lst;
			do {
				vis[i]=true;
				lst.PB(i);
				forint(j, 1, n) if(j!=la) {
					int x=i, y=j; if(a[y]%2==0) swap(x, y);
					if(dinic.getFlow(ai[x], ai[y])>0) {
						la=i; i=j;
						break;
					}
				}
			} while(i!=cur);
			ans.PB(lst);
		}
		cout<<ans.size()<<endl;
		forn(i, ans.size()) {
			cout<<ans[i].size();
			forn(j, ans[i].size()) cout<<" "<<ans[i][j];
			cout<<endl;
		}
		
	}

	return 0;
}