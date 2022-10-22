#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int tr[N<<2],tag[N<<2],p[N],q[N],a[N],n;
int pushdown(int k)
{
	tr[k<<1]+=tag[k];
	tag[k<<1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void add(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tag[k]+=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) add(k<<1,l,mid,a,b,v);
	else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
	else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		a[p[i]]=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&q[i]);
	add(1,1,n,1,a[n],1);
	for(int i=1,ans=n;i<=n;i++)
	{
		printf("%d ",ans);
		if(i<n)
		{
			add(1,1,n,1,q[i],-1);
			while(tr[1]<=0)
			{
				ans--;
				add(1,1,n,1,a[ans],1);
			}
		}
	}
	return 0;
}