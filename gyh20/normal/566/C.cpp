#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,pos,head[200002],cnt,rt,siz[200002],mn,a[200002];
double f[200002],s1,s2,ans;
bool v[200002];
struct edge{int to,next,w;}e[400002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
inline void find(re int x,re int y,re int z){
	siz[x]=1;
	re int mx=0;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y&&!v[e[i].to])find(e[i].to,x,z),siz[x]+=siz[e[i].to],mx=max(mx,siz[e[i].to]);
	mx=max(mx,z-siz[x]);
	if(mx<mn)mn=mx,pos=x;
}
inline void dfs(re int x,re int y,re int z,re int d){
	s1+=sqrt(d)*d*a[x],f[z]+=sqrt(d)*a[x];
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x,z,d+e[i].w);
}
inline void dfs(re int x,re int y){
	mn=1e9,find(x,x,y),x=pos,s1=s2=0,find(x,x,y);
	for(re int i=head[x];i;i=e[i].next)f[e[i].to]=0,dfs(e[i].to,x,e[i].to,e[i].w),f[e[i].to]*=1.5,s2+=f[e[i].to];
	v[x]=1;
	if(s1<ans)ans=s1,rt=x;
	for(re int i=head[x];i;i=e[i].next)if(!v[e[i].to])if(s2<2*f[e[i].to])return dfs(e[i].to,siz[e[i].to]);
}
int main(){
	n=read(),ans=1e100;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1,x,y,z;i<n;++i)x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
	dfs(1,n);
	printf("%d %.10lf",rt,ans);
}