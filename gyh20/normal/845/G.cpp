#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
int n,m,cnt,head[100005];
long long p[63];
inline void insert(re long long x){
	for(re int i=62;i>=0;--i){
		if(x&(1ll<<i))
		if(!p[i]){
			p[i]=x;
			return;
		}
		else x^=p[i];
	}
}
struct edge{
	int to,next;
	long long w;
}e[200002];
const int Mxdt=100000;
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read() {
	int res=0;
	char ch=gc();
	while(ch<'0')ch=gc();
	while(ch>='0')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return res;
}
inline void add(re int x,re int y,re long long z){

	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;e[cnt].w=z;	
}
long long dis[100005];
bool vis[100005];
inline void dfs(re int x,re long long xr){
	dis[x]=xr,vis[x]=1;
	for(re int i=head[x];i;i=e[i].next){
		if(!vis[e[i].to])dfs(e[i].to,xr^e[i].w);
		else insert(dis[e[i].to]^xr^e[i].w);
	}
}
inline long long ask(re long long ans){
	for(re int i=62;i>=0;--i){
		if((ans^p[i])<ans)ans^=p[i];
	}
	return ans;
}
int x,y,z;
signed main(){
	n=read();
	m=read();
	for(re int i=1;i<=m;++i){
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
//	printf("%lld\n",dis[n]);
	printf("%lld",ask(dis[n]));
}