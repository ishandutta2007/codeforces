#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,S[205][205],f[100005][205],ans=0,sum[205],size[100005],t[205];
vector<int> g[100005];
void upd(int &x,long long y){
	x=(x+y)%mod;
}
void dp(int x,int fa){
	f[x][0]=1,size[x]=1;
	for(int y:g[x]){
		if(y==fa)continue;
		dp(y,x);
		for(int i=0;i<size[x]&&i<=m;i++){
			for(int j=0;j<size[y]&&i+j<=m;j++){
				upd(t[i+j],1ll*f[x][i]*f[y][j]),upd(t[i+j+1],1ll*f[x][i]*f[y][j]);
				upd(sum[i+j],1ll*f[x][i]*f[y][j]),upd(sum[i+j+1],1ll*f[x][i]*f[y][j]);
			}
		}
		for(int i=0;i<size[y]&&i<=m;i++)upd(t[i],f[y][i]),upd(t[i+1],f[y][i]);
		size[x]+=size[y];
		for(int i=0;i<size[x]&&i<=m;i++)f[x][i]=(f[x][i]+t[i])%mod,t[i]=0;
	}
}
int main(){
	cin>>n>>m,S[0][0]=1;
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mod;
	for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dp(1,0);
	for(int i=0,jc=1;i<=m;i++,jc=1ll*jc*i%mod)ans=(ans+1ll*jc*sum[i]%mod*S[m][i])%mod;
	cout<<ans;
}