#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];
int n,m;
struct data{int ans,l,r;
	friend data operator + (const data&a,const data&b)
	{
		int mn=min(a.l,b.r);
		return (data){a.ans+b.ans+mn,a.l+b.l-mn,a.r+b.r-mn}; 
	}  
};
struct Tree{int l,r;data x;}T[MN*4+5];
void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r)) {T[x].x=(data){0,st[l]=='(',st[l]==')'};return;}	
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	T[x].x=T[x<<1].x+T[x<<1|1].x; 
}
data Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x].x;
	int mid=T[x].l+T[x].r>>1;
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r);
}
int main()
{
	scanf("%s",st+1);n=strlen(st+1);Build(1,1,n);
	m=read();
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read();
		printf("%d\n",2*Query(1,l,r).ans);	
	}
	return 0;
}