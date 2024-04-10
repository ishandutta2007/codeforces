#include<bits/stdc++.h>
using namespace std;
int n,k,q,sz,tp,a[222222][11],b[11],x,l,r,ans;
int get(int a[],int msk)
{
	int res=0;
	for (int i=0;i<k;i++)
	{
		if (msk&(1<<i)) res+=a[i];
		else res-=a[i];
	}
	return res;
}
struct segtree
{
	int tree[1111111];
	void build(int l,int r,int node,int msk)
	{
		if (l==r) 
		{
			if (l<=n) tree[node]=get(a[l],msk);
			else tree[node]=-1e9;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,node<<1,msk);
		build(mid+1,r,(node<<1)|1,msk);
		tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
	}
	void update(int x,int y)
	{
		int pos=sz-1+x;
		tree[pos]=y;pos>>=1;
		while(pos>=1)
		{
			tree[pos]=max(tree[pos<<1],tree[(pos<<1)|1]);
			pos>>=1;
		}
	}
	int query(int beg,int en,int l,int r,int node)
	{
		if (l>en || r<beg) return -1e9;
		if (l>=beg && r<=en) return tree[node];
		int mid=(l+r)>>1;
		return max(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
	}
}st[44];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<k;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	sz=1;
	while(sz<n) sz*=2;
	for (int i=0;i<(1<<k);i++) st[i].build(1,sz,1,i);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d",&x);
			for (int i=0;i<k;i++) scanf("%d",&b[i]);
			for (int i=0;i<(1<<k);i++) st[i].update(x,get(b,i));
		}
		else
		{
			ans=0;
			scanf("%d%d",&l,&r);
			for (int i=0;i<(1<<(k-1));i++)
			{
				ans=max(ans,st[i].query(l,r,1,sz,1)+st[(1<<k)-1-i].query(l,r,1,sz,1));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}