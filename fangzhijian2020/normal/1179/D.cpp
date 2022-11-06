#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long INF=1e18;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,x,y,h[500005],cnt,size[500005];
struct edge{int to,next;}e[1000005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
void DFS(int x,int prt){
	int i,y;size[x]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		DFS(y,x);size[x]+=size[y];
	}
}
int core;long long Max;
long long mul(int x){return 1ll*x*(x-1);}
void dfs(int x,int prt,long long now){
	int i,y;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x,now+mul(size[x]-size[y]));
	}
	now+=mul(size[x]);
	if(now<=Max){core=x;Max=now;}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	core=0;Max=INF;DFS(1,0);dfs(1,0,0);
	Max=INF;DFS(core,0);dfs(core,0,0);
	cout<<mul(n)-Max/2<<"\n";
	return 0;
}