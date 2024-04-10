#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#define MAXN 1000010
using namespace std;

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN<<1];

int n,m;
int *s[MAXN];
int l[MAXN];
int g[MAXN],nume;
int p[MAXN][2],nump;
int dfn[MAXN],low[MAXN],cur;
int c[MAXN],numc;
bool instack[MAXN];
vector<int> e2[MAXN];
int d[MAXN];
int order[MAXN];
bool ans[MAXN];
stack<int> S;

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

void dfs(int x){
	dfn[x]=low[x]=++cur;
	S.push(x);
	instack[x]=1;
	for(int i=g[x];~i;i=e[i].next)
		if(!dfn[e[i].to]){
			dfs(e[i].to);
			if(low[e[i].to]<low[x]) low[x]=low[e[i].to];
		}else if(instack[e[i].to]){
			if(dfn[e[i].to]<low[x]) low[x]=dfn[e[i].to];
		}
	if(dfn[x]==low[x]){
		++numc;
		while(S.top()!=x){
			c[S.top()]=numc;
			instack[S.top()]=0;
			S.pop();
		}
		c[S.top()]=numc;
		instack[S.top()]=0;
		S.pop();
	}
}

bool gao(int x){
	int minl=min(l[x],l[x+1]);
	for(int i=1;i<=minl;i++)
		if(s[x][i]!=s[x+1][i]){
			if(s[x][i]<s[x+1][i]){
				addEdge(p[s[x][i]][0],p[s[x+1][i]][0]);
				addEdge(p[s[x+1][i]][1],p[s[x][i]][1]);
			}else{
				addEdge(p[s[x][i]][0],p[s[x][i]][1]);
				addEdge(p[s[x+1][i]][1],p[s[x+1][i]][0]);
			}
			return 1;
		}
	if(l[x]>l[x+1]) return 0;
	return 1;
}

void calc(){
	for(int i=1;i<=nump;i++)
		for(int j=g[i];~j;j=e[j].next)
			if(c[i]!=c[e[j].to]){
				d[c[e[j].to]]++;
				e2[c[i]].push_back(c[e[j].to]);
			}
	static queue<int> Q;
	for(int i=1;i<=numc;i++)
		if(!d[i])
			Q.push(i);
	int now_order=0;
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		order[x]=++now_order;
		for(int i=0;i<e2[x].size();i++)
			if(!(--d[e2[x][i]]))
				Q.push(e2[x][i]);
	}
	for(int i=1;i<=m;i++)
		if(order[c[p[i][0]]]<order[c[p[i][1]]])
			ans[i]=1;
	int cnt=0;
	for(int i=1;i<=m;i++) if(ans[i]) cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=m;i++) if(ans[i]) printf("%d ",i);
}

int main(){
#ifdef DEBUG
	freopen("C.in","r",stdin);
#endif
	memset(g,-1,sizeof g);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",l+i);
		s[i]=new int[l[i]+5];
		for(int j=1;j<=l[i];j++)
			scanf("%d",&s[i][j]);
	}
	for(int i=1;i<=m;i++){
		p[i][0]=++nump;
		p[i][1]=++nump;
	}
	for(int i=1;i<n;i++) 
		if(!gao(i)){
			puts("No");
			return 0;
		}
	for(int i=1;i<=nump;i++)
		if(!dfn[i])
			dfs(i);
	for(int i=1;i<=m;i++)
		if(c[p[i][0]]==c[p[i][1]]){
			puts("No");
			return 0;
		}
	puts("Yes");
	calc();
	return 0;
}