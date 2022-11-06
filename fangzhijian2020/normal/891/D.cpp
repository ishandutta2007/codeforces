#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
inline int read()
{
	int res=0,bj=0;char ch=gc();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return bj?-res:res;
}
int n,x,y,h[500005],cnt=1;long long ans;
struct edge{int to,next;}e[1000005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int size[500005],fa[500005];
void dfs(int x,int prt){
	int i,y;size[x]=1;fa[x]=prt;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x);size[x]+=size[y];
	}
}
struct node{
	int t[2][2];
	void init(){
		memset(t,0,sizeof(t));t[0][0]=1;
	}
	node operator*(const node&a)const{
		node b;
		b.t[0][0]=t[0][0]&a.t[1][0];
		b.t[1][0]=(t[1][0]&a.t[1][0])|(t[0][0]&a.t[0][0]);
		b.t[0][1]=(a.t[1][0]?t[0][1]:0)+(t[0][0]?a.t[1][1]:0);
		b.t[1][1]=(a.t[1][0]?t[1][1]:0)+(t[1][0]?a.t[1][1]:0)+(a.t[0][0]?t[0][1]:0)+(t[0][0]?a.t[0][1]:0);
		return b;
	}
	node operator^(const node&a)const{
		node b;
		b.t[0][0]=t[0][0]&a.t[0][0];
		b.t[1][0]=(t[1][0]&a.t[0][0])|(t[0][0]&a.t[1][0]);
		b.t[0][1]=(a.t[0][0]?t[0][1]:0)+(t[0][0]?a.t[0][1]:0);
		b.t[1][1]=(a.t[0][0]?t[1][1]:0)+(t[1][0]?a.t[0][1]:0)+(a.t[1][0]?t[0][1]:0)+(t[0][0]?a.t[1][1]:0);
		return b;
	}
}f[1000005],L[500005],R[500005];
void Dfs(int x,int prt){
	int i,y;f[prt].init();
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if((i^1)==prt)continue;
		Dfs(y,i);f[prt]=f[prt]*f[i];
	}
	f[prt].t[1][1]+=f[prt].t[0][0];
}
int p[1000005];
void DFS(int x,int prt){
	int i,y,tot=0;
	for(i=h[x];i;i=e[i].next)p[++tot]=i;
	R[tot+1].init();
	for(int i=tot;i;--i)R[i]=R[i+1]*f[p[i]];
	L[0].init();
	for(int i=1;i<=tot;++i){
		f[p[i]^1]=L[i-1]^R[i+1];
		L[i]=L[i-1]*f[p[i]];
	}
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;f[i^1].t[1][1]+=f[i^1].t[0][0];
		if((i^1)==prt)continue;DFS(y,i);
	}
}
int main(){
//	freopen("ex_data3.in","r",stdin);
//	freopen("match.out","w",stdout);
	n=read();
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	if(n&1){puts("0");return 0;}
	dfs(1,0);Dfs(1,0);DFS(1,0);
	for(int i=2;i<=cnt;i+=2){
		x=size[e[i].to]>size[e[i^1].to]?e[i^1].to:e[i].to;
		if(!(size[x]&1)){
			if(f[i].t[1][0]&&f[i^1].t[1][0]){
				ans+=1ll*size[x]*(n-size[x]);
			}
		}
		else{
			ans+=1ll*(f[i].t[1][1])*(f[i^1].t[1][1]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}