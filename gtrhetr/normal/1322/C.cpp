#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

vector<int> v[500010];

pll h[500010];

ll val[500010];
ll num[500010],sum[500010],t,n,m;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

mt19937 rnd(time(NULL));

inline ll gcd(ll x,ll y) { return (!y)?x:gcd(y,x%y); }

inline void work()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) v[i].clear();
	for (int i=1;i<=n;i++) val[i]=(rnd()<<rnd())^rnd(),sum[i]=0;
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(y);
		sum[y]+=val[x];
	}
	for (int i=1;i<=n;i++) h[i]=pll(sum[i],i);
	sort(h+1,h+n+1);
	ll ans=0;
	for (int i=1,j;i<=n;i=j+1)
	{
		for (j=i;j<=n&&h[j].first==h[i].first;j++);j--;
		if (h[i].first==0) continue;
		ll s=0;
		for (int k=i;k<=j;k++) s+=num[h[k].second];
		ans=gcd(ans,s);
	}
	print(ans);
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}