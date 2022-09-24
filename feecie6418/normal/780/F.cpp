#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
const ll inf=1e18;
bitset<505> f[505][70][2];
int n,m,can[505],tc[505];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(z==0)f[x][0][0][y]=1;
		else f[x][0][1][y]=1;
	}
	for(int i=1;i<=60;i++){
		for(int j=1;j<=n;j++)
			for(int l=1;l<=n;l++)
				for(int w=0;w<2;w++)
					if(f[j][i-1][w][l])f[j][i][w]|=f[l][i-1][w^1];
	}
	ll ans=0;
	fill(can+1,can+n+1,1);
	for(int i=60,w=0;i>=0;i--){
		bool ok=0;
		for(int j=1;j<=n;j++){
			if(!can[j])continue;
			for(int k=1;k<=n;k++){
				if(f[j][i][w][k])tc[k]=1,ok=1;
			}
		}
		if(ok){
			w^=1,ans+=(1ll<<i);
			for(int j=1;j<=n;j++)can[j]=tc[j],tc[j]=0;
		}
	}
	if(ans>inf)cout<<-1;
	else cout<<ans;
}