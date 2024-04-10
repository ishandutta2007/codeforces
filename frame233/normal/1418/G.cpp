// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=500005;
struct node{
	int a,b;
	Finline void merge(const node &o)
	{
		if(o.a>a) *this=o;
		else if(o.a==a) b+=o.b;
	}
};
struct seg_tr{
	struct Node{
		int ls,rs;
		node val;
		int tag;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val=f[f[x].ls].val;
		f[x].val.merge(f[f[x].rs].val);
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].val.b=1;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	Finline void Upd(int cur,int C)
	{
		f[cur].tag+=C;
		f[cur].val.a+=C;
	}
	Finline void PushDown(int cur)
	{
		if(f[cur].tag)
		{
			Upd(f[cur].ls,f[cur].tag);
			Upd(f[cur].rs,f[cur].tag);
			f[cur].tag=0;
		}
	}
	void Update(int L,int R,int l,int r,int cur,int C)
	{
		if(L>R||!L) return;
		if(L<=l&&r<=R)
		{
			Upd(cur,C);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,C);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,C);
		PushUp(cur);
	}
	node Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return f[cur].val;
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			node val(Query(L,R,l,mid,f[cur].ls));
			val.merge(Query(L,R,mid+1,r,f[cur].rs));
			return val;
		}
		if(L<=mid) return Query(L,R,l,mid,f[cur].ls);
		return Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
int nxt[N],qwq[N],a[N];
int __[N];
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i) read(a[i]),nxt[i]=qwq[a[i]],qwq[a[i]]=i;
	std::fill(qwq+1,qwq+n+1,n+1);
	for(int i=n;i>=1;--i) __[i]=qwq[a[i]],qwq[a[i]]=i;
	tr.build(1,n);
	for(int i=1;i<=n;++i) tr.Update(1,qwq[i]-1,1,n,1,1);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		tr.Update(nxt[i]+1,i-1,1,n,1,-1);
		tr.Update(i+1,__[i]-1,1,n,1,1);
		tr.Update(nxt[nxt[nxt[nxt[i]]]]+1,nxt[nxt[nxt[i]]],1,n,1,-1);
		tr.Update(nxt[nxt[nxt[i]]]+1,nxt[nxt[i]],1,n,1,1);
		node val=tr.Query(1,i,1,n,1);
		if(val.a==n) ans+=val.b;
	}
	printf("%lld\n",ans);
	return 0;
}