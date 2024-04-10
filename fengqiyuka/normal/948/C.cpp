#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[110000],b[110000];
ll d[110000],qz[110000],ans2[110000];int sum=0;
void up(int x)
{
	while(x/2>0&&d[x/2]>d[x])
	{
		ll t=d[x];d[x]=d[x/2];d[x/2]=t;
		x/=2;
	}
}
void down(int x)
{
	while((x*2<=sum&&d[x*2]<d[x])||(x*2+1<=sum&&d[x*2+1]<d[x]))
	{
		if(x*2==sum)
		{
			ll t=d[x*2];d[x*2]=d[x];d[x]=t;
			x*=2;
		}
		else
		{
			if(d[x*2]<d[x*2+1])
			{
				ll t=d[x*2];d[x*2]=d[x];d[x]=t;
				x*=2;
			}
			else
			{
				ll t=d[x*2+1];d[x*2+1]=d[x];d[x]=t;
				x=x*2+1;
			}
		}
	}
}
void insert(ll x) {d[++sum]=x;up(sum);}
void delete2(int x)
{
	if(d[x]>d[sum])
	{
		d[x]=d[sum];sum--;up(x);
	}
	else
	{
		d[x]=d[sum];sum--;down(x);
	}
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	qz[0]=0;for(int i=1;i<=n;i++) qz[i]=qz[i-1]+b[i];
	for(int i=1;i<=n;i++)
	{
		insert(a[i]+qz[i-1]);ll ans=0;
		while(sum>0&&d[1]<=qz[i])
		{
			ans+=d[1]-qz[i-1];
			delete2(1);
		}
		ans+=sum*b[i];ans2[i]=ans;
	}
	for(int i=1;i<n;i++) printf("%lld ",ans2[i]);
	printf("%lld\n",ans2[n]);
	return 0;
}