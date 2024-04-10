#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
int n,f[100002][2],m,t,g[100002][4];
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x,re int y){return (x+=y)>=M?x-=M:x;}
vector<int>v[100002];
inline void dfs(re int x){
	sort(v[x].begin(),v[x].end());
	f[x][1]=1,f[x][0]=0;
	for(re int i=0,z;i<(int)v[x].size();++i){
		dfs(z=v[x][i]);
		re int tmp0=f[x][0],tmp1=f[x][1];
		add(f[x][0],1ll*tmp0*f[z][0]%M);
		add(f[x][0],1ll*tmp1*f[z][1]%M);
		add(f[x][1],1ll*tmp0*f[z][1]%M);
		add(f[x][1],1ll*tmp1*f[z][0]%M);
	}
	re int aaa=1;
	reverse(v[x].begin(),v[x].end());
	add(f[x][0],f[x][0]),add(f[x][1],f[x][1]);
	g[x][0]=1,g[x][1]=0;
	for(re int i=0,z;i<(int)v[x].size();++i){
		z=v[x][i];
		re int tmp=g[x][1];
		add(g[x][1],1ll*g[x][0]*f[z][1]%M);
		add(g[x][0],1ll*tmp*f[z][1]%M);
		aaa=1ll*aaa*(f[z][0]+1)%M;
	}
	add(f[x][0],M-g[x][1]);
	add(f[x][1],M-aaa);
}
int main(){
//	freopen("randomdfs.in","r",stdin);
//	freopen("randomdfs.out","w",stdout);
	t=1;
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)v[i].clear();
		for(re int i=2;i<=n;++i)v[read()].push_back(i);
		dfs(1);
		printf("%d\n",(f[1][0]+f[1][1])%M);
	}
}