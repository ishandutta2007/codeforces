#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
long long ans;
int t,n,m,a[1000002],A,pos[1000002],nn[1000002],vis[300002],b[300002],c[300002];
char s[1000002];
vector<int>G[300002],B[300002];
inline bool cmp(re int x,re int y){return a[x]<a[y];}
int main(){
	t=read();
	while(t--){
		n=read(),m=read();ans=0;
		for(re int i=1;i<=n;++i)a[i]=b[i]=read(),G[i].clear(),B[i].clear(),vis[i]=0,nn[i]=0;
		sort(b+1,b+n+1);
		for(re int i=1;i<=n;++i)c[i]=lower_bound(b+1,b+n+1,a[i])-b;
		re int num=0;
		for(re int i=1,x,y;i<=m;++i)x=read(),x=lower_bound(b+1,b+n+1,x)-b,y=read(),y=lower_bound(b+1,b+n+1,y)-b,B[x].push_back(y),B[y].push_back(x);
		for(re int i=1;i<=n;++i)++nn[c[i]];
		for(re int i=1;i<=n;++i)if(nn[i])G[nn[i]].push_back(i);
		for(re int i=1;i<=n;++i){
			if(G[i].size())pos[++num]=i;
			sort(G[i].begin(),G[i].end()),reverse(G[i].begin(),G[i].end());
		}
		for(re int i=1;i<=n;++i){
			if(!nn[i])continue;
			for(re int j=0;j<B[i].size();++j)vis[B[i][j]]=i;
			for(re int j=1;j<=num;++j)
				for(re int k=0;k<G[pos[j]].size();++k){
					re int x=G[pos[j]][k];
					if(vis[x]==i||x==i)continue;
					ans=max(ans,1ll*(b[i]+b[x])*(nn[x]+nn[i]));
					break;
				}
		}
		printf("%lld\n",ans);
	}
}