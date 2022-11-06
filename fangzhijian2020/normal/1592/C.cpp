#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,k,x,y,h[100005],cnt,a[100005],vis[100005],fa[100005],size[100005],opt,tp[100005];
struct edge{int to,next;}e[200005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
void dfs(int x,int prt){
	int i,y;size[x]=a[x];
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		fa[y]=x;dfs(y,x);size[x]^=size[y];
	}
}
void DFS(int x,int prt){
	int i,y;tp[x]=0;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		DFS(y,x);tp[x]+=tp[y];
	}
	if(tp[x]&1){
		tp[x]+=(size[x]==0);
	}
	else{
		tp[x]+=(size[x]==size[1]);
	}
}
int main(){
	T=read()+1;
	while(--T){
		n=read();k=read();
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<n;++i){
			x=read();y=read();
			add(x,y);add(y,x);
		}
		dfs(1,0);opt=0;
		if(size[1]==0)puts("YES");
		else{
			if(k==2)puts("NO");
			else{
				DFS(1,0);
				if(tp[1]>2)puts("YES");
				else puts("NO");	
			}
		}
		for(int i=1;i<=n;++i)h[i]=0;cnt=0;
	}
	return 0;
}