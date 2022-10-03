#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> v[100010];
vector<int> v1[100010];

int mx[100010],mn[100010];
int num[100010],h[100010],n,m,tt;
bool bo[100010];

inline int rd()
{
	int x=0;char ch=getchar();
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

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;i++) num[i]=i;
	ll ans=0;
	for (int i=1;i<=n;i++) for (int t:v[i])
	{
		if (num[t]>num[i]) mx[i]++,v1[i].push_back(t);
		else mn[i]++;
	}
	for (int i=1;i<=n;i++) ans+=(ll)mx[i]*mn[i];
	print(ans);
	int q=rd();
	for (int i=1;i<=q;i++)
	{
		int x=rd();int tt=0;
		ans-=(ll)mx[x]*mn[x];
		for (int t:v1[x]) if (num[t]>num[x]&&!bo[t])
		{
			h[++tt]=t;bo[t]=true;
			ans-=(ll)mx[t]*mn[t];
			mn[t]--;mx[t]++;
			ans+=(ll)mx[t]*mn[t];
			v1[t].push_back(x);
			mx[x]--;mn[x]++;
		}
		num[x]=n+i;
		v1[x].clear();
		for (int j=1;j<=tt;j++) bo[h[j]]=false;
		print(ans);
	}
	return 0;
}