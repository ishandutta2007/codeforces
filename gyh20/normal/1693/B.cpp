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
int t,n,m,a[1000002],ans,A,B,fa[1000002],L[1000002],R[1000002],f[1000002];
char s[1000002];
vector<int>G[1000002];
inline void dfs(re int x){f[x]=0;
	for(auto z:G[x]){
		dfs(z),f[x]+=f[z];
	}
	f[x]=min(f[x],R[x]);
	if(f[x]<L[x])f[x]=R[x],++ans;
}
signed main(){
	t=read();
	while(t--){
		n=read();ans=0;
		for(re int i=1;i<=n;++i)G[i].clear();
		for(re int i=2;i<=n;++i)fa[i]=read(),G[fa[i]].push_back(i); 
		for(re int i=1;i<=n;++i)L[i]=read(),R[i]=read();
		dfs(1);printf("%lld\n",ans);
	}
}