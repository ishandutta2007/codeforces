#include<iostream>
#include<cstdio>
#define MN 100000
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct data{ll lmx,rmx,len,rlen,ans;
	data operator + (const data&b)
	{
		data c;
		c.len=len+b.len+rlen;c.rlen=b.rlen;
		c.ans=max(max(ans,b.ans),rmx+b.lmx+rlen);
		c.lmx=max(lmx,b.lmx+rlen+len);
		c.rmx=max(b.rmx,rmx+rlen+b.len);
		return c;
	}
};
struct Tree{int l,r;data x;}T[MN*4+5];
int n,m,d[MN+5],h[MN+5];
void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r)){T[x].x=(data){h[l],h[l],0,d[l],0};return;}	
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
	n=read();m=read();
	for(int i=1;i<=n;++i) d[i]=read();
	for(int i=1;i<=n;++i) h[i]=read()<<1;
	Build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read();
		if(l<=r) 
		{
			if(r==n) printf("%lld\n",Query(1,1,l-1).ans);
			else if(l==1) printf("%lld\n",Query(1,r+1,n).ans);
			else printf("%lld\n",(Query(1,r+1,n)+Query(1,1,l-1)).ans);
		}
		else printf("%lld\n",Query(1,r+1,l-1).ans);
	}
	return 0;
}