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
ll dp[2501][51][51];
ll dp2[2501][51];
ll w[51][51][51][4];
ll f[51];
int fr[51];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> t;
	f[0]=1;
	for(int i=1; i<=n ;i++) f[i]=f[i-1]*i%mod;
	dp[0][0][0]=1;
	dp2[0][0]=1;
	for(int i=1; i<=n ;i++){
		int ti,g;cin >> ti >> g;
		
		if(g<=2){
		for(int j=t; j>=ti ;j--)
			for(int a=0; a<=fr[1] ;a++)
				for(int b=0; b<=fr[2] ;b++)
		//			for(int c=0; c<=n ;c++)
						if(g==1) add(dp[j][a+1][b],dp[j-ti][a][b]);
						else if(g==2) add(dp[j][a][b+1],dp[j-ti][a][b]);
		}
		else{
		for(int j=t; j>=ti ;j--)
		//	for(int a=0; a<=15 ;a++)
		//		for(int b=0; b<=15 ;b++)
					for(int c=0; c<=fr[3] ;c++)
						add(dp2[j][c+1],dp2[j-ti][c]);
		}
		fr[g]++;
	}
	w[0][0][0][3]=1;
	ll ans=0;
	for(int i=0; i<=fr[1] ;i++){
		for(int j=0; j<=fr[2] ;j++){
			for(int k=0; k<=fr[3] ;k++){
				for(int l=0; l<3 ;l++){
					for(int m=0; m<4 ;m++){
						if(l==m) continue;
						if(l==0 && i!=0) add(w[i][j][k][l],w[i-1][j][k][m]);
						if(l==1 && j!=0) add(w[i][j][k][l],w[i][j-1][k][m]);
						if(l==2 && k!=0) add(w[i][j][k][l],w[i][j][k-1][m]);
					}
				}
				ll cur=0;
				for(int ts=0; ts<=t ;ts++){
					add(cur,dp[t-ts][i][j]*dp2[ts][k]%mod*(w[i][j][k][0]+w[i][j][k][1]+w[i][j][k][2]+w[i][j][k][3])%mod);
				}
				cur=cur*f[i]%mod*f[j]%mod*f[k]%mod;
				ans=(ans+cur)%mod;
			}
		}
	}
	cout << ans << '\n';
}