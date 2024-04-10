#include<bits/stdc++.h>
using namespace std;
int fac[250010];///////////////////
int main() {/////////////
	int n,m;///////////////
	cin>>n>>m;////////
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%m;
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+1ll*(n-i+1)*(n-i+1)%m*fac[i]%m*fac[n-i])%m;
	cout<<ans<<endl;
	return 0;
}