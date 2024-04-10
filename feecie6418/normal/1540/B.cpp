#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
vector<int> g[205];
int n,A,B,f[205],d[205],dfn[205],size[205],sign,ans=0,h[205][205];
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return r;
}
void dfs(int x,int fa){
	f[x]=fa,d[x]=d[fa]+1;
	dfn[x]=++sign,size[x]=1;
	for(int y:g[x])if(y^fa)dfs(y,x),size[x]+=size[y];
}
int LCA(int x,int y){
	while(x^y){
		if(d[x]<d[y])swap(x,y);
		x=f[x];
	}
	return x;
}
int main(){
	cin>>n;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	}
	h[1][1]=(mod+1)/2;
	for(int i=2;i<=n;i++)h[1][i]=1ll*h[1][i-1]*(mod+1)/2%mod;
	for(int i=2;i<=n;i++)h[i][1]=(1+mod-h[1][i])%mod;
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)h[i][j]=1ll*(h[i-1][j]+h[i][j-1])*(mod+1)/2%mod;
	for(int rt=1;rt<=n;rt++){
		sign=0,dfs(rt,0);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){//ji 
				if(dfn[i]<=dfn[j]&&dfn[j]<dfn[i]+size[i])continue;
				if(dfn[j]<=dfn[i]&&dfn[i]<dfn[j]+size[j]){
					ans++;
					continue;
				}
				int u=LCA(i,j),uu=ans;
				ans=(ans+h[d[i]-d[u]][d[j]-d[u]])%mod;
				//cout<<i<<' '<<j<<' '<<(ans-uu+mod)%mod<<'\n';
			}
		}
	}
	cout<<1ll*ans*Power(n,mod-2)%mod;
}