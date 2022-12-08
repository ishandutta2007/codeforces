#include<bits/stdc++.h>
using namespace std;
const int N=400010;
vector<int>S[N],T[N];
int dfn[N],jp[N][20],dep[N],dfns;
int h[N],sk[N],f[N];
long long dp[N][2];
int cmp(int a,int b) {
	return dfn[a]<dfn[b];
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
			if(las)T[sk[top]].push_back(las);
			las=sk[top--];
		}
		if(p!=sk[top])T[sk[++top]=p].clear();
		if(las)T[p].push_back(las);
		T[sk[++top]=h[i]].clear();
	}
	while(--top)T[sk[top]].push_back(sk[top+1]);
}
void dfs(int x) {
	dp[x][0]=0;
	dp[x][1]=1e9;
	long long sum=0;
	for(int y:T[x]) {
		dfs(y);
		dp[x][0]+=dp[y][0];
		sum+=min(dp[y][0],dp[y][1]);
	}
	for(int y:T[x])
		dp[x][1]=min(dp[x][1],dp[x][0]-dp[y][0]+dp[y][1]);
	if(!f[x])dp[x][0]=min(dp[x][0],sum+1);
	else dp[x][1]=dp[x][0],dp[x][0]=1e9;
}
int main() {
	int n,q,k,x,y;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		scanf("%d%d",&x,&y);
		S[x].push_back(y);
		S[y].push_back(x);
	}
	dfs(1,0);
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&k);
		int cnt=k;
		for(int i=1;i<=k;i++) {
			scanf("%d",h+i);
			f[h[i]]=1;
			if(jp[h[i]][0])
				h[++cnt]=jp[h[i]][0];
		}
		build(cnt);
		dfs(1);
		for(int i=1;i<=cnt;i++)
			f[h[i]]=0;
		if(min(dp[1][0],dp[1][1])<=n)printf("%lld\n",min(dp[1][0],dp[1][1]));
		else puts("-1");
	}
	return 0;
}