#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=105;
int tr[N<<2],tag[N<<2][M],n,q;
void build(int k,int l,int r)
{
	for(int i=1;i<=100;i++)
		tag[k][i]=i;
	if(l==r)
	{
		scanf("%d",&tr[k]);
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void pushdown(int k)
{
	for(int i=1;i<=100;i++)
	{
		tag[k<<1][i]=tag[k][tag[k<<1][i]];
		tag[k<<1|1][i]=tag[k][tag[k<<1|1][i]];
	}
	for(int i=1;i<=100;i++)
		tag[k][i]=i;
}
void update(int k,int l,int r,int a,int b,int x,int y)
{
	if(l==a&&r==b)
	{
		for(int i=1;i<=100;i++)
			if(tag[k][i]==x)
				tag[k][i]=y;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,x,y);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,x,y);
	else update(k<<1,l,mid,a,mid,x,y),update(k<<1|1,mid+1,r,mid+1,b,x,y);
}
void out(int k,int l,int r)
{
	if(l==r)
	{
		printf("%d ",tag[k][tr[k]]);
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	out(k<<1,l,mid);
	out(k<<1|1,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&b,&x,&y);
		update(1,1,n,a,b,x,y);
	}
	out(1,1,n);
	return 0;
}