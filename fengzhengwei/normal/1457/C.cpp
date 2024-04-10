#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll n,p,k;
int a[1000005];
ll f[1000005];
int g[1000005];
signed main(){
	int T=read();
	while(T--)
	{
		n=read();
		p=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%1d",&a[i]);
			f[i]=a[i]^1;
		}
		ll x,y;
		x=read();
		y=read();
		ll ans=1e18;
		for(int i=n-k;i>=1;i--)f[i]+=f[i+k];
		for(int i=p;i<=n;i++)
		{
			ans=min(ans,(i-p)*y+x*f[i]);
//			cout<<i<<" "<<f[i]<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}