#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int f[2005][2005],n,m,K;
void Solve(){
	scanf("%d%d%d",&n,&m,&K);
	printf("%lld\n",1ll*K*f[n][m]%mod);
}
int main(){
	for(int i=1;i<=2000;i++){
		f[i][i]=i;
		for(int j=1;j<i;j++){
			f[i][j]=1ll*(mod+1)/2*(f[i-1][j]+f[i-1][j-1])%mod;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}