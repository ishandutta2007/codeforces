#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int add(ll& x,ll y){
	x+=y;
	if(x>=mod) x-=mod;
}
#define fi first
#define se second
int n,t;
ll dp[226][17][17][17];
ll w[17][17][17][4];
ll f[16];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> t;
	f[0]=1;
	for(int i=1; i<=n ;i++) f[i]=f[i-1]*i%mod;
	dp[0][0][0][0]=1;
	for(int i=1; i<=n ;i++){
		int ti,g;cin >> ti >> g;
		for(int j=t; j>=ti ;j--)
			for(int a=0; a<=15 ;a++)
				for(int b=0; b<=15 ;b++)
					for(int c=0; c<=15 ;c++)
						if(g==1) add(dp[j][a+1][b][c],dp[j-ti][a][b][c]);
						else if(g==2) add(dp[j][a][b+1][c],dp[j-ti][a][b][c]);
						else add(dp[j][a][b][c+1],dp[j-ti][a][b][c]);
	}
	w[0][0][0][3]=1;
	ll ans=0;
	for(int i=0; i<=15 ;i++){
		for(int j=0; j<=15 ;j++){
			for(int k=0; k<=15 ;k++){
				for(int l=0; l<3 ;l++){
					for(int m=0; m<4 ;m++){
						if(l==m) continue;
						if(l==0 && i!=0) add(w[i][j][k][l],w[i-1][j][k][m]);
						if(l==1 && j!=0) add(w[i][j][k][l],w[i][j-1][k][m]);
						if(l==2 && k!=0) add(w[i][j][k][l],w[i][j][k-1][m]);
					}
				}
				//if(i==1 && j==1 && k==1) cout << w[i][j][k][1] << endl;
				ll cur=dp[t][i][j][k]*(w[i][j][k][0]+w[i][j][k][1]+w[i][j][k][2]+w[i][j][k][3])%mod;
				cur=cur*f[i]%mod*f[j]%mod*f[k]%mod;
				ans=(ans+cur)%mod;
			}
		}
	}
	cout << ans << '\n';
}