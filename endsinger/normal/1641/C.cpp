#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,tr[N<<2],op[N],x[N],y[N],w[N],a[N],ans[N<<2];
struct nd
{
	int mx,cm,d;
}s[N<<2];
vector<int>f[N];
nd operator +(nd a,nd b)
{
	nd c;
	if(a.mx>b.mx)
		c.mx=a.mx,c.cm=max(a.cm,b.mx),c.d=a.d;
	if(a.mx<b.mx)
		c.mx=b.mx,c.cm=max(a.mx,b.cm),c.d=b.d;
	if(a.mx==b.mx)
		c.mx=c.cm=a.mx,c.d=a.d;
	return c;
}
int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
void build(int k,int l,int r)
{
	tr[k]=q+1;
	if(l==r)
		return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void upd(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]=min(tr[k],v);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) upd(k<<1,l,mid,a,b,v);
	else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
	else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
}
void out(int k,int l,int r,int v)
{
	v=min(v,tr[k]);
	if(l==r)
	{
		a[l]=v;
		return;
	}
	int mid=l+r>>1;
	out(k<<1,l,mid,v);
	out(k<<1|1,mid+1,r,v);
}
void bs(int k,int l,int r)
{
	if(l==r)
	{
		s[k]={a[l],0,l};
		return;
	}
	int mid=l+r>>1;
	bs(k<<1,l,mid);
	bs(k<<1|1,mid+1,r);
	s[k]=s[k<<1]+s[k<<1|1];
}
nd ask(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return s[k];
	int mid=l+r>>1;
	if(b<=mid) return ask(k<<1,l,mid,a,b);
	else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
	else return ask(k<<1,l,mid,a,mid)+ask(k<<1|1,mid+1,r,mid+1,b);
}
void add(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		ans[k]=v;
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) add(k<<1,l,mid,a,b,v);
	else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
	else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
}
int query(int k,int l,int r,int x,int v)
{
	if(ans[k])
		v=ans[k];
	if(l==r)
		return v;
	int mid=l+r>>1;
	if(x<=mid) return query(k<<1,l,mid,x,v);
	else return query(k<<1|1,mid+1,r,x,v);
}
int main()
{
	n=rd(),q=rd();
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		op[i]=rd();
		if(op[i]==0)
		{
			x[i]=rd(),y[i]=rd(),w[i]=rd();
			if(!w[i])
				upd(1,1,n,x[i],y[i],i);
		}
		else
			w[i]=rd();
	}
	out(1,1,n,q+1);
	bs(1,1,n);
	for(int i=1;i<=q;i++)
	{
		for(auto j:f[i])
			add(1,1,n,j,j,1);
		if(op[i]==0)
		{
			if(!w[i])
				add(1,1,n,x[i],y[i],2);
			else
			{
				nd ti=ask(1,1,n,x[i],y[i]);
				if(ti.cm>q)
					continue;
				if(ti.cm>i)
					f[ti.cm].push_back(ti.d);
				else
					add(1,1,n,ti.d,ti.d,1);
			}
		}
		else
		{
			int z=query(1,1,n,w[i],0);
			if(z==0)
				puts("N/A");
			if(z==1)
				puts("YES");
			if(z==2)
				puts("NO");
		}
	}
	return 0;
}