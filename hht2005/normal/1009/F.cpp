#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>S[N];
int siz[N],son[N],d[N],dep[N],ans[N],K,Max;
void pre(int x,int fa) {
	dep[x]=dep[fa]+1;
	siz[x]=1;
	for(int y:S[x]) {
		if(y==fa)continue;
		pre(y,x);
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y])
			son[x]=y;
	}
}
void clear(int x,int fa) {
	d[dep[x]]=0;
	for(int y:S[x])
		if(y!=fa)clear(y,x);
}
void calc(int x,int fa) {
	d[dep[x]]++;
	if(d[dep[x]]>Max||(d[dep[x]]==Max&&K>dep[x]))
		Max=d[K=dep[x]];
	for(int y:S[x])
		if(y!=fa)calc(y,x);
}
void dfs(int x,int fa) {
	for(int y:S[x]) {
		if(y==fa||y==son[x])
			continue;
		dfs(y,x);
		Max=K=0;
		clear(y,x);
	}
	if(son[x])dfs(son[x],x);
	d[dep[x]]++;
	if(d[dep[x]]>Max||(d[dep[x]]==Max&&K>dep[x]))
		Max=d[K=dep[x]];
	for(int y:S[x]) {
		if(y==fa||y==son[x])
			continue;
		calc(y,x);
	}
	ans[x]=K;
}
int main() {
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	pre(1,0);
	dfs(1,0);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]-dep[i]);
	return 0;
}