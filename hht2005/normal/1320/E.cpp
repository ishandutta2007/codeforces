#include<bits/stdc++.h>
using namespace std;
const int N=400010,mod=1e9+7;
vector<int>S[N],T[N];
int dfn[N],jp[N][20],dep[N],dfns;
int h[N],sk[N],s[N],pos[N],Max[N],id[N];
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
int dis(int a,int b) {
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}
void build(int n) {
	sort(h+1,h+n+1,cmp);
	int top;
	T[sk[top=1]=1].clear();
	h[0]=1;
	for(int i=1;i<=n;i++) {
		if(h[i]==h[i-1])continue;
		int p=lca(h[i],sk[top]),las=0;
		while(dep[sk[top]]>dep[p]) {
			if(las)T[sk[top]].push_back(las);
			las=sk[top--];
		}
		if(p!=sk[top])T[sk[++top]=p].clear();
		if(las)T[p].push_back(las);
		T[sk[++top]=h[i]].clear();
	}
	while(--top)T[sk[top]].push_back(sk[top+1]);
}
int cmp(int a,int b,int x) {
	int A=dis(a,x),B=dis(b,x);
	A=A/s[a]+(A%s[a]!=0);
	B=B/s[b]+(B%s[b]!=0);
	return A<B||(A==B&&id[a]<id[b]);
}
void DP1(int x) {
	Max[x]=0;
	for(int y:T[x]) {
		DP1(y);
		if(!Max[y])continue;
		if(!Max[x]||cmp(Max[y],Max[x],x))
			Max[x]=Max[y];
	}
	if(s[x])Max[x]=x;
}
void DP2(int x,int fa) {
	if(fa&&Max[fa]&&(!Max[x]||cmp(Max[fa],Max[x],x)))
		Max[x]=Max[fa];
	for(int y:T[x])
		DP2(y,x);
}
int main() {
	int n,q,a,b;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	dfs(1,0);
	scanf("%d",&q);
	int k,m;
	while(q--) {
		scanf("%d%d",&k,&m);
		for(int i=1;i<=k;i++) {
			scanf("%d",pos+i);
			scanf("%d",&a);
			id[pos[i]]=i;
			s[pos[i]]=a;
			h[i]=pos[i];
		}
		for(int i=k+1;i<=m+k;i++) {
			scanf("%d",pos+i);
			h[i]=pos[i];
		}
		build(k+m);
		DP1(1);
		DP2(1,0);
		for(int i=1;i<=k;i++)
			s[pos[i]]=0;
		for(int i=k+1;i<=m+k;i++)
			printf("%d ",id[Max[pos[i]]]);
		puts("");
	}
	return 0;
}