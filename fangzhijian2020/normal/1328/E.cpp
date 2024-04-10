#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,k,p[200005],x,y,h[200005],cnt,in[200005],out[200005],Time;
struct edge{int to,next;}e[400005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
bool cmp(const int&a,const int&b){
	return in[a]<in[b];
}
int f[200005][20],d[200005],t[200005],tot;
void dfs(int x,int prt){
	int i,y;f[x][0]=prt;in[x]=++Time;d[x]=d[prt]+1;
	for(int i=1;i<20;++i)f[x][i]=f[f[x][i-1]][i-1];
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x);
	}
	out[x]=Time;
}
int LCA(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=19;~i;--i){
		if(d[x]-(1<<i)>=d[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=19;~i;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];y=f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x,int y){return d[x]-d[y];}
int main(){
	n=read();m=read();
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=m;++i){
		k=read();
		for(int j=1;j<=k;++j)p[j]=read();
		int opt=1;
		for(int j=1;j<=k;++j)p[j]=p[j]==1?1:f[p[j]][0];
		sort(p+1,p+k+1,cmp);
		for(int j=1;j<k;++j){
			if(in[p[j]]<=in[p[j+1]]&&out[p[j]]>=out[p[j+1]]);
			else opt=0;
		}
		puts(opt?"YES":"NO");tot=0;
	}
	for(int i=1;i<=n;++i)h[i]=0;cnt=0;Time=0;
	return 0;
}