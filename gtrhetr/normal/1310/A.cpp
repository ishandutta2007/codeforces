#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

multiset<int> st;
vector<int> v[200010];

int a[200010],t[200010],h[400010],n,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=n;i++) t[i]=rd();
	tt=0;
	for (int i=1;i<=n;i++) h[++tt]=a[i];
	sort(h+1,h+tt+1);
	h[++tt]=h[1];
	for (int i=2;i<=n;i++) h[++tt]=max(h[i],h[i-1+n]+1);
	sort(h+1,h+tt+1);
	tt=unique(h+1,h+tt+1)-h-1;
	for (int i=1;i<=n;i++) v[lower_bound(h+1,h+tt+1,a[i])-h].push_back(t[i]);
	ll ans=0,sum=0;
	for (int i=1;i<=tt;i++)
	{
		for (int t:v[i]) st.insert(t),sum+=t;
		if (!st.empty())
		{
			int hh=*st.rbegin();sum-=hh;st.erase(st.find(hh));
			ans+=sum;
		}
	}
	printf("%lld\n",ans);
	return 0;
}