#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,K,jc[5005]={1},ny[5005]={1},ans=0,a[5005],f[5005][5005],cnt[5005];
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
int main(){
	for(int i=1;i<=5000;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[5000]=Power(jc[5000],mod-2);
	for(int i=5000-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int S=1;
		for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
		for(int i=1;i<=n;i++)S=1ll*S*ny[cnt[i]]%mod;
		f[0][0]=S;
		reverse(a+1,a+n+1);
		a[n+1]=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				for(int j=0;j<=n;j++)f[i][j]=f[i-1][j];
				continue;
			}
			f[i][0]=f[i-1][0];
			for(int j=1;j<=i&&j<=n/2;j++){
				int w=1;
				if(j>1)w=1ll*w*max(0,n-i-(n-2*j+1))%mod;
				if(j==n/2)w=1ll*w*max(0,n-i)%mod;
				f[i][j]=(f[i-1][j]+1ll*f[i-1][j-1]*cnt[a[i]]%mod*w)%mod;
			}
		}
		cout<<f[n][n/2]<<'\n';
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=0;
		for(int i=0;i<=n;i++)cnt[i]=0;
	}
}