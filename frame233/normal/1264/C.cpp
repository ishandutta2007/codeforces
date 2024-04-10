// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
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
template <typename _Tp>Finline void read(_Tp &x)
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

const int N=200005;
const int mod=998244353;
const int inv100=828542813;
ll ksm(ll a,int b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
struct matrix{
	ll a,b,c,d;
	Finline matrix operator * (const matrix &o)const
	{
		return (matrix){(a*o.a+b*o.c)%mod,(a*o.b+b*o.d)%mod,(c*o.a+d*o.c)%mod,(c*o.b+d*o.d)%mod};
	}
	Finline ll get()
	{
		return c*ksm(d)%mod;
	}
};
ll a[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		matrix mul;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].mul=f[f[x].ls].mul*f[f[x].rs].mul;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].mul=(matrix){1,0,1,a[l]};
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update(int pos,int l,int r,int cur,int val)
	{
		if(l==r)
		{
			f[cur].mul=(matrix){1,0,1,val};
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,val);
		else Update(pos,mid+1,r,f[cur].rs,val);
		PushUp(cur);
	}
	matrix Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].mul;
		}
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			return Query(L,R,l,mid,f[cur].ls)*Query(L,R,mid+1,r,f[cur].rs);
		}
		if(L<=mid) return Query(L,R,l,mid,f[cur].ls);
		return Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
std::set<int> S;
Finline void add(ll &a,int b){(a+=b)>=mod&&(a-=mod);}
Finline void sub(ll &a,int b){(a-=b)<0&&(a+=mod);}
bool used[N];
int main()
{
	int n,q;
	read(n,q);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		a[i]=a[i]*inv100%mod;
	}
	int root=tr.build(1,n);
	S.insert(1);
	S.insert(n+1);
	ll ans=tr.Query(1,n,1,n,root).get();
	int x;
	while(q--)
	{
		read(x);
		if(!used[x])
		{
			std::set<int>::iterator itr=S.upper_bound(x);
			std::set<int>::iterator itl=itr;
			--itl;
			sub(ans,tr.Query(*itl,*itr-1,1,n,root).get());
			add(ans,tr.Query(*itl,x-1,1,n,root).get());
			add(ans,tr.Query(x,*itr-1,1,n,root).get());
			S.insert(x);
		}
		else
		{
			S.erase(x);
			std::set<int>::iterator itr=S.upper_bound(x);
			std::set<int>::iterator itl=itr;
			--itl;
			sub(ans,tr.Query(*itl,x-1,1,n,root).get());
			sub(ans,tr.Query(x,*itr-1,1,n,root).get());
			add(ans,tr.Query(*itl,*itr-1,1,n,root).get());
		}
		used[x]^=1;
		printf("%lld\n",ans);
	}
    return 0;
}