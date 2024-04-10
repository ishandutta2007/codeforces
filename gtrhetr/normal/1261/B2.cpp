#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<pii> v[200010];

pii c[200010];

int ans[200010];
int num[200010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const pii &x,const pii &y) { return (x.first!=y.first)?(x.first>y.first):(x.second<y.second); }

int sum[800010];

inline void modify(int o,int l,int r,int x)
{
	sum[o]++;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x);
	else modify(o<<1|1,mid+1,r,x);
}

inline int query(int o,int l,int r,int x)
{
	if (l==r) return num[l];
	int mid=(l+r)>>1;
	if (sum[o<<1]>=x) return query(o<<1,l,mid,x);
	return query(o<<1|1,mid+1,r,x-sum[o<<1]);
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) c[i]=pii(num[i],i);
	sort(c+1,c+n+1,cmp);
	m=rd();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(pii(y,i));
	}
	for (int i=1;i<=n;i++)
	{
		modify(1,1,n,c[i].second);
		for (pii hh:v[i]) ans[hh.second]=query(1,1,n,hh.first);
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}