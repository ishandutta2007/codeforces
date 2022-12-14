#include<iostream>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct data
{
	int milk,order,ans;	
	friend data operator + (const data&a,const data&b)
	{
		data c;int add=min(a.milk,b.order);add=0;
		c.ans=a.ans+b.ans+add;
		c.milk=a.milk+b.milk-add;
		c.order=a.order+b.order-add;
		return c;	
	}
	void Mod(int x){int add=min(milk,x);ans+=add;milk-=add;order+=x-add;}
};
struct Tree{int l,r;data d[3];}T[MN*4+5]; 
int n,a,b,k,m;

void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r)) 
	{
		T[x].d[0]=(data){0,0,0};
		T[x].d[1]=(data){a,0,0};
		T[x].d[2]=(data){b,0,0};
		return;
	}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	for(int i=0;i<3;++i) T[x].d[i]=T[x<<1].d[i]+T[x<<1|1].d[i];
}

void Modify(int x,int k,int v)
{
	if(T[x].l==T[x].r) 
	{
		for(int i=0;i<3;++i) T[x].d[i].Mod(v);
		return; 
	}
	int mid=T[x].l+T[x].r>>1;
	Modify(x<<1|(k>mid),k,v);
	for(int i=0;i<3;++i) T[x].d[i]=T[x<<1].d[i]+T[x<<1|1].d[i];
}

data Query(int x,int l,int r,int v)
{
	if(l>r) return (data){0,0,0};
	if(T[x].l==l&&T[x].r==r) return T[x].d[v];
	int mid=T[x].l+T[x].r>>1;
	if(r<=mid) return Query(x<<1,l,r,v);
	else if(l>mid) return Query(x<<1|1,l,r,v);
	else return Query(x<<1,l,mid,v)+Query(x<<1|1,mid+1,r,v);
}

int main()
{
	n=read();k=read();b=read();a=read();m=read();
	Build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int op=read(),p,v;
		if(op==2) p=read(),printf("%d\n",(Query(1,1,p-1,1)+Query(1,p,p+k-1,0)+Query(1,p+k,n,2)).ans);
		else p=read(),v=read(),Modify(1,p,v);
	}
	return 0;
}