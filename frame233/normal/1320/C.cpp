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

const int N=200005;
const int MAXN=1000005;
ll a[N],ca[N];
ll b[N],cb[N];
ll B[MAXN],A[MAXN];
struct seg_tr{
	struct Node{
		int ls,rs;
		ll maxx,tag;
	}f[MAXN<<1];
	int node_cnt;
	Finline seg_tr(){f[0].maxx=-1e18;}
	Finline void PushUp(int x)
	{
		f[x].maxx=max(f[f[x].ls].maxx,f[f[x].rs].maxx);
	}
	Finline void add(int cur,ll C)
	{
		f[cur].maxx+=C;
		f[cur].tag+=C;
	}
	Finline void PushDown(int cur)
	{
		if(f[cur].tag)
		{
			add(f[cur].ls,f[cur].tag);
			add(f[cur].rs,f[cur].tag);
			f[cur].tag=0;
		}
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].maxx=-B[l];
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update(int L,int R,int l,int r,int cur,int C)
	{
		if(L<=l&&r<=R)
		{
			add(cur,C);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,C);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,C);
		PushUp(cur);
	}
	ll Query(){return f[1].maxx;}
}tr;
struct node{
	int a,b;
};
std::vector<node> v[MAXN];
int main()
{
	memset(A,63,sizeof(A));
	memset(B,63,sizeof(B));
	int n,m,p;
	read(n,m,p);
	ll minn1=1e18,minn2=1e18;
	for(int i=1;i<=n;++i) read(a[i],ca[i]),chmin(minn1,ca[i]),chmin(A[a[i]],ca[i]);
	for(int i=1;i<=m;++i) read(b[i],cb[i]),chmin(B[b[i]],cb[i]),chmin(minn2,cb[i]);
	ll ans=-(minn1+minn2);
	int x,y,z;
	for(int i=1;i<=p;++i)
	{
		read(x,y,z);
		v[x].push_back((node){y,z});
	}
	tr.build(1,1000001);
	for(int i=1;i<=1000000;++i)
	{
		chmax(ans,-A[i]+tr.Query());
		for(auto it:v[i])
		{
			tr.Update(it.a+1,1000001,1,1000001,1,it.b);
		}
	}
	printf("%lld\n",ans);
	return 0;
}