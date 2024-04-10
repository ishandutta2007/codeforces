#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long INF=1e18+10;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,x,y,z,vis[605],h[605],cnt;long long dis[605];
struct edge{int to,next,v;}e[605*605];
void add(int x,int y,int z){
	e[++cnt]=(edge){y,h[x],z};h[x]=cnt;
}
void dijkstra(int s){
	int i,y;for(int i=0;i<n;++i)dis[i]=INF,vis[i]=0;
	for(int i=h[s];i;i=e[i].next){
		dis[e[i].to]=e[i].v;
	}
	for(int t=1;t<=n;++t){
		int id=-1;
		for(int i=0;i<n;++i){
			if(!vis[i]){
				if(id==-1)id=i;
				else if(dis[i]<dis[id])id=i;
			}
		}
		vis[id]=1;
		dis[(id+1)%n]=min(dis[(id+1)%n],dis[id]+1);
		for(int i=h[id];i;i=e[i].next){
			y=(e[i].to+dis[id])%n;
			dis[y]=min(dis[y],dis[id]+e[i].v);
		}
	}
	dis[s]=0;
	for(int i=0;i<n;++i)cout<<dis[i]<<" ";
	puts("");
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		x=read();y=read();z=read();
		add(x,y,z);
	}
	for(int i=0;i<n;++i)dijkstra(i);
	return 0;
}