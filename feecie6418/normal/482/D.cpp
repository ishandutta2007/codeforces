#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
vector<int> gr[100005];
int f[100005][2],g[100005][2][2],n;
//g[i][0/1][0/1]: ii//
void dfs(int x){
	for(int y:gr[x])dfs(y);
	g[x][0][0]=g[x][0][1]=f[x][1]=1;
	for(int y:gr[x]){
		int t1=(1ll*f[x][0]*f[y][1]+1ll*f[y][0]*f[x][1])%mod;
		int t0=(1ll*f[x][0]*f[y][0]+1ll*f[y][1]*f[x][1])%mod;
		f[x][0]=(f[x][0]+t0)%mod,f[x][1]=(f[x][1]+t1)%mod;
		int t00=1ll*g[x][0][0]*f[y][0]%mod;
		int t01=1ll*g[x][1][1]*f[y][1]%mod;
		int t11=1ll*g[x][0][1]*f[y][1]%mod;
		g[x][0][0]=(g[x][0][0]+t00)%mod;
		g[x][0][1]=(g[x][0][1]+t01)%mod;
		g[x][1][1]=(g[x][1][1]+t11)%mod;
	}
	f[x][0]=(2ll*f[x][0]-g[x][1][1]+mod)%mod;
	f[x][1]=(2ll*f[x][1]-g[x][0][0]+mod)%mod;
}
int main(){
	scanf("%d",&n);
	for(int i=2,x;i<=n;i++)scanf("%d",&x),gr[x].push_back(i);
	dfs(1),printf("%d\n",(f[1][0]+f[1][1])%mod);
    return 0;
}