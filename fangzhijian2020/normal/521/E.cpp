#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,x[200005],y[200005],fa[200005],q[200005],tot;
int getfzj(int x){
	if(x==fa[x])return x;
	return fa[x]=getfzj(fa[x]);
}
int h[200005],cnt,dep[200005],vis[200005],in[200005],X[200005],Y[200005],tmp[200005];
struct edge{int to,next;}e[400005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int LCA(int x,int y){
	while(x!=y){
		if(dep[x]<dep[y])swap(x,y);
		x=fa[x];
	}
	return x;
}
void Cal(int x,int y){
	while(x!=y){
		tmp[++tot]=x;x=fa[x];
	}
	tmp[++tot]=x;
}
void Out(int a,int b,int c,int d){
	if(dep[d]>dep[b])swap(a,c),swap(b,d);
	puts("YES");int lca=LCA(a,c);
	tot=0;Cal(lca,b);reverse(tmp+1,tmp+tot+1);
	cout<<tot<<" ";for(int i=1;i<=tot;++i)cout<<tmp[i]<<" ";puts("");
	tot=0;Cal(b,b);Cal(a,lca);
	cout<<tot<<" ";for(int i=1;i<=tot;++i)cout<<tmp[i]<<" ";puts("");
	tot=0;Cal(b,d);Cal(c,lca);
	cout<<tot<<" ";for(int i=1;i<=tot;++i)cout<<tmp[i]<<" ";puts("");
	exit(0);
}
void dfs(int x){
	int i,y;vis[x]=in[x]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==fa[x])continue;
		if(!vis[y]){
			fa[y]=x;dep[y]=dep[x]+1;dfs(y);
		}
		else if(in[y]){
			int now=x;
			while(now!=y){
				if(X[now]&&Y[now]){
					Out(X[now],Y[now],x,y);
				}
				else{
					X[now]=x;Y[now]=y;
				}
				now=fa[now];
			}
		}
	}
	in[x]=0;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		x[i]=read();y[i]=read();
		add(x[i],y[i]);add(y[i],x[i]);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])dfs(i);
	}
	puts("NO");
	return 0;
}