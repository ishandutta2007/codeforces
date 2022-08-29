#include<cstdio>
#define re register
using namespace std;
const int Mxdt=300000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,head[300002],f[300002],cnt,ans,fa[300002],num;
char v[300002];
struct edge{
	int to,next;
}e[600002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	fa[x]=y;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x);
			f[x]^=f[e[i].to]+1;
		}
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,1),ans=f[1];
	putchar(ans?'1':'2');
	for(re int i=2;i<=n;++i){
		re int x=i;
		while(!v[x])v[x]=1,ans^=f[x]+1,ans^=f[x],x=fa[x],++num;
		putchar(ans^(num&1)?'1':'2');
	}
}