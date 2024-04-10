#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))

struct tree { int ls,rs,mn; }t[20000010];

pii h[100010];

vector<int> v[50010];

int ans[50010],rt[50010],n,m,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void modify(int &o,int l,int r,int x,int y)
{
	if (!o) o=++tot,t[o].mn=m+1;
	t[o].mn=min(t[o].mn,y);
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) modify(t[o].ls,l,mid,x,y);
	else modify(t[o].rs,mid+1,r,x,y);
}

inline int query(int o,int l,int r,int x)
{
	if (!o) return m+1;
	if (l>=x) return t[o].mn;
	int mid=(l+r)>>1;
	if (x<=mid) return min(query(t[o].ls,l,mid,x),query(t[o].rs,mid+1,r,x));
	return query(t[o].rs,mid+1,r,x);
}

inline int work(int l,int r,int len)
{
	if (r-l+1<len) return 0;
	int res=m+1;
	for (int x=r;x;x-=lowbit(x)) res=min(res,query(rt[x],1,n,l));
	if (res>m) return 0;
	return work(l,h[res].first-1,len)+work(h[res].second+1,r,len)+h[res].second-h[res].first+1;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++) h[i].first=rd(),h[i].second=rd();
	for (int i=1;i<=m;i++) v[h[i].second-h[i].first+1].push_back(i);
	for (int i=n;i;i--)
	{
		for (int t:v[i])
		{
			for (int x=h[t].second;x<=n;x+=lowbit(x)) modify(rt[x],1,n,h[t].first,t);
		}
		ans[i]=work(1,n,i);
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}