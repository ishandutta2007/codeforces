#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))

const LL INFI=1LL<<60;

template<size_t N, size_t E> struct MaxFlow {
	struct Edge {
		int y;  LL w;
		Edge *next, *oppo;
	} edges[E*2];
	int e_cnt;
	Edge *g[N], *ce[N];
	int n, src, dst;	
	int d[N], q[N];
	bool build() {
		memset(d, 0, sizeof(d)); d[q[1]=src]=1;
		for(int ss=0, tt=1; ss<tt; ) {
			int x=q[++ss];
			for(Edge *e=ce[x]=g[x]; e!=NULL; e=e->next)
				if(e->w>0 && d[e->y]==0) d[q[++tt]=e->y]=d[x]+1;
		}
		return d[dst]>0;
	}
	LL find(int x, LL rest) {
		if(x==dst) return rest;
		LL ans=0;
		for(Edge *&e=ce[x]; e!=NULL; e=e->next)
			if(e->w>0 && d[e->y]>d[x]) {
				LL cur=find(e->y, min(e->w,rest));
				e->w-=cur; e->oppo->w+=cur;
				ans+=cur; rest-=cur;
				if(rest==0) break;
			}
		return ans;
	}
	void initialize(int n, int s, int t) {
		this->n=n;
		this->src=s;
		this->dst=t;
		memset(g, 0, sizeof(g)); e_cnt=0;
	}
	void add_edge(int x, int y, LL w1, LL w2) {
		Edge *e1=&edges[e_cnt++], *e2=&edges[e_cnt++];
		e1->y=y, e1->w=w1, e1->oppo=e2, e1->next=g[x], g[x]=e1;
		e2->y=x, e2->w=w2, e2->oppo=e1, e2->next=g[y], g[y]=e2;
	}
	LL compute() {
		LL ans=0; while(build()) ans+=find(src, INFI); return ans;
	}
};

const int MAXN=55;
const int MAXM=110;
const int MAXV=210;
const int MAXNodes=MAXN*MAXV;
const int MAXEdges=MAXN*MAXV+MAXM*MAXV;

int a[MAXN], b[MAXN], c[MAXN], l[MAXN], r[MAXN];
int u[MAXM], v[MAXM], d[MAXM];
int n, m;

int vn[MAXN], vx[MAXN][MAXV], vi[MAXN][MAXV];
int vs, vt;
MaxFlow<MAXNodes,MAXEdges> net;

LL eva(int i, LL x) {
	return a[i]*x*x+b[i]*x+c[i];
}

int main() {
	scanf("%d%d", &n,&m);
	forint(i, 1, n) scanf("%d%d%d", a+i,b+i,c+i);
	forint(i, 1, n) scanf("%d%d", l+i,r+i);
	forint(i, 1, m) scanf("%d%d%d", u+i,v+i,d+i);

	int ncnt=0;
	vs=++ncnt;
	vt=++ncnt;
	forint(i, 1, n) {
		vi[i][0]=++ncnt;
		vn[i]=0;
		forint(x, l[i], r[i]) {
			++vn[i];
			vx[i][vn[i]]=x;
			vi[i][vn[i]]=++ncnt;
		}
	}
	
	net.initialize(ncnt, vs, vt);
	LL BIG=1001000, ans_t=0;
	forint(i, 1, n) {
		ans_t+=BIG;
		net.add_edge(vs, vi[i][0], INFI, 0);
		net.add_edge(vi[i][vn[i]], vt, INFI, 0);
		forint(j, 1, vn[i])
			net.add_edge(vi[i][j-1], vi[i][j], BIG-eva(i,vx[i][j]), 0);
	}
	forint(k, 1, m) {
		int i1=u[k], i2=v[k], d0=d[k];
		forint(j1, 1, vn[i1]) {
			forintdown(j2, vn[i2], 1)
				if(vx[i1][j1]>vx[i2][j2]+d0) {
					net.add_edge(vi[i1][j1-1], vi[i2][j2], INFI, 0);
					break;
				}
		}
	}

	LL ans=ans_t-net.compute();
	cout<<ans<<endl;

	return 0;
}