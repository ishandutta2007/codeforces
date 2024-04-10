#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,K,f[1005][1005],s[1005][1005],a[1005],ans=0;
int Calc(int x){
	a[0]=-1e9,f[0][0]=s[0][0]=1;
	int ans=0;
	for(int i=1,p=0;i<=n;i++){
		while(a[i]-a[p+1]>=x)p++;
		s[0][i]=1;
		for(int j=1;j<=i&&j<=K;j++){
			f[j][i]=s[j-1][p];
			s[j][i]=(s[j][i-1]+f[j][i])%mod;
		}
		ans=(ans+f[K][i])%mod;
	}
	return ans;
}
int main(){
	cin>>n>>K;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=100000/(K-1);i++)ans=(ans+Calc(i))%mod;
	cout<<ans;
}