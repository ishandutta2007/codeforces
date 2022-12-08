#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=998244353;
int s[N],t[N],fac[N],inv[N],sum[N],c[N],P;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void add(int x,int v) {
	for(int i=x;i<=200000;i+=i&-i)
		c[i]+=v;
}
int qry(int x) {
	int sum=0;
	for(int i=x;i;i-=i&-i)
		sum+=c[i];
	return sum;
}
signed main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	int P=fac[n],ans=0;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1;i<=n;i++) {
		scanf("%d",s+i);
		P=1ll*P*fac[sum[s[i]]]%mod;
		sum[s[i]]++;
		P=1ll*P*inv[sum[s[i]]]%mod;
		add(s[i],1);
	}
	for(int i=1;i<=m;i++)
		scanf("%d",t+i);
	for(int i=1;i<=n&&i<=m;i++) {
		ans=(ans+1ll*P*qry(t[i]-1)%mod*qpow(n-i+1,mod-2))%mod;
		if(!sum[t[i]]) {
			cout<<ans<<endl;
			return 0;
		}
		P=1ll*P*sum[t[i]]%mod;
		P=1ll*P*qpow(n-i+1,mod-2)%mod;
		sum[t[i]]--;
		add(t[i],-1);
	}
	if(n<m)ans=(ans+1)%mod;
	cout<<ans<<endl;
	return 0;
}