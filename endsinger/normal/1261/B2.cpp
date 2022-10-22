#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct num
{
	int val,pos;
	bool operator<(const num x)const
	{
		return val==x.val?pos<x.pos:val>x.val;
	}
}a[N];
vector<pair<int,int>>q[N];
int ans[N],ar[N],n,m; 
namespace bit
{
	int b[N];
	void add(int i)
	{
		while(i<=n)
		{
			b[i]++;
			i+=i&(-i);
		}
	}
	int query(int i)
	{
		int s=0;
		while(i)
		{
			s+=b[i];
			i-=i&(-i);
		} 
		return s;
	}
}
int solve(int p)
{
	int l=0,r=n+1;
	while(r-l>1)
	{
		int mid=l+r>>1;
		if(bit::query(mid)<=p-1)
			l=mid;
		else
			r=mid;	
	}	
	return ar[r];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);
		a[i].val=ar[i];
		a[i].pos=i;
	}
	sort(a+1,a+n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int k,p;
		scanf("%d%d",&k,&p);
		q[k].push_back(make_pair(p,i));
	}
	for(int i=1;i<=n;i++)
	{
		bit::add(a[i].pos);
		for(auto j:q[i])
		{
			ans[j.second]=solve(j.first);
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}