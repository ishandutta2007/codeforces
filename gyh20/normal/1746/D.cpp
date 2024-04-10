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
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp,p[1000002],b[1000002],V[1000002],f[1000002],g[1000002],S[1000002];
char s[1000002];
vector<int>G[200002];
inline bool cmp(re int x,re int y){return f[x]>f[y];}
inline void dfs(re int x){
	f[x]=V[x];
	for(auto z:G[x])dfs(z),f[x]=max(f[x],V[x]+f[z]);
}
inline void dfs1(re int x,re int y){
	if(y==0)return;
	if(!G[x].size()){
		ans+=y*V[x];
		return; 
	}
	ans+=y*V[x];
	for(auto z:G[x])dfs1(z,y/G[x].size());
	y%=G[x].size();
	sort(G[x].begin(),G[x].end(),cmp);
	for(re int j=0;j<y;++j)ans+=f[G[x][j]];
	f[x]=f[G[x][y]]+V[x];
}
signed main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans=0;
		for(re int i=1;i<=n;++i)G[i].clear();
		for(re int i=2;i<=n;++i)G[read()].push_back(i);
		for(re int i=1;i<=n;++i)V[i]=read();
		dfs(1),dfs1(1,m);
		printf("%lld\n",ans);
	}
}