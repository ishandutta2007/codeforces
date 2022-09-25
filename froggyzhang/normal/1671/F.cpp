#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int dp[44][13][13][13],s[44][13][13];
inline void Plus(int &x,int y){
	(x+=y)>=mod?x-=mod:233;
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int Lagrange(int *x,int *y,int n,int k){
	int ans=0;
	for(int i=1;i<=n;++i){
		int A=1,B=1;
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			A=1LL*A*(k-x[j])%mod;
			B=1LL*B*(x[i]-x[j])%mod;
		}
		A=(A+mod)%mod,B=(B+mod)%mod;
		ans=(ans+1LL*A*qpow(B,mod-2)%mod*y[i])%mod;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0][0][0][0]=1;
	for(int i=1;i<=40;++i){
		for(int j=0;j<=11;++j){
			for(int k=0;k<=11;++k){
				for(int x=0;x<=min(i-1,11);++x){
					for(int y=0;y<=min(i-1,11);++y){ //  y 
						if((!k&&x<y)||j<y)continue;
						Plus(dp[i][j][k][y],dp[i-1][j-y][k-(x<y)][x]);
					}
				}
				for(int x=0;x<=11;++x){
					Plus(s[i][j][k],dp[i][j][k][x]);
				}
			}
		}
	}
	int T;
	cin>>T;
	while(T--){
		int n,k,x;
		cin>>n>>k>>x;
		if(n<=40){
			cout<<s[n][k][x]<<'\n';
		}
		else{
			static int X[25],Y[25];
			for(int i=1;i<=20;++i){
				X[i]=20+i,Y[i]=s[20+i][k][x];
			}
			cout<<Lagrange(X,Y,20,n)<<'\n';
		}
	}
	return 0;
}