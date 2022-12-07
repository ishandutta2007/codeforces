#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=998244353;
const int N=4e5+5;
int fpow(int x,int k)
{
	if(k<0)return 0;
	int ans=1,base=x;
	while(k)
	{
		if(k&1)ans=1ll*ans*base%P;
		base=1ll*base*base%P,k>>=1;
	} return ans;
}
int n,D,sum[N],cnt[N],s[N],a[N],w[N];
int d[N],f[N],g[N],ans[N];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&a[i],&w[i]);int u=a[i];
		d[u]=1ll*a[i]*a[i]%P*w[i]%P;
		f[u]=a[i]*w[i]%P,g[u]=w[i];
		D=max(D,a[i]);
	} 
	for(int i=1;i<=D;++i)
	{
		for(int j=i;j<=D;j+=i)
			cnt[i]=(cnt[i]+g[j]),
			s[i]=(s[i]+d[j])%P,
			sum[i]=(sum[i]+f[j])%P;	
	} 
	for(int i=1;i<=D;++i)
	{
		if(cnt[i]<=1)continue;
		int S=sum[i]*sum[i]%P;
		int fS=s[i]%P;S=(S-fS+P)%P;
		int ct=cnt[i];
		int fg=(ct-2)%P*fpow(2,ct-3)%P;
		int fu=fpow(2,ct-2)%P;
		int ff=(ct-1)%P*fpow(2,ct-2)%P;
		ans[i]=S*(fu+fg)%P;
		ans[i]=(ans[i]+fS*ff%P)%P;
	} 
	for(int i=D;i>=1;--i)
	{
		for(int j=i*2;j<=D;j+=i)
			ans[i]=(ans[i]-ans[j]+P)%P;
	}
	cout<<(ans[1]%P+P)%P<<endl;
	return 0;
}