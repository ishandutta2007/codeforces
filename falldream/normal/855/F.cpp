#include<iostream>
#include<cstdio>
#define MN 100000
#define INF 2000000000 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct data{int mx,mx2,num,val;
	friend data operator + (data a,data b)
	{
		data c;c.val=0;
		if(b.mx==a.mx) 
		{
			c.mx=a.mx;c.num=a.num+b.num;
			c.mx2=max(a.mx2,b.mx2);
		}
		else 
		{
			if(a.mx<b.mx) swap(a,b);
			c.mx=a.mx;c.num=a.num;
			c.mx2=max(a.mx2,b.mx);
		}
		return c;
	}
};
struct SegTree
{
	struct Tree{int l,r;data x,X;long long sum;}T[MN*4+5];
	void update(int x)
	{		
		T[x].x=T[x<<1].x+T[x<<1|1].x;
		T[x].X=T[x<<1].X+T[x<<1|1].X;
		T[x].sum=T[x<<1].sum+T[x<<1|1].sum;
	}
	void Mark2(int x,int v)
	{
		if(v>=T[x].X.mx) return;
		if(v>T[x].X.mx2) 
		{
			T[x].sum-=1LL*(T[x].X.mx-v)*T[x].X.num;
			T[x].X.mx=v;T[x].X.val=v;
		}
	}
	void Mark(int x,int v)
	{
		if(v>=T[x].x.mx) return;
		if(v>T[x].x.mx2)
		{
			T[x].sum-=1LL*(T[x].x.mx-v)*T[x].x.num;
			T[x].x.mx=v;T[x].x.val=v;
		}
	}
	void pushdown(int x)
	{
		if(T[x].x.val) Mark(x<<1,T[x].x.val),Mark(x<<1|1,T[x].x.val),T[x].x.val=0;
		if(T[x].X.val) Mark2(x<<1,T[x].X.val),Mark2(x<<1|1,T[x].X.val),T[x].X.val=0;
	}
	void Build(int x,int l,int r)
	{
		if((T[x].l=l)==(T[x].r=r)){T[x].x=T[x].X=(data){INF,INF,1,0};T[x].sum=0;return;}	
		int mid=l+r>>1;
		Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
		update(x);
	}
	void Modify2(int x,int l,int r,int v)
	{	 
		if(T[x].l==l&&T[x].r==r)
		{
			if(l==r) {T[x].X=(data){min(T[x].X.mx,v),0,0,0};if(T[x].x.mx<INF&&T[x].X.mx<INF)T[x].sum=T[x].x.mx+T[x].X.mx,T[x].X.num=T[x].x.num=1;}
			else 
			{
				if(v>T[x].X.mx2) Mark2(x,v);
				else 
				{
					int mid=l+r>>1;pushdown(x);
					Modify2(x<<1,l,mid,v);
					Modify2(x<<1|1,mid+1,r,v);
					update(x);
				}
			}
			return;
		}
		int mid=T[x].l+T[x].r>>1;pushdown(x);
		if(r<=mid) Modify2(x<<1,l,r,v);
		else if(l>mid) Modify2(x<<1|1,l,r,v);
		else Modify2(x<<1,l,mid,v),Modify2(x<<1|1,mid+1,r,v);
		update(x); 
	}
	void Modify(int x,int l,int r,int v)
	{ 
		if(T[x].l==l&&T[x].r==r)
		{
			if(l==r) {T[x].x=(data){min(T[x].x.mx,v),0,0,0};if(T[x].x.mx<INF&&T[x].X.mx<INF)T[x].sum=T[x].x.mx+T[x].X.mx,T[x].X.num=T[x].x.num=1;}
			else 
			{
				if(v>T[x].x.mx2) Mark(x,v);
				else 
				{
					int mid=l+r>>1;pushdown(x);
					Modify(x<<1,l,mid,v);
					Modify(x<<1|1,mid+1,r,v);
					update(x);
				}
			}
			return;
		}
		int mid=T[x].l+T[x].r>>1;pushdown(x);
		if(r<=mid) Modify(x<<1,l,r,v);
		else if(l>mid) Modify(x<<1|1,l,r,v);
		else Modify(x<<1,l,mid,v),Modify(x<<1|1,mid+1,r,v);
		update(x); 
	}
	long long Query(int x,int l,int r)
	{
		if(T[x].l==l&&T[x].r==r) return T[x].sum;
		int mid=T[x].l+T[x].r>>1;pushdown(x);
		if(r<=mid) return Query(x<<1,l,r);
		else if(l>mid) return Query(x<<1|1,l,r);
		else return Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r);
	}
}s;
int main()
{
	s.Build(1,1,MN);
	for(int Q=read();Q;--Q)
	{
		int op=read(),l=read(),r=read()-1;
		if(op==1) 
		{
			int k=read();	
			if(k>0) s.Modify(1,l,r,k);
			else s.Modify2(1,l,r,-k);
		}
		else printf("%lld\n",s.Query(1,l,r));
	}
	return 0;
}