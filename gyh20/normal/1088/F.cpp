#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int a[500002],fa[22][500002],n,m,head[500002],cnt,pos;
long long ans;
struct edge{int to,next;}e[1000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	fa[0][x]=y;
	re ll s=a[x]+a[y];
	for(re int i=1;fa[i-1][x]^pos;++i){
		fa[i][x]=fa[i-1][fa[i-1][x]];
		if(!fa[i][x])fa[i][x]=pos;
		s=min(s,a[x]+a[fa[i][x]]+1ll*i*min(a[x],a[fa[i][x]]));
	}if(x^pos)ans+=s;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x);
}
int main(){
	n=read(),a[0]=1145141919;
	for(re int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]<a[pos])pos=i;
	}
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(pos,pos),printf("%lld",ans);
}