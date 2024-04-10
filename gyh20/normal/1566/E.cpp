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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,head[200002],d[200002],f[200002],siz[200002];
vector<int>G[200002];
inline void dfs(re int x,re int y){
	f[x]=siz[x]=0,siz[x]=f[x]=1;
	re int sum=0,ia=0;
	for(auto &z:G[x])
		if(z^y){
			dfs(z,x);
			if((siz[x]-f[x])%2==0||(siz[z]-f[z])%2==1)f[x]=f[x]+f[z]-1;
			else f[x]+=f[z];
			siz[x]+=siz[z];
		}
}
int main(){
	int t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)d[i]=0,G[i].clear(); 
		for(re int i=1,x,y;i<n;++i){
			x=read(),y=read(),G[x].push_back(y),G[y].push_back(x);
			++d[x],++d[y];
		}
		dfs(1,1);
		printf("%d\n",f[1]);
	}
}