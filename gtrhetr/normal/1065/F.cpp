#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
  int t,next;
  Edge() {}
  Edge(int a,int b):t(a),next(b) {}
};

namespace Graph {

Edge e[2000005],e2[2000005];
int head[1000005],head2[1000005],tot,tot2;
int d[1000005];

void addEdge(int x,int y) {
  e[++tot]=Edge(y,head[x]);
  head[x]=tot;
}

void addEdge2(int x,int y) {
  e2[++tot2]=Edge(y,head2[x]);
  head2[x]=tot2;
  d[y]++;
}

int size[1000005];
bool leaf[1000005];

int dfn[1000005],low[1000005],cnt;
int id[1000005],scc_cnt;
int st[1000005],top;
bool in[1000005];

void dfs(int x) {
  dfn[x]=low[x]=++cnt;
  in[x]=1;st[++top]=x;
  for(int i=head[x];i;i=e[i].next) {
    	int u=e[i].t;
    	if (!dfn[u]) {
    		dfs(u);
    		low[x]=min(low[x],low[u]);
		}
		else if (in[u]) low[x]=min(low[x],dfn[u]);
	}
  if (low[x]>=dfn[x]) {
  	scc_cnt++;
  	int t;
  	do {
  		t=st[top--];
  		in[t]=0;
  		id[t]=scc_cnt;
  		size[scc_cnt]+=leaf[t];
	  } while (t!=x);
  }
}

queue <int> q;
int num[1000005];

void topo() {
  int tot=0;
  for(int i=1;i<=scc_cnt;i++)
    if (!d[i]) q.push(i);
  while (!q.empty()) {
  	int x=q.front();q.pop();
  	num[++tot]=x;
  	for(int i=head2[x];i;i=e2[i].next) {
  		int u=e2[i].t;
  		d[u]--;
  		if (!d[u]) q.push(u);
	  }
  }
}

int f[1000005];

int dp() {
  for(int i=scc_cnt;i>0;i--) {
  	int x=num[i];
  	for(int j=head2[x];j;j=e2[j].next) f[x]=max(f[x],f[e2[j].t]);
  	f[x]+=size[x];
  }
  return f[id[1]];
}

int solve(int n) {
  for(int i=1;i<=n;i++)
    if (!dfn[i]) dfs(i);
  for(int i=1;i<=n;i++)
    for(int j=head[i];j;j=e[j].next) 
	  if (id[i]!=id[e[j].t]) addEdge2(id[i],id[e[j].t]);
  topo();
  return dp();
}

}

namespace Tree {

Edge e[1000005];
int head[1000005],tot;

void addEdge(int x,int y) {
  e[++tot]=Edge(y,head[x]);
  head[x]=tot;
}

int st[1000005],top;

void dfs(int x,int k) {
  st[++top]=x;
  bool ok=0;
  for(int i=head[x];i;i=e[i].next) {
  	int u=e[i].t;
  	ok=1;
  	dfs(u,k);
  	Graph::addEdge(x,u);
  }
  if (!ok) {
  	Graph::leaf[x]=1;
  	Graph::addEdge(x,st[max(top-k,1)]);
  }
  top--;
}

}

int main() {
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=2;i<=n;i++) {
  	int x;
  	scanf("%d",&x);
  	Tree::addEdge(x,i);
  }
  Tree::dfs(1,k);
  printf("%d\n",Graph::solve(n));
  return 0;
}