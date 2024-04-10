#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,f[300005][3];
vector<int> g[300005];
int Power(int x,int y) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
void dfs(int x,int fa){
	f[x][0]=f[x][2]=1;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x),f[x][0]=1ll*f[x][0]*(f[y][0]+f[y][1])%mod;
		f[x][1]=(f[x][1]+1ll*Power((f[y][0]+2ll*f[y][1])%mod,mod-2)*f[y][2])%mod;
		f[x][2]=f[x][2]*(f[y][0]+2ll*f[y][1])%mod;
	}
	f[x][1]=1ll*f[x][1]*f[x][2]%mod;
}
int main(){
	cin>>n;
	for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dfs(1,0),cout<<(f[1][0]+f[1][1])%mod;
    return 0;
}