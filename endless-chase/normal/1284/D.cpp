#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,s[111111],t[111111],x[111111],y[111111];
int arr[444444],cnt;
map<int,int> mp;
struct mntree
{
	int tree[2222222];
	mntree()
	{
		for (int i=1;i<=2000000;i++) tree[i]=1e9;
	}
	void upd(int x,int l,int r,int node,int y)
	{
		if (l==r)
		{
			tree[node]=min(tree[node],y);
			return;
		}
		int mid=(l+r)>>1;
		if (x>mid) upd(x,mid+1,r,(node<<1)|1,y);
		else upd(x,l,mid,node<<1,y);
		tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
	}
	int query(int beg,int en,int l,int r,int node)
	{
		if (l>en || r<beg) return 1e9;
		if (l>=beg && r<=en) return tree[node];
		int mid=(l+r)>>1;
		return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1)); 
	}
}t1,t2;
struct mxtree
{
	int tree[2222222];
	mxtree()
	{
		memset(tree,0,sizeof(tree));
	}
	void upd(int x,int l,int r,int node,int y)
	{
		if (l==r)
		{
			tree[node]=max(tree[node],y);
			return;
		}
		int mid=(l+r)>>1;
		if (x>mid) upd(x,mid+1,r,(node<<1)|1,y);
		else upd(x,l,mid,node<<1,y);
		tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
	}
	int query(int beg,int en,int l,int r,int node)
	{
		if (l>en || r<beg) return -1e9;
		if (l>=beg && r<=en) return tree[node];
		int mid=(l+r)>>1;
		return max(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1)); 
	}
}t3,t4;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&s[i],&t[i],&x[i],&y[i]);
		arr[++cnt]=s[i];arr[++cnt]=t[i];arr[++cnt]=x[i];arr[++cnt]=y[i];
	}
	sort(arr+1,arr+cnt+1);
	cnt=unique(arr+1,arr+cnt+1)-arr-1;
	for (int i=1;i<=cnt;i++) mp[arr[i]]=i;
	for (int i=1;i<=n;i++)
	{
		s[i]=mp[s[i]];t[i]=mp[t[i]];x[i]=mp[x[i]];y[i]=mp[y[i]];
	}
	for (int i=1;i<=n;i++)
	{
		t3.upd(s[i],1,cnt,1,x[i]);t3.upd(t[i],1,cnt,1,x[i]);
		t1.upd(s[i],1,cnt,1,y[i]);t1.upd(t[i],1,cnt,1,y[i]);
		t4.upd(x[i],1,cnt,1,s[i]);t4.upd(y[i],1,cnt,1,s[i]);
		t2.upd(x[i],1,cnt,1,t[i]);t2.upd(y[i],1,cnt,1,t[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (t3.query(s[i],t[i],1,cnt,1)>y[i] || t1.query(s[i],t[i],1,cnt,1)<x[i]) 
		{
			printf("NO\n");
			return 0;
		}
		if (t4.query(x[i],y[i],1,cnt,1)>t[i] || t2.query(x[i],y[i],1,cnt,1)<s[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return Accepted;
}