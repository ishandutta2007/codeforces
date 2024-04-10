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
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp,d[1000002],siz[1000002];
char s[1000002];
vector<int>G[1000002];
inline void dfs(re int x){
	siz[x]=1;
	for(auto z:G[x])dfs(z),siz[x]+=siz[z];
}
inline void dfs1(re int x){
	if(x)printf("%d ",x);
	for(auto z:G[x])if(siz[z]==1)dfs1(z);
	for(auto z:G[x])if(siz[z]^1)dfs1(z);
}
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),d[i]=0,G[i].clear();G[0].clear();
		re int pos=0;
		for(re int i=1;i<=n;++i)if(a[i]>i)pos=i;
		for(re int i=1;i<=n;++i)if(a[i]==n+1)a[i]=0;
		for(re int i=1;i<=n;++i)G[a[i]].push_back(i);
		printf("%d\n",pos);
		dfs(0),dfs1(0);puts("");
	}
}