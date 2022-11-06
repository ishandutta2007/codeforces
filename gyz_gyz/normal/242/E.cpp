#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=1e5+10;

struct SegmentTree
{
	int sum[maxn<<2];
	int tag_rev[maxn<<2];
	int tag_set[maxn<<2];
	int tag_reset[maxn<<2];
	int n;

#define ls (o<<1)
#define rs ((o<<1)|1)
#define mid ((l+r)>>1)

	void Mark_Set(int o,int l,int r)
	{
		sum[o]=r-l+1;
		tag_set[o]=1;
		tag_reset[o]=0;
		tag_rev[o]=0;
	}

	void Mark_Reset(int o,int l,int r)
	{
		sum[o]=0;
		tag_reset[o]=1;
		tag_set[o]=0;
		tag_rev[o]=0;
	}

	void Mark_Reverse(int o,int l,int r)
	{
		sum[o]=(r-l+1)-sum[o];
		tag_rev[o]^=1;
	}

	void Push_Down(int o,int l,int r)
	{
		if (tag_set[o])
		{
			Mark_Set(ls,l,mid);
			Mark_Set(rs,mid+1,r);
			tag_set[o]=0;
		}
		if (tag_reset[o])
		{
			Mark_Reset(ls,l,mid);
			Mark_Reset(rs,mid+1,r);
			tag_reset[o]=0;
		}
		if (tag_rev[o])
		{
			Mark_Reverse(ls,l,mid);
			Mark_Reverse(rs,mid+1,r);
			tag_rev[o]=0;
		}
	}

	void Update(int o)
	{
		sum[o]=sum[ls]+sum[rs];
	}

	void Change_Set(int o,int l,int r,int a,int b)
	{
		if (a<=l && r<=b)
		{
			Mark_Set(o,l,r);
			return;
		}
		Push_Down(o,l,r);
		if (a<=mid) Change_Set(ls,l,mid,a,b);
		if (b> mid) Change_Set(rs,mid+1,r,a,b);
		Update(o);
	}

	void Change_Reset(int o,int l,int r,int a,int b)
	{
		if (a<=l && r<=b)
		{
			Mark_Reset(o,l,r);
			return;
		}
		Push_Down(o,l,r);
		if (a<=mid) Change_Reset(ls,l,mid,a,b);
		if (b> mid) Change_Reset(rs,mid+1,r,a,b);
		Update(o);
	}

	void Change_Reverse(int o,int l,int r,int a,int b)
	{
		if (a<=l && r<=b)
		{
			Mark_Reverse(o,l,r);
			return;
		}
		Push_Down(o,l,r);
		if (a<=mid) Change_Reverse(ls,l,mid,a,b);
		if (b> mid) Change_Reverse(rs,mid+1,r,a,b);
		Update(o);
	}

	int Query(int o,int l,int r,int a,int b)
	{
		if (a<=l && r<=b)
			return sum[o];
		Push_Down(o,l,r);
		int res=0;
		if (a<=mid) res+=Query(ls,l,mid,a,b);
		if (b> mid) res+=Query(rs,mid+1,r,a,b);
		return res;
	}

	void BuildTree(int o,int l,int r,int *arr)
	{
		if (l==r)
		{
			sum[o]=arr[l];
			return;
		}
		BuildTree(ls,l,mid,arr);
		BuildTree(rs,mid+1,r,arr);
		Update(o);
	}

	void Change(int a,int b,int op)
	{
		if (op==2) Change_Reverse(1,1,n,a,b);
		if (op==3) Change_Set(1,1,n,a,b);
		if (op==4) Change_Reset(1,1,n,a,b);
	}

	int Query(int a,int b)
	{
		return Query(1,1,n,a,b);
	}

	void Build(int _n,int *arr)
	{
		n=_n;
		BuildTree(1,1,n,arr);
	}
}T[20];

int a[maxn],b[maxn];
int n,q;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int p=0;p<20;p++)
	{
		for (int i=1;i<=n;i++) b[i]=(a[i]&(1<<p))?1:0;
		T[p].Build(n,b);
	}
	scanf("%d",&q);
	while (q--)
	{
		int op,l,r,x;
		scanf("%d%d%d",&op,&l,&r);
		if (op==1)
		{
			long long ans=0;
			for (int p=0;p<20;p++)
				ans+=T[p].Query(l,r)*(1ll<<p);
			cout<<ans<<endl;
		}
		else if (op==2)
		{
			scanf("%d",&x);
			for (int p=0;p<20;p++) if (x&(1<<p))
				T[p].Change(l,r,op);
		}
		else if (op==3)
		{
			scanf("%d",&x);
			for (int p=0;p<20;p++) if (x&(1<<p))
				T[p].Change(l,r,op);
		}
		else
		{
			scanf("%d",&x);
			for (int p=0;p<20;p++) if (!(x&(1<<p)))
				T[p].Change(l,r,op);
		}
	}
	return 0;
}