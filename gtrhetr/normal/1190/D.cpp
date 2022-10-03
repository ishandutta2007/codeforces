#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&(-(x)))

struct node { int x,y; }a[200010];

vector<int> v[200010];

int h[200010],lst[200010],c[200010],n,t1,t2,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x) { for (;x<=t2;x+=lowbit(x)) c[x]++; }

inline int query(int x)
{
	int res=0;
	for (;x;x-=lowbit(x)) res+=c[x];
	return res;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	for (int i=1;i<=n;i++) h[++tt]=a[i].x;
	sort(h+1,h+tt+1);
	tt=unique(h+1,h+tt+1)-h-1;
	for (int i=1;i<=n;i++) a[i].x=lower_bound(h+1,h+tt+1,a[i].x)-h;
	t2=tt;
	tt=0;
	for (int i=1;i<=n;i++) h[++tt]=a[i].y;
	sort(h+1,h+tt+1);
	tt=unique(h+1,h+tt+1)-h-1;
	for (int i=1;i<=n;i++) a[i].y=lower_bound(h+1,h+tt+1,a[i].y)-h;
	t1=tt;
	for (int i=1;i<=n;i++) v[a[i].y].push_back(a[i].x);
	ll ans=0;
	int tt=0;
	for (int i=t1;i;i--)
	{
		for (int t:v[i])
		{
			if (!lst[t]) add(t),lst[t]=1,tt++;
		}
		v[i].push_back(0);
		v[i].push_back(t2+1);
		sort(v[i].begin(),v[i].end());
		ans+=(ll)tt*(tt+1)/2;
		for (int j=0;j<v[i].size()-1;j++)
		{
			ll now=query(v[i][j+1]-1)-query(v[i][j]);
			ans-=(ll)now*(now+1)/2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}