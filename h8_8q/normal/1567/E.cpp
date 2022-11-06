#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5;
int n,q,a[N],b[N];

struct Node
{
	int lh,rh,len,sum;
	Node operator + (const Node &x)const
	{
		Node res;
		res.sum=sum+x.sum+rh*x.lh;
		res.len=len+x.len;
		res.lh=lh+(lh==len?x.lh:0);
		res.rh=x.rh+(x.rh==x.len?rh:0);
		return res;
	}
};

struct Seg
{
	Node val[N*4];
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			val[x].lh=(b[l]>=0);
			val[x].rh=(b[l]>=0);
			val[x].len=1;
			val[x].sum=(b[l]>=0);
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		val[x]=val[lc]+val[rc];
	}
	void update(int x,int l,int r,int p)
	{
		if(l==r)
		{
			val[x].lh=(b[l]>=0);
			val[x].rh=(b[l]>=0);
			val[x].len=1;
			val[x].sum=(b[l]>=0);
			return;
		}
		if(p<=mid) update(lc,l,mid,p);
		else update(rc,mid+1,r,p);
		val[x]=val[lc]+val[rc];
	}
	Node query(int x,int l,int r,int L,int R)
	{
		if(L>R) return (Node){0,0,0,0};
		if(L<=l&&r<=R) return val[x];
		if(L<=mid&&mid+1<=R)
			return query(lc,l,mid,L,R)+query(rc,mid+1,r,L,R);
		else if(L<=mid) return query(lc,l,mid,L,R);
		else return query(rc,mid+1,r,L,R);
	}
}sum;

signed main()
{
	n=read();q=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	if(n==1)
	{
		while(q--)
		{
			int opt=read();
			if(opt==1)
			{
				int x=read(),y=read();a[x]=y;
				//if(x!=1) b[x]=a[x]-a[x-1],sum.update(1,2,n,x);
				//if(x!=n) b[x+1]=a[x+1]-a[x],sum.update(1,2,n,x+1);
			}
			else
			{
				int l=read(),r=read();
				printf("1\n");
			}
		}
		return 0;
	}
	for(int i=2;i<=n;++i)
		b[i]=a[i]-a[i-1];
	sum.build(1,2,n);
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read(),y=read();a[x]=y;
			if(x!=1) b[x]=a[x]-a[x-1],sum.update(1,2,n,x);
			if(x!=n) b[x+1]=a[x+1]-a[x],sum.update(1,2,n,x+1);
		}
		else
		{
			int l=read(),r=read();
			Node res=sum.query(1,2,n,l+1,r);
			printf("%lld\n",res.sum+r-l+1);
		}
	}
	return 0;
}