#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,s,cnt=0,head[N],siz[N],son[N],f[N],top[N],dep[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs1(int u,int fa,int deep){
	siz[u]=1;
	f[u]=fa;
	dep[u]=deep;
	int maxson=-1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson){
			maxson=siz[v];
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int Dis(int x,int y){
	int lca=LCA(x,y);
	return dep[x]+dep[y]-2*dep[lca];
}
int main(){
	n=read();
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),a=read(),b=read(),k=read();
		int len=Dis(a,b);
		if(len<=k&&(len&1)==(k&1)){
			printf("YES\n");
			continue;
		}
		int l=Dis(x,a),r=Dis(y,b);
		if(l+r+1<=k&&(k&1)==((l+r+1)&1)){
			printf("YES\n");
			continue;
		}
		l=Dis(x,b),r=Dis(y,a);
		if(l+r+1<=k&&(k&1)==((l+r+1)&1)){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}