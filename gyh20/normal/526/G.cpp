#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
struct edge{int to,next,w;}e[200002];
int n,head[100002],cnt,la,L[100002],q;
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
struct node{int x,y;bool operator <(const node a)const{return x>a.x;};}p[100002];
struct Tree{
	int dep[100002],fa[22][100002],dis[100002],son[100002],rt,mxd[100002],m,s[100002],c[100002];
	inline void dfs(re int x,re int y){
		fa[0][x]=y,dep[x]=dep[y]+1,mxd[x]=son[x]=0;
		for(re int i=head[x];i;i=e[i].next)
			if(e[i].to^y){
				dis[e[i].to]=dis[x]+e[i].w,dfs(e[i].to,x);
				if(mxd[e[i].to]+e[i].w>mxd[x])mxd[x]=mxd[e[i].to]+e[i].w,son[x]=e[i].to;
			}
	}
	inline int pre(re int x){
		dfs(x,0);
		for(re int i=1;i<=n;++i)if(dis[i]>dis[rt])rt=i;
		dis[rt]=0,dfs(rt,0);
		for(re int i=1;i<=n;++i)
			if(!son[i]){
				re int x=i;
				while(son[fa[0][x]]==x)x=fa[0][x];
				p[++m]=(node){dis[i]-dis[fa[0][x]],i};
			}
		sort(p+1,p+m+1);
		for(re int i=1;i<=m;++i){
			s[i]=s[i-1]+p[i].x;
			re int x=p[i].y;
			while(son[fa[0][x]]==x)c[x]=i,x=fa[0][x];c[x]=i;
		}
		for(re int i=1;i<=L[n];++i)for(re int j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
		return rt;
	}
	inline int ask1(re int x,re int y){
		re int ss=mxd[x]+dis[x]+s[y-1];
		for(re int i=L[dep[x]];~i;--i)if(c[fa[i][x]]>y-1)x=fa[i][x];
		return ss-dis[fa[0][x]]; 
	}
	inline int ask2(re int x,re int y){
		re int ss=s[y]+mxd[x]+dis[x];
		for(re int i=L[dep[x]];~i;--i)if(c[fa[i][x]]>y)x=fa[i][x];
		return ss-mxd[fa[0][x]]-dis[fa[0][x]];
	}
	inline int ask(re int x,re int y){if(c[x]<=y)return s[min(y,m)];return max(ask1(x,y),ask2(x,y));}
}T1,T2;
int main(){
	n=read(),q=read();
	for(re int i=0;i<=n;++i)L[i]=L[i>>1]+1;
	for(re int i=1,x,y,z;i<n;++i)x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
	T2.pre(T1.pre(1));
	while(q--){
		re int x=(read()+la-1)%n+1,y=(read()+la-1)%n+1;y<<=1,--y;
		printnum(la=max(T1.ask(x,y),T2.ask(x,y)),'\n');
	}
	pc('o',1); 
}