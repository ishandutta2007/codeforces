#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>S[N];
int hea[N],to[N<<1],nxt[N<<1],dep[N],dfn[N],col[N];
int low[N],in[N],G[N],jp[N][20],d[N],sd[N],dfns,tot,cnt;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void tarjan(int x,int f) {
	dfn[x]=low[x]=++dfns;
	for(int i=hea[x];i;i=nxt[i]) {
		if(i==f)continue;
		int y=to[i];
		if(!dfn[y]) {
			tarjan(y,i^1);
			if(low[y]>dfn[x])G[i/2]=1;
			low[x]=min(low[x],low[y]);
		} else low[x]=min(low[x],dfn[y]);
	}
}
void dfs(int x) {
	in[x]=cnt;
	for(int i=hea[x];i;i=nxt[i]) {
		if(G[i/2])continue;
		int y=to[i];
		if(!in[y])dfs(y);
	}
}
void dfs(int x,int fa,int cc) {
	dep[x]=dep[fa]+1;
	jp[x][0]=fa;
	col[x]=cc;
	for(int i=1;i<20;i++)
		jp[x][i]=jp[jp[x][i-1]][i-1];
	for(int y:S[x])
		if(y!=fa)dfs(y,x,cc);
}
int lca(int a,int b) {
	if(dep[a]<dep[b])swap(a,b);
	for(int i=19;i>=0;i--)
		if(dep[jp[a][i]]>=dep[b])
			a=jp[a][i];
	if(a==b)return a;
	for(int i=19;i>=0;i--)
		if(jp[a][i]!=jp[b][i]) {
			a=jp[a][i];
			b=jp[b][i];
		}
	return jp[a][0];
}
int A[N],B[N];
void sum1(int x,int fa) {
	for(int y:S[x]) {
		if(y==fa)continue;
		sum1(y,x);
		d[x]+=d[y];
	}
}
void sum2(int x,int fa) {
	sd[x]=sd[fa]+d[x];
	for(int y:S[x])
		if(y!=fa)sum2(y,x);
}
int main() {
	tot=1;
	int n,m,q,a,b;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i,0);
	for(int i=1;i<=n;i++)
		if(!in[i])cnt++,dfs(i);
	for(int i=1;i<=n;i++)
		for(int j=hea[i];j;j=nxt[j])
			if(in[i]!=in[to[j]])
				S[in[to[j]]].push_back(in[i]);
	for(int i=1;i<=n;i++)
		if(!col[i])dfs(i,0,i);
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&a,&b);
		a=in[a],b=in[b];
		if(col[a]!=col[b]) {
			puts("No");
			return 0;
		}
		int p=lca(a,b);
		A[i]=b,B[i]=p;
		d[p]--,d[a]++;
	}
	for(int i=1;i<=n;i++)
		if(col[i]==i) {
			sum1(i,0);
			sum2(i,0);
		}
	for(int i=1;i<=q;i++)
		if(sd[A[i]]!=sd[B[i]]) {
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}