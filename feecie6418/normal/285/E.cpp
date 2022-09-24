#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int n,m,jc[1005]={1},ny[1005]={1},f[1005][1005],g[1005][1005][2][2],s[1005];
void upd(int &x,int y){
	x=(x+y)%mod;
}
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
void Make(int cnt){
	for(int i=0;i<=cnt;i++)memset(g[i],0,sizeof(g[i]));
	g[0][0][0][0]=1;
	//,,i+1,i
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<2;k++){//i+1
				for(int l=0;l<2;l++){//i
					//i
					if(k==0){
						upd(g[i][j][k][l],g[i-1][j][l][0]);
						upd(g[i][j][k][l],g[i-1][j][l][1]);
					}
					//ii-1 
					if(j&&i>1&&!k){
						upd(g[i][j][k][l],g[i-1][j-1][l][0]);
					}
					//ii+1 
					if(j&&k){
						upd(g[i][j][k][l],g[i-1][j-1][l][0]);
						upd(g[i][j][k][l],g[i-1][j-1][l][1]);
					}
				}
			}
		}
	}
	for(int i=0;i<=cnt;i++)s[i]=(g[cnt][i][0][0]+g[cnt][i][0][1])%mod;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod,ny[i]=Power(jc[i],mod-2);
	Make(n);
	for(int i=0;i<=n;i++)s[i]=1ll*s[i]*jc[n-i]%mod;
	int ans=0;
	for(int i=m;i<=n;i++){
		if((i-m)&1)ans=(ans-1ll*C(i,m)*s[i]%mod+mod)%mod;
		else ans=(ans+1ll*C(i,m)*s[i])%mod;
	}
	cout<<ans;
}