#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int ans=0,n,m,b[5005],cnt[5005],a[5005],f[5005][5005],sum[5005][5005],ny[5005]={0,1};
int main(){
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=2;i<=m;i++)ny[i]=1ll*(mod-mod/i)*ny[mod%i]%mod;
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)if(b[i]^b[i-1])a[++n]=b[i],cnt[n]=1;else cnt[n]++;
	sum[0][0]=1;
	for(int i=1;i<=n;i++){
		sum[i][0]=1;
		for(int j=1;j<=i;j++){
			f[i][j]=1ll*sum[i-1][j-1]*cnt[i]%mod*ny[m-j+1]%mod;
			sum[i][j]=(sum[i-1][j]+f[i][j])%mod;
			ans=(ans+1ll*f[i][j]*ny[m-j]%mod*(cnt[i]-1))%mod;
		}
	}
	cout<<ans;
    return 0;
}