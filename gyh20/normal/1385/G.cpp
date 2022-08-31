#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[800002],b[800002],ans,pos1[800002],pos2[800002],num[800002],vis[800002],tim,tot,q[800002],tp,cnt,head[800002];
struct edge{
	int to,next;
}e[3200002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;
	e[++cnt]=(edge){x,head[y]};
	head[y]=cnt;
}
inline int inv(re int x){
	return x>n?x-n:x+n;
}
inline void dfs(re int x){//printf("%d\n",x);
	if(x>n)++tot;vis[x]=tim;q[++tp]=x;
	for(re int i=head[x];i;i=e[i].next)if((!vis[e[i].to])&&(!vis[inv(e[i].to)]))dfs(e[i].to);
}
int main(){
	t=read();
	while(t--){
		n=read();ans=0;cnt=0;
		for(re int i=1;i<=n*2;++i)pos1[i]=pos2[i]=num[i]=vis[i]=head[i]=0;
		for(re int i=1;i<=n;++i){
		a[i]=read();++num[a[i]];if(pos1[a[i]])pos2[a[i]]=i;else pos1[a[i]]=i;}
		for(re int i=1;i<=n;++i){
		a[i]=read();++num[a[i]];if(pos1[a[i]])pos2[a[i]]=i;else pos1[a[i]]=i;}
		bool ia=0;
		for(re int i=1;i<=n;++i)if(num[i]!=2)ia=1;
		if(ia){
			puts("-1");continue;
		}
		for(re int i=1;i<=n;++i){
			if(pos1[i]==pos2[i])continue;
			if((a[pos1[i]]==i)==(a[pos2[i]]==i))add(pos1[i],pos2[i]+n),add(pos2[i],pos1[i]+n);
			else add(pos1[i],pos2[i]),add(pos1[i]+n,pos2[i]+n);
		}
		for(re int i=1;i<=n;++i){
			if(!vis[i]&&!vis[inv(i)]){
			tim=i;tot=0;tp=0;
			dfs(i);
			if(tot>tp-tot){
				for(re int j=1;j<=tp;++j)swap(vis[q[j]],vis[inv(q[j])]);
				ans+=tp-tot;
			}
			else ans+=tot;
			}
		}
		printf("%d\n",ans);
		for(re int i=1;i<=n;++i)if(!vis[i])printf("%d ",i);puts("");
	}
}