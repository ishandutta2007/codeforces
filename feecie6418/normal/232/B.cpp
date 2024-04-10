#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,f[105][10005]={1},c[105][105]={1},w[105][105],q;
ll m;
int Power(int x,ll y) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)w[i][j]=Power(c[n][j],(i<=(m-1)%n+1)?(m-1)/n+1:(m-1)/n);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(n,q);j++){
			for(int k=j;k<=q;k++)f[i][k]=(f[i][k]+1ll*w[i][j]*f[i-1][k-j])%mod;
		}
	}
	cout<<f[n][q];
}