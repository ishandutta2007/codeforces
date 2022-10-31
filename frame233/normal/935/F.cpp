// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=1e18;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=100005;
struct Pair{
	ll left,right;
}b[N];
ll a[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		ll maxx;
		Finline Node():maxx(-INF){}
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].maxx=max(f[f[x].ls].maxx,f[f[x].rs].maxx);
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].maxx=min(b[l].left,0ll)+min(b[l].right,0ll);
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update(const int &pos,const int &l,const int &r,const int &cur,const Pair &val)
	{
		if(l==r)
		{
			f[cur].maxx=min(val.left,0ll)+min(val.right,0ll);
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,val);
		else Update(pos,mid+1,r,f[cur].rs,val);
		PushUp(cur);
	}
	ll Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].maxx;
		}
		int mid=(l+r)>>1;
		return max(L<=mid?Query(L,R,l,mid,f[cur].ls):-INF,R>mid?Query(L,R,mid+1,r,f[cur].rs):-INF);
	}
}tr;
int main()
{
	int n;
	read(n);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	for(int i=2;i<=n;++i)
	{
		ans+=abs(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;++i)
	{
		b[i].left=a[i]-a[i-1];
		b[i].right=a[i]-a[i+1];
	}
	b[1].left=-inf,b[n].right=-inf;
	int root=tr.build(1,n);
	int _;
	ll tmp;
	read(_);
	int opt,l,r;
	ll x;
	while(_--)
	{
		read(opt,l,r,x);
		if(opt==1)
		{
			if(l!=r)
			{
				ll t=-INF;
				if(l==1)
				{
					chmax(t,-abs(b[1].right)+abs(b[1].right+x));
					++l;
				}
				if(r==n)
				{
					chmax(t,-abs(b[n].left)+abs(b[n].left+x));
					--r;
				}
				tmp=tr.Query(l,r,1,n,root);
				if(tmp==0)
				{
					printf("%lld\n",ans+max(t,(x<<1)));
				}
				else
				{
					printf("%lld\n",ans+max(t,x+2*max(-x,tmp)+x));
				}
			}
			else
			{
				if(l==1)
				{
					printf("%lld\n",ans-abs(b[1].right)+abs(b[1].right+x));
				}
				else if(r==n)
				{
					printf("%lld\n",ans-abs(b[n].left)+abs(b[n].left+x));
				}
				else
				{
					printf("%lld\n",ans+abs(b[l].left+x)+abs(b[l].right+x)-abs(b[l].left)-abs(b[l].right));
				}
			}
		}
		else
		{
			if(l>1)
			{
				ans+=-abs(b[l].left)+abs(b[l].left+x);
			}
			if(r<n)
			{
				ans+=-abs(b[r].right)+abs(b[r].right+x);
			}
			b[l].left+=x;
			b[l-1].right-=x;
			b[r].right+=x;
			b[r+1].left-=x;
			
			tr.Update(l,1,n,root,b[l]);
			if(l>1) tr.Update(l-1,1,n,root,b[l-1]);
			tr.Update(r,1,n,root,b[r]);
			if(r<n) tr.Update(r+1,1,n,root,b[r+1]);
		}
	}
    return 0;
}