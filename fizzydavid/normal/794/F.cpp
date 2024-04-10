//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int ia[100111];
int digit[11];
int q1,q2;
struct SGT
{
	struct node
	{
		ll sum[10];
		ll p[10];
		node()
		{
			memset(sum,0,sizeof(sum));
			for(int i=0;i<10;i++)p[i]=i;
		}
	}a[400111];
	#define ls p<<1
	#define rs p<<1|1
	void sumup(int p)
	{
		for(int i=0;i<10;i++)a[p].sum[i]=a[ls].sum[i]+a[rs].sum[i];
	}
	void build(int l,int r,int p=1)
	{
		if(l==r)
		{
			int tmp=ia[l],bs=1;
			while(tmp)
			{
				a[p].sum[tmp%10]+=bs;
				tmp/=10;
				bs*=10;
			}
			return;
		}
		int m=l+r>>1;
		build(l,m,ls);
		build(m+1,r,rs);
		sumup(p);
	}
	void update(int p,int pp)
	{
		ll nsum[10]={};
		for(int i=0;i<10;i++)
		{
			nsum[a[pp].p[i]]+=a[p].sum[i];
		}
		for(int i=0;i<10;i++)a[p].sum[i]=nsum[i];
	}
	void pushdown(int p,bool f)
	{
		update(p,p);
		if(f)
		{
			for(int i=0;i<10;i++)
			{
				a[ls].p[i]=a[p].p[a[ls].p[i]];
				a[rs].p[i]=a[p].p[a[rs].p[i]];
			}
		}
		for(int i=0;i<10;i++)a[p].p[i]=i;
	}
	void change(int x,int y,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)
		{
			for(int i=0;i<10;i++)if(a[p].p[i]==q1)a[p].p[i]=q2;
			pushdown(p,l!=r);
			return;
		}
		pushdown(p,l!=r);
		if(r<x||y<l)return;
		int m=l+r>>1;
		change(x,y,l,m,ls);
		change(x,y,m+1,r,rs);
		sumup(p);
	}
	ll query(int x,int y,int l,int r,int p=1)
	{
		pushdown(p,l!=r);
		if(x<=l&&r<=y)
		{
			ll ret=0;
			for(int i=0;i<10;i++)ret+=a[p].sum[i]*i;
			return ret;
		}
		int m=l+r>>1;
		ll ret=0;
		if(x<=m)ret+=query(x,y,l,m,ls);
		if(m<y)ret+=query(x,y,m+1,r,rs);
		return ret;
	}
	void out(int l,int r,int p=1)
	{
		cout<<p<<":"<<l<<","<<r<<endl;
		for(int i=0;i<10;i++)cout<<a[p].sum[i]<<" ";cout<<endl;
		for(int i=0;i<10;i++)cout<<a[p].p[i]<<" ";cout<<endl;
		if(l<r)
		{
			int m=l+r>>1;
			out(l,m,ls);
			out(m+1,r,rs);
		}
	}
}A;
int n,q;
int main()
{
	getii(n,q);
	for(int i=1;i<=n;i++)geti(ia[i]);
	A.build(1,n);
	for(int i=1;i<=q;i++)
	{
		int cmd;
		geti(cmd);
		int l,r;
		getii(l,r);
		if(cmd==1)
		{
			getii(q1,q2);
			if(q1!=q2)A.change(l,r,1,n);
		}
		else
		{
			putsi(A.query(l,r,1,n));
		}
//		A.out(1,n);
	}
	return 0;
}