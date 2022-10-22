#include <bits/stdc++.h>
#define FR first
#define SE second
 
using namespace std;
 
typedef pair<int,int> pr;
 
vector <int> e[300005];
 
namespace Tree {
 
int fa[300005],dep[300005];
int size[300005],son[300005];
 
void dfs1(int x) {
  size[x]=1;
  for(int i=0;i<e[x].size();i++)
    if (e[x][i]!=fa[x]) {
    	int u=e[x][i];
    	fa[u]=x;dep[u]=dep[x]+1;
    	dfs1(u);
    	size[x]+=size[u];
    	if (size[u]>size[son[x]]) son[x]=u;
	}
}
 
int top[300005],dfn[300005],dfs_cnt;
 
void dfs2(int x,int anc) {
  top[x]=anc;dfn[x]=++dfs_cnt;
  if (son[x]) dfs2(son[x],anc);
  for(int i=0;i<e[x].size();i++)
    if (e[x][i]!=fa[x]&&e[x][i]!=son[x]) dfs2(e[x][i],e[x][i]);
}
 
void build(int rt) {
  dep[rt]=1;
  dfs1(rt);
  dfs2(rt,rt);
} 
 
int lca(int x,int y) {
  while (top[x]!=top[y]) {
  	if (dep[top[x]]<dep[top[y]]) swap(x,y);
  	x=fa[top[x]];
  }
  return (dep[x]<dep[y])?x:y;
}
 
}
 
vector <pr> ee[300005];
int num[1000005],e_cnt;
int q[300005],node_cnt;
 
inline void addEdge(int x,int y) {
  e_cnt++;
  ee[x].push_back(pr(y,e_cnt));
  ee[y].push_back(pr(x,e_cnt));
}
 
namespace VT {
 
bool cmp(int x,int y) {
  return Tree::dfn[x]<Tree::dfn[y];
}
 
int st[300005],top;
 
void build(int k,int rt) {
  sort(num+1,num+k+1,cmp);
  st[top=1]=rt;
  node_cnt=0;
  for(int i=1;i<=k;i++) {
  	int x=num[i];
  	if (x==st[top]) continue;
  	int p=Tree::lca(x,st[top]);
  	for(;;) {
  		if (Tree::dep[p]<=Tree::dep[st[top-1]]) {
  			if (st[top-1]!=rt) addEdge(st[top-1],st[top]);
			q[++node_cnt]=st[top];
			top--; 
		  }
		else if (Tree::dep[p]<Tree::dep[st[top]]) {
			if (p!=rt) addEdge(p,st[top]);
			q[++node_cnt]=st[top];
			st[top]=p;
			break;
		}
		else break;
	  }
	if (st[top]!=p) st[++top]=p;
	st[++top]=x;
  }
  for(;top;top--) {
  	if (top>1) addEdge(st[top-1],st[top]);
  	q[++node_cnt]=st[top];
  }
}
 
void clear() {
  for(;node_cnt;node_cnt--) vector<pr>().swap(ee[q[node_cnt]]);
}
 
}
 
namespace Graph {
 
int dfn[300005],low[300005],dfs_cnt;
int id[300005],bcc_cnt;
 
int vis[2000005],vis_cnt;
bool rt[300005];
 
void dfs1(int x,int fa) {
  dfn[x]=low[x]=++dfs_cnt;
  for(int i=0;i<ee[x].size();i++)
    if (ee[x][i].SE!=fa) {
    	int u=ee[x][i].FR;
    	if (!dfn[u]) {
    		dfs1(u,ee[x][i].SE);
    		low[x]=min(low[x],low[u]);
    		if (low[u]>dfn[x]) vis[ee[x][i].SE]=vis_cnt;
		}
		else low[x]=min(low[x],dfn[u]);
	}
}
 
void dfs2(int x) {
  id[x]=bcc_cnt;
  for(int i=0;i<ee[x].size();i++)
    if (!id[ee[x][i].FR]&&vis[ee[x][i].SE]<vis_cnt) dfs2(ee[x][i].FR);
}
 
void init(int n) {
  for(int i=1;i<=n;i++) {
  	int x=q[i];
    dfn[x]=low[x]=id[x]=rt[x]=0;
  }
  dfs_cnt=bcc_cnt=0;
}
 
void build(int n) {
  init(n);
  vis_cnt++;
  for(int i=1;i<=n;i++)
    if (!dfn[q[i]]) {
    	rt[q[i]]=1;
    	dfs1(q[i],0);
	}
  for(int i=1;i<=n;i++)
    if (!id[q[i]]) {
    	bcc_cnt++;
    	dfs2(q[i]);
	}
}
 
void build_tree(int n) {
  for(int i=1;i<=n;i++)
  	for(int j=0;j<ee[i].size();j++)
  	  if (id[i]!=id[ee[i][j].FR]) e[id[i]].push_back(id[ee[i][j].FR]);
}
 
}
 
int val[300005],bel[300005];
 
int main() {
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=m;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	ee[x].push_back(pr(y,i));
  	ee[y].push_back(pr(x,i));
  }
  node_cnt=n;
  for(int i=1;i<=n;i++) q[i]=i;
  Graph::build(n);
  Graph::build_tree(n);
  int rt=Graph::bcc_cnt+1;
  for(int i=1;i<=n;i++) {
    bel[i]=Graph::id[i];
    if (Graph::rt[i]) {
    	e[rt].push_back(bel[i]);
    	e[bel[i]].push_back(rt);
	}
  }
  for(int i=1;i<=n;i++) vector<pr>().swap(ee[i]);
  Tree::build(rt);
  int R=0;
  for(int i=1;i<=k;i++) {
  	int ni,mi;
  	scanf("%d%d",&ni,&mi);
  	int cnt=0;
  	for(int j=1;j<=ni;j++) {
  		int x;
  		scanf("%d",&x);
  		x=(x+R)%n;
  		if (!x) x=n;
  		x=bel[x];
  		val[j]=x;
  		num[++cnt]=x;
	  }
	e_cnt=0;
	for(int j=1;j<=mi;j++) {
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+R)%n;y=(y+R)%n;
		if (!x) x=n;
		if (!y) y=n;
		x=bel[x];y=bel[y];
		addEdge(x,y);
		num[++cnt]=x;num[++cnt]=y;
	}
	VT::build(cnt,rt);
	Graph::build(node_cnt);
	bool ok=1;
	for(int j=1;j<=ni;j++)
	  if (Graph::id[val[j]]!=Graph::id[val[1]]) ok=0;
	puts((ok)?"YES":"NO");
	if (ok) R=(R+i)%n;
	VT::clear();
  }
  return 0;
}