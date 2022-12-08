#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,mod=998244353;
int a[maxn],f[maxn],c[maxn],C[maxn],n;
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
	for(int i=x;i<=n;i+=i&-i)C[i]+=v;
}
int qry(int x) {
	int sum=0;
	for(int i=x;i;i-=i&-i)sum+=C[i];
	return sum;
}
int main() {
	int m=0,cnt=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(a[i]!=-1)f[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
		if(!f[i])c[++m]=i;
	for(int i=1;i<=n;i++) {
		if(a[i]==-1)cnt++;
		else {
			ans=(ans+1ll*cnt*qpow(m,mod-2)%mod*(m-(lower_bound(c+1,c+m+1,a[i])-c-1)))%mod;
			ans=(ans+1ll*(m-cnt)*qpow(m,mod-2)%mod*(lower_bound(c+1,c+m+1,a[i])-c-1))%mod;
		}
	}
	ans=(ans+1ll*m*(m-1)/2%mod*(mod+1)/2)%mod;
	for(int i=n;i>=1;i--) {
		if(a[i]==-1)continue;
		ans=(ans+qry(a[i]))%mod;
		add(a[i],1);
	}
	printf("%d\n",ans);
	return 0;
}