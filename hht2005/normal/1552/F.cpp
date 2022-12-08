#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
int x[N],y[N],s[N],f[N],sum[N];
int main() {
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",x+i,y+i,s+i);
		int t=lower_bound(x+1,x+i+1,y[i])-x;
		f[i]=(0ll+sum[i-1]-sum[t-1]+x[i]-y[i])%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
		if(s[i])ans=(ans+f[i])%mod;
	}
	ans=(ans+x[n]+1)%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}