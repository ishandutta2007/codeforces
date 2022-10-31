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
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
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

const int N=300005;
const int mod=1000000007;
const ll inv2=500000004;
struct matrix{
	ll a,b,c,d,e,f;
	Finline matrix operator * (const matrix &o)const
	{
		return (matrix){a*o.a%mod,(b*o.a+c*o.b)%mod,c*o.c%mod,(d*o.a+e*o.b+f*o.d)%mod,(e*o.c+f*o.e)%mod,f*o.f%mod};
	}
}I;
Finline matrix get1(ll x)
{
	return (matrix){1ll,x*inv2%mod,inv2,0,x*inv2%mod,1ll};
}
Finline matrix get2(ll x)
{
	return (matrix){1ll,mod-x,2ll,(x*x)%mod*inv2%mod,mod-x,1ll};
}
int t[N<<1];
int a[N];
int b[N<<1];
struct seg_tr{
	struct Node{
		int ls,rs;
		matrix val;
	}f[N<<2];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val=f[f[x].ls].val*f[f[x].rs].val;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			matrix res(I),a=get1(t[l]);
			while(b[l]) res=res*a,--b[l];
			f[cur].val=res;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update1(int l,int r,int pos,int cur)
	{
		if(l==r)
		{
			f[cur].val=f[cur].val*get1(t[l]);
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update1(l,mid,pos,f[cur].ls);
		else Update1(mid+1,r,pos,f[cur].rs);
		PushUp(cur);
	}
	void Update2(int l,int r,int pos,int cur)
	{
		if(l==r)
		{
			f[cur].val=f[cur].val*get2(t[l]);
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update2(l,mid,pos,f[cur].ls);
		else Update2(mid+1,r,pos,f[cur].rs);
		PushUp(cur);
	}
	Finline ll Query(){return f[1].val.d;}
}tr;
int Q[N][2];
int main()
{
	I=(matrix){1ll,0ll,1ll,0ll,0ll,1ll};
	int n;
	read(n);
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		t[++pos]=a[i];
	}
	int q;
	read(q);
	for(int i=1;i<=q;++i)
	{
		read(Q[i][0],Q[i][1]);
		t[++pos]=Q[i][1];
	}
	std::sort(t+1,t+pos+1);
	pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=std::lower_bound(t+1,t+pos+1,a[i])-t;
		++b[a[i]];
	}
	tr.build(1,pos);
	printf("%lld\n",tr.Query());
	for(int i=1;i<=q;++i)
	{
		Q[i][1]=std::lower_bound(t+1,t+pos+1,Q[i][1])-t;
		tr.Update2(1,pos,a[Q[i][0]],1);
		tr.Update1(1,pos,Q[i][1],1);
		a[Q[i][0]]=Q[i][1];
		printf("%lld\n",tr.Query());
	}
	return 0;
}