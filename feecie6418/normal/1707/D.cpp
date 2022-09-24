#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
using namespace std;
int n,mod,f[2005][2005],jc[2005]={1},ny[2005]={1},ans[2005];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
vector<int> g[2005];
int pre[2005][2005],suf[2005][2005],s[2005];
void dfs(int x,int fa){
	vector<int> sons;
	sons.push_back(0);
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
		sons.push_back(y);
	}
	for(int i=1;i<n;i++){
		pre[i][0]=1;
		for(int j=1;j<sons.size();j++){
			int y=sons[j];
			pre[i][j]=1ll*pre[i][j-1]*f[y][i]%mod;
		}
		suf[i][sons.size()]=1;
		for(int j=sons.size()-1;j>0;j--){
			int y=sons[j];
			suf[i][j]=1ll*suf[i][j+1]*f[y][i]%mod;
		}
	}
	for(int j=1;j<sons.size();j++)s[j]=0;
	for(int i=1;i<n;i++){
		f[x][i]=1;
		if(i==1)continue;
		for(int j=1;j<sons.size();j++){
			int y=sons[j];
			f[x][i]=1ll*f[x][i]*f[y][i]%mod;
		}
		for(int j=1;j<sons.size();j++){
			int y=sons[j];
			s[j]=(s[j]+1ll*pre[i-1][j-1]*suf[i-1][j+1])%mod;
			f[x][i]=(f[x][i]+1ll*(f[y][i]-f[y][i-1]+mod)*s[j])%mod;
		}
		f[x][i]=(f[x][i]+f[x][i-1])%mod;
	}
}
int main(){
	cin>>n>>mod;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n]=Power(jc[n],mod-2);
	for(int i=n-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	fill(ans+1,ans+n,1);
	for(int y:g[1]){
		dfs(y,1);
		for(int i=1;i<n;i++)ans[i]=1ll*ans[i]*f[y][i]%mod;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<i;j++)ans[i]=(ans[i]-1ll*ans[j]*C(i,j)%mod+mod)%mod;
		cout<<ans[i]<<' ';
	}
}