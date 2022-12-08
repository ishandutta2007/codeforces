#include<bits/stdc++.h>
using namespace std;
const int N=100010,mod=1e9+7;
#define add(a,b) T[a].push_back(b),T[b].push_back(a);
vector<int>S[N],T[N];
int dfn[N],jp[N][20],dep[N],dfns;
int h[N],sk[N],f[N],Dfn[N],dp[N][310],Dfns;
int cmp(int a,int b) {
	return dfn[a]<dfn[b];
}
int Cmp(int a,int b) {
	return Dfn[a]<Dfn[b];
}
void dfs(int x,int fa) {
	dfn[x]=++dfns;
	dep[x]=dep[fa]+1;
	jp[x][0]=fa;
	for(int i=1;i<20;i++)
		jp[x][i]=jp[jp[x][i-1]][i-1];
	for(int y:S[x])
		if(y!=fa)dfs(y,x);
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
void build(int n) {
	sort(h+1,h+n+1,cmp);
	int top;
	T[sk[top=1]=1].clear();
	h[0]=1;
	for(int i=1;i<=n;i++) {
		if(h[i]==h[i-1])continue;
		int p=lca(h[i],sk[top]),las=0;
		while(dep[p]<dep[sk[top]]) {
			if(las)add(sk[top],las);
			las=sk[top--];
		}
		if(p!=sk[top])T[sk[++top]=p].clear();
		if(las)add(p,las);
		T[sk[++top]=h[i]].clear();
	}
	while(--top)add(sk[top],sk[top+1]);
}
void Dfs(int x,int fa) {
	Dfn[x]=++Dfns;
	for(int y:T[x]) {
		if(y==fa)continue;
		f[y]+=f[x];
		Dfs(y,x);
	}
}
void clear(int x,int fa) {
	f[x]=0;
	for(int y:T[x]) {
		if(y==fa)continue;
		clear(y,x);
	}
}
int main() {
	int n,q,k,m,r,x,y;
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++) {
		scanf("%d%d",&x,&y);
		S[x].push_back(y);
		S[y].push_back(x);
	}
	dfs(1,0);
	while(q--) {
		scanf("%d%d%d",&k,&m,&r);
		for(int i=1;i<=k;i++) {
			scanf("%d",h+i);
			f[h[i]]=1;
		}
		h[k+1]=r;
		build(k+1);
		Dfns=0;
		Dfs(r,0);
		sort(h+1,h+k+2,Cmp);
		dp[1][0]=1;
		for(int i=2;i<=k+1;i++)
			for(int j=1;j<=m;j++)
				dp[i][j]=(dp[i-1][j-1]+1ll*dp[i-1][j]*max(j-f[h[i]]+1,0))%mod;
		int ans=0;
		for(int i=1;i<=m;i++)
			ans=(ans+dp[k+1][i])%mod;
		printf("%d\n",ans);
		clear(r,0);
	}
	return 0;
}