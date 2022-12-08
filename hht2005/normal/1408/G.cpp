#include<bits/stdc++.h>
using namespace std;
const int N=1510,M=N*N+N,mod=998244353;
struct node {
	int a,b,w;
	node(int A=0,int B=0,int W=0) {
		a=A,b=B,w=W;
	}
	int operator<(const node &a)const {
		return w<a.w;
	}
}s[M];
vector<int>S[M],pos[M];
int siz[M],sum[M],fa[M],L[M],R[M],f[N][N],c[M],dfns;
int get(int x) {
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void dfs(int x) {
	L[x]=1e9,R[x]=0;
	if(S[x].empty())L[x]=R[x]=++dfns;
	for(int y:S[x]) {
		dfs(y);
		L[x]=min(L[x],L[y]);
		R[x]=max(R[x],R[y]);
	}
	if(c[x])pos[R[x]].push_back(L[x]);
}
void add(int x) {
	if(siz[x]*(siz[x]-1)/2==++sum[x])c[x]=1;
}
int main() {
	int n,m=0,w;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			scanf("%d",&w);
			if(i<j)s[++m]=node(i,j,w);
		}
	sort(s+1,s+m+1);
	for(int i=1;i<=n+m;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=n;i++)c[i]=1;
	for(int i=1;i<=m;i++) {
		int p=get(s[i].a),q=get(s[i].b);
		if(p==q) {
			add(p);
			continue;
		}
		fa[p]=fa[q]=++n;
		siz[n]=siz[p]+siz[q];
		sum[n]=sum[p]+sum[q];
		add(n);
		S[n].push_back(p);
		S[n].push_back(q);
	}
	dfs(n);
	f[0][0]=1;
	n=dfns;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int y:pos[i])
				f[i][j]=(f[i][j]+f[y-1][j-1])%mod;
	for(int i=1;i<=n;i++)
		printf("%d ",f[n][i]);
	puts("");
	return 0;
}