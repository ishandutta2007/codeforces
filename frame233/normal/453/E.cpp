// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
struct seg_tr{
	int ls[N<<6],rs[N<<6],node_cnt;
	ll sum0[N<<6],sum1[N<<6];
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		ls[cur]=build(l,mid),rs[cur]=build(mid+1,r);
		return cur;
	}
	void Update(int &cur,int type,int pos,int C,int l,int r)
	{
		int tmp=++node_cnt;
		ls[tmp]=ls[cur],rs[tmp]=rs[cur],sum1[tmp]=sum1[cur],sum0[tmp]=sum0[cur],cur=tmp;
		(type?sum1[cur]:sum0[cur])+=C;
		if(l==r) return;
		int mid=(l+r)>>1;
		pos<=mid?Update(ls[cur],type,pos,C,l,mid):Update(rs[cur],type,pos,C,mid+1,r);
	}
	ll Query(int L,int R,int type,int u,int v,int l,int r)
	{
		if(L<=l&&r<=R) return type?sum1[v]-sum1[u]:sum0[v]-sum0[u];
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid) return Query(L,R,type,ls[u],ls[v],l,mid)+Query(L,R,type,rs[u],rs[v],mid+1,r);
		return L<=mid?Query(L,R,type,ls[u],ls[v],l,mid):Query(L,R,type,rs[u],rs[v],mid+1,r);
	}
}tr;
int s[N],m[N],r[N],root[N];
struct frac{
	ll a,b;
	inline bool operator == (const frac &o)const{return a*o.b==o.a*b;}
	inline bool operator < (const frac &o)const{return a*o.b<o.a*b;}
}T[N];
struct node{
	int l,r;
	mutable int t;
	inline bool operator < (const node &o)const{return l<o.l;}
};
std::set<node> S;
std::set<node>::iterator split(int x)
{
	auto it=S.lower_bound({x,x,0});
	if(it!=S.end()&&it->l==x) return it;
	node val=*--it;
	if(val.r<x) return S.end();
	return S.erase(it),S.insert({val.l,x-1,val.t}),S.insert({x,val.r,val.t}).first;
}
int main()
{
	int n;read(n);
	int pos=0;
	for(int i=1;i<=n;++i) read(s[i],m[i],r[i]),T[++pos]={m[i],r[i]};
	std::sort(T+1,T+pos+1),pos=std::unique(T+1,T+pos+1)-T-1;
	root[0]=tr.build(1,pos);
	for(int i=1;i<=n;++i)
	{
		int id=std::lower_bound(T+1,T+pos+1,(frac){m[i],r[i]})-T;
		root[i]=root[i-1],tr.Update(root[i],0,id,r[i],1,pos),tr.Update(root[i],1,id,m[i],1,pos);
	}
	for(int i=1;i<=n;++i) S.insert({i,i,-1});
	int q;read(q);
	while(q--)
	{
		int t,l,r;read(t,l,r);
		auto itr=split(r+1),itl=split(l);
		ll ans=0;
		for(auto it=itl;it!=itr;++it)
		{
			if(it->t==-1) ans+=min(s[it->l]+1LL*t*::r[it->l],(ll)m[it->l]),it->t=0,s[it->l]=0;
			else
			{
				int cur=t-it->t,p=std::upper_bound(T+1,T+pos+1,(frac){cur,1})-T-1;
				if(1<=p) ans+=tr.Query(1,p,1,root[it->l-1],root[it->r],1,pos);
				if(p<pos) ans+=tr.Query(p+1,pos,0,root[it->l-1],root[it->r],1,pos)*cur;
			}
		}
		S.erase(itl,itr),S.insert({l,r,t});
		printf("%lld\n",ans);
	}
	return 0;
}