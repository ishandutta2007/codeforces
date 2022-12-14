#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 500000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Tree{int l,r,x;}T[MN*4+5];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,a[MN+5],num;
void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r)){T[x].x=a[l];return;}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);	
	T[x].x=gcd(T[x<<1].x,T[x<<1|1].x);
}
void Modify(int x,int k,int v)
{
	if(T[x].l==T[x].r){T[x].x=v;return;}
	int mid=T[x].l+T[x].r>>1;
	Modify(x<<1|(k>mid),k,v);
	T[x].x=gcd(T[x<<1].x,T[x<<1|1].x);	
}
void Query(int x,int l,int r,int g)
{
	if(num>1||T[x].x%g==0) return;
	if(T[x].l==l&&T[x].r==r) 
	{
		if(T[x].l==T[x].r) ++num;
		else Query(x<<1,l,l+r>>1,g),Query(x<<1|1,(l+r)/2+1,r,g);
		return;
	}
	int mid=T[x].l+T[x].r>>1;
	if(r<=mid) Query(x<<1,l,r,g);
	else if(l>mid) Query(x<<1|1,l,r,g);
	else Query(x<<1,l,mid,g),Query(x<<1|1,mid+1,r,g);
}	
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	Build(1,1,n);int Q=read();
	while(Q--)
	{
		int op=read(),l=read(),r=read();
		if(op==2) Modify(1,l,r);
		else 
		{
			int g=read();num=0;
			Query(1,l,r,g);
			puts(num<=1?"YES":"NO");
		}
	}
	return 0;
}