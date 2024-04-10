#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
vector<int> G[500005];
int n,f[500005][2],g[500005][2];
void dfs(int x,int fa){
	g[x][0]=1;
	for(int y:G[x]){
		if(y==fa)continue;
		//if(x==1)cout<<"Y:"<<y<<'\n';
		dfs(y,x);
		int f0=f[x][0],f1=f[x][1],g0=g[x][0],g1=g[x][1];
		f[x][1]=(1ll*f0*g[y][0]+1ll*g0*f[y][0]+2ll*g0*g[y][0]+1ll*g[y][0]*f1+1ll*f[y][0]*g1+1ll*g[y][1]*f1+1ll*f[y][1]*g1)%mod;
		f[x][1]=(f[x][1]+1ll*g[y][0]*f1+1ll*f[y][0]*g1+1ll*g[y][1]*f1+1ll*f[y][1]*g1)%mod;
		f[x][0]=(1ll*f0*g[y][1]+1ll*g0*f[y][1]+1ll*f0*g[y][1]+1ll*g0*f[y][1]+1ll*f0*g[y][0]+1ll*g0*f[y][0])%mod;
		
		g[x][1]=(2ll*g1*(g[y][0]+g[y][1])+1ll*g0*g[y][0])%mod;
		g[x][0]=1ll*g0*(0ll+g[y][0]+g[y][1]+g[y][1])%mod;
		//if(x==1)cout<<f[x][0]<<' '<<f[x][1]<<' '<<g[x][0]<<' '<<g[x][1]<<' '<<(g[y][0]+g[y][1])<<'\n';
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
	dfs(1,0),cout<<(f[1][0]+f[1][1])%mod;
}
/*
5
1 2
1 3
1 4
4 5
*/