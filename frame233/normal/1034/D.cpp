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

const int N=300005;
const int LIMIT=1e9+1;
struct BIT1{
	ll c[N];
	void add(int x,ll C){++x;for(;x;x-=lowbit(x))c[x]+=C;}
	ll sum(int x){++x;ll ans=0;for(;x<N;x+=lowbit(x))ans+=c[x];return ans;}
}tr1;
struct BIT2{
	ll c[N];
	void add(int x,ll C){++x;for(;x<N;x+=lowbit(x))c[x]+=C;}
	ll sum(int x){++x;ll ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr2;
struct node{
	int l,r,id;
	Finline bool operator < (const node &o)const
	{
		return l<o.l;
	}
};
std::set<node> S;
int n,k;
int L[N],R[N];
std::set<node>::iterator split(int x)
{
	auto it=--S.upper_bound((node){x,0,0});
	if(it->l==x) return it;
	node val=*it;S.erase(it);
	S.insert((node){val.l,x,val.id});
	return S.insert((node){x,val.r,val.id}).first;
}
struct Node{
	int pos,val;
};
std::vector<Node> v[N];
void init()
{
	S.insert((node){1,LIMIT,0});
	for(int i=1;i<=n;++i)
	{
		int l=L[i],r=R[i];
		auto itr=split(r);
		auto itl=split(l);
		for(auto it=itl;it!=itr;++it) v[i].pb((Node){it->id,it->l-it->r});
		S.erase(itl,itr);
		S.insert((node){l,r,i});
	}
}
int a[N];
ll calc(int mid)
{
	memset(tr1.c,0,sizeof(tr1.c));
	memset(a,0,sizeof(a));
	int pos=0;
	ll ans=0,sum=0;
	for(int i=1;i<=n;++i)
	{
		for(auto it:v[i])
		{
			a[it.pos]+=it.val;
			if(it.pos>=pos) sum+=it.val;
		}
		a[i]+=R[i]-L[i];
		sum+=R[i]-L[i];
		while(pos<i&&sum-a[pos]>=mid) sum-=a[pos++];
		ans+=pos;
	}
	return ans;
}
ll solve(int mid)
{
	memset(tr1.c,0,sizeof(tr1.c));
	memset(tr2.c,0,sizeof(tr2.c));
	int pos=0;
	ll ans=0,res=0;
	for(int i=1;i<=n;++i)
	{
		int l=L[i],r=R[i];
		for(auto it:v[i]) tr1.add(it.pos,it.val),tr2.add(it.pos,1ll*it.pos*it.val);
		tr1.add(i,r-l),tr2.add(i,1ll*i*(r-l));
		while(pos<i&&tr1.sum(pos+1)>=mid) ++pos;
		ans+=pos;
		res+=tr2.sum(pos)+1ll*pos*tr1.sum(pos+1);
	}
	res-=1ll*(ans-k)*mid;
	return res;
}
int main()
{
	read(n,k);
	for(int i=1;i<=n;++i) read(L[i],R[i]);
	init();
	int l=1,r=1e9;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(calc(mid)>=k) l=mid;
		else r=mid-1;
	}
	printf("%lld\n",solve(l));
	return 0;
}