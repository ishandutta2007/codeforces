#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],fa[maxn],dep[maxn],mx[maxn],s[maxn],a[maxn],b[maxn],c[maxn],tot=1;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x) {
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa[x]) {
			fa[to[i]]=x;
			s[to[i]]=i>>1;
			dep[to[i]]=dep[x]+1;
			dfs(to[i]);
		}
}
void Max(int x,int y,int w) {
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y]) {
		mx[s[x]]=max(mx[s[x]],w);
		x=fa[x];
	}
	while(x!=y) {
		mx[s[x]]=max(mx[s[x]],w);
		x=fa[x];
		mx[s[y]]=max(mx[s[y]],w);
		y=fa[y];
	}
}
int qry(int x,int y) {
	int ans=1e9;
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y]) {
		ans=min(mx[s[x]],ans);
		x=fa[x];
	}
	while(x!=y) {
		ans=min(mx[s[x]],ans);
		x=fa[x];
		ans=min(mx[s[y]],ans);
		y=fa[y];
	}
	return ans;
}
int main() {
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		mx[i]=1;
		scanf("%d%d",a+i,b+i);
		add(a[i],b[i]);
		add(b[i],a[i]);
	}
	dfs(1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",a+i,b+i,c+i);
		Max(a[i],b[i],c[i]);
	}
	for(int i=1;i<=m;i++)
		if(qry(a[i],b[i])!=c[i])
			return puts("-1");
	for(int i=1;i<n-1;i++)printf("%d ",mx[i]);
	printf("%d\n",mx[n-1]);
	return 0;
}