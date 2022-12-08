#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int inv[maxn],fac[maxn],s[maxn],sum[45][maxn],a[45],b[45],l[maxn],r[maxn],f[maxn];
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m) {
	if(m<0||n<m)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",l+i,r+i);
		s[l[i]]++;
		s[r[i]+1]--;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++)s[i]+=s[i-1];
	for(int i=0;i<=2*m;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=(sum[i][j-1]+C(s[j]-i,j-i))%mod;
	for(int i=0;i<m;i++)
		scanf("%d%d",a+i,b+i);
	for(int i=0;i<1<<m;i++) {
		int L=1,R=n,cnt=0,c1=0;
		for(int j=0;j<m;j++)f[a[j]]=f[b[j]]=0;
		for(int j=0;j<m;j++)
			if(i>>j&1) {
				c1^=1;
				if(!f[a[j]])cnt+=(f[a[j]]=1);
				if(!f[b[j]])cnt+=(f[b[j]]=1);
				L=max(L,max(l[a[j]],l[b[j]]));
				R=min(R,min(r[a[j]],r[b[j]]));
			}
		if(L>R)continue;
		if(c1)ans=(0ll+ans-sum[cnt][R]+sum[cnt][L-1]+mod)%mod;
		else ans=(0ll+ans+sum[cnt][R]-sum[cnt][L-1]+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}