#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
const int mod=1000000007;
struct board
{
	int h,l,r,s;
	bool operator <(const board &other) const
	{
		return h>other.h;
	}
}a[100001];
int maxn,w,n,sum,ans[100001<<2];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[100001];
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
inline int ls(int k)
{
	return k<<1;
}
inline int rs(int k)
{
	return k<<1|1;
}
inline void push_up(int k)
{
	ans[k]=min(ans[ls(k)],ans[rs(k)]);
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		q[l].push(make_pair(maxn+1,1));
		ans[k]=maxn+1;
		return;
	}
	int mid=(l+r)>>1;
	build(ls(k),l,mid);
	build(rs(k),mid+1,r);
	push_up(k);
}
void update(int node,int l,int r,int k,int p,int h)
{
	if(l==r)
	{
		q[l].push(make_pair(h,p));
		ans[k]=min(ans[k],h);
		return;
	}
	int mid=(l+r)>>1;
	if(node<=mid)
		update(node,l,mid,ls(k),p,h);
	else
		update(node,mid+1,r,rs(k),p,h);
	push_up(k);
}
int query(int nl,int nr,int l,int r,int k,int h,int s)
{
	if(ans[k]>h+s)
		return 0;
	if(l==r)
	{
		int res=0;
		while(!q[l].empty()&&q[l].top().first<=h+s)
		{
			res=(res+q[l].top().second)%mod;
			q[l].pop();
		}
		ans[k]=q[l].empty()? 1e10+7:q[l].top().first;
		return res;
	}
	int mid=(l+r)>>1,res=0;
	if(nl<=mid)
		res=(res+query(nl,nr,l,mid,ls(k),h,s))%mod;
	if(nr>mid)
		res=(res+query(nl,nr,mid+1,r,rs(k),h,s))%mod;
	push_up(k);
	return res;
}
signed main()
{
	maxn=read(),w=read(),n=read();
	for(register int i=1;i<=n;++i)
		a[i].h=read(),a[i].l=read(),a[i].r=read(),a[i].s=read();
	sum=w;
	build(1,1,w);
	sort(a+1,a+n+1);
	for(register int i=1;i<=n;++i)
	{
		int tmp=query(a[i].l,a[i].r,1,w,1,a[i].h,a[i].s);
		sum=(sum+tmp)%mod;
		if(a[i].l==1)
			update(a[i].r+1,1,w,1,(tmp<<1)%mod,a[i].h);
		else
			if(a[i].r==w)
				update(a[i].l-1,1,w,1,(tmp<<1)%mod,a[i].h);
			else
			{
				update(a[i].l-1,1,w,1,tmp,a[i].h);
				update(a[i].r+1,1,w,1,tmp,a[i].h);
			}
	}
	printf("%lld\n",sum);
	return 0;
}