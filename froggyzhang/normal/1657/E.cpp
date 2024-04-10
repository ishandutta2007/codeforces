#include<bits/stdc++.h>
using namespace std;
#define N 255
typedef long long ll;
const int mod=998244353;
int n,m,dp[N][N],C[N][N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
inline void Plus(int &x,int y){(x+=y)>=mod?x-=mod:233;}
void init(int n){
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
int S(int l,int r){
	return (l+r)*(r-l+1)/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	init(n);
	--n;
	dp[0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=0;k<=i;++k){
				int w=dp[i-k][j-1];
				if(!w)continue;
				Plus(dp[i][j],1LL*w*C[n-(i-k)][k]%mod*qpow(j,S(n-i,n-(i-k+1)))%mod);
			}
		}
	}
	cout<<dp[n][m]<<'\n';
	return 0;
}