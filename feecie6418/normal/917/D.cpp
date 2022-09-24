#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,f[105][105][105],size[105],C[105][105]={1},tmp[105][105],ans[105];
//f[i][j][k]:ijikprod()i 
//ans[i]:in-i 
vector<int> g[105];
int Power(int x,int y){
	if(y<0)return Power(Power(x,mod-2),-y);
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return r;
}
void upd(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
void dfs(int x,int fa){
	size[x]=1,f[x][1][1]=1;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
		for(int i=1;i<=size[x];i++){
			for(int j=1;j<=size[x];j++){
				for(int k=1;k<=size[y];k++){
					for(int l=1;l<=size[y];l++){
						upd(tmp[i+k][j],1ll*f[x][i][j]*f[y][k][l]%mod*l%mod);//
						upd(tmp[i+k-1][j+l],1ll*f[x][i][j]*f[y][k][l]%mod);//
					}
				}
			}
		}
		size[x]+=size[y];
		for(int i=1;i<=size[x];i++)for(int j=1;j<=size[x];j++)f[x][i][j]=tmp[i][j],tmp[i][j]=0;
	}
}
int main(){
	cin>>n;
	for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=0;i<n;i++)for(int j=1;j<=n;j++)upd(ans[i],1ll*f[1][n-i][j]*j%mod*Power(n,n-i-2)%mod);
	for(int i=n-1;i>=0;i--)for(int j=i+1;j<n;j++)ans[i]=(ans[i]-1ll*ans[j]*C[j][i]%mod+mod)%mod;
	for(int i=0;i<n;i++)cout<<ans[i]<<' ';
	return 0;
}