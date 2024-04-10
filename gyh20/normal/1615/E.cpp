#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],head[1000002],cnt,len[1000002],top[1000002],son[1000002],fa[1000002],p[1000002],tot,k;
long long ans;
struct edge{
	int to,next;
}e[1000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	len[x]=0,fa[x]=y;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x);
			if(len[e[i].to]>len[x])len[x]=len[e[i].to],son[x]=e[i].to;
		}
	++len[x];
}
int main(){
	n=read(),k=read();ans=-1e18;
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,1);
	for(re int i=1;i<=n;++i)if(i!=son[fa[i]])p[++tot]=len[i];
	sort(p+1,p+tot+1);
	if(k>tot){
		for(re int i=tot;i<=k;++i)ans=max(ans,1ll*i*(n-i));
		printf("%lld\n",ans);
	}
	else{
		re int s=n,sum=0;
		for(re int i=1;i<=tot-k;++i)s-=p[i],sum+=p[i];
		ans=1e18;
		for(re int i=0;i<=sum;++i)ans=min(ans,1ll*(k-i)*(n-k-i));
		printf("%lld\n",ans);
	}
}