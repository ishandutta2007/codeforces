#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> v[7010];

int sum[7010];
ll a[7010],b[7010],n,now;
bool bo[7010];

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool check()
{
	bool flag=false;
	for (int i=1;i<=n;i++) if (bo[i]&&sum[i]==now-1)
	{
		flag=true;bo[i]=false;
		for (int j=1;j<=n;j++) if (bo[j]&&(a[i]&a[j])!=a[j]) sum[j]--;
		break;
	}
	return flag;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=n;i++) b[i]=rd();
	for (int i=1;i<=n;i++) bo[i]=true;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (i!=j&&(a[i]&a[j])!=a[i]) sum[i]++;
	now=n;
	while (check()) now--;
	int sum=0;
	for (int i=1;i<=n;i++) sum+=bo[i];
	if (sum<=1) puts("0");
	else
	{
		ll ans=0;
		for (int i=1;i<=n;i++) if (bo[i]) ans+=b[i];
		printf("%lld\n",ans);
	}
	return 0;
}