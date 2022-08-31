#include<bits/stdc++.h>
#define re register
#define int long long
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
int t,n,m,ans,a[1000002],b[1000002],S[1000002],A[1002],B[1002],deg[1002],Q[1002],hd,tl,lst[1002],tg[1002];
vector<int>G[1002];
signed main(){
	t=read();
	while(t--){
		n=read(),m=read(),hd=1,tl=0,ans=0;
		for(re int i=1;i<=n;++i)a[i]=read(),deg[i]=0,G[i].clear(),lst[i]=-1;
		for(re int i=1;i<=m;++i)A[i]=read(),B[i]=read(),G[A[i]].push_back(B[i]),++deg[B[i]];
		for(re int i=1;i<=n;++i){
			re bool ia=1;
			for(re int j=1;j<=n;++j)if(a[j]){ia=0;break;}
			if(ia)break;
			++ans;
			for(re int j=1;j<=n;++j)tg[j]=a[j]>0;
			for(re int j=1;j<=m;++j)if(tg[A[j]])++a[B[j]];
			for(re int j=1;j<=n;++j)if(tg[j])--a[j];
		}
		re bool ia=1;
		for(re int j=1;j<=n;++j)if(a[j]){ia=0;break;}
		if(ia){
			printf("%lld\n",ans);
			continue;
		}
		for(re int i=1;i<=n;++i)a[i]%=M;
		for(re int i=1;i<=n;++i)if(!deg[i])Q[++tl]=i;
		while(hd<=tl){
			re int x=Q[hd++];
			for(auto z:G[x])add(a[z],a[x]);
			for(auto z:G[x])if(!(--deg[z]))Q[++tl]=z;
		}
		/*
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<=n;++j)tg[j]=0;
			for(re int j=1;j<=m;++j)if(a[A[j]]>0)tg[B[j]]=1;
			re int mn=2e9;
			for(re int j=1;j<=n;++j)if(!tg[j]&&a[j])mn=min(mn,a[j]);
			if(mn>1.1e9)break;
			ans+=mn;
			for(re int j=1;j<=n;++j)tg[j]=a[j]>0;
			for(re int j=1;j<=m;++j)if(tg[A[j]])a[B[j]]+=mn;
			for(re int j=1;j<=n;++j)if(tg[j])a[j]-=mn;
		}*/
		printf("%lld\n",(ans+a[Q[tl]])%M);
	}
}