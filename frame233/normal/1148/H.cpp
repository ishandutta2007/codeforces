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

const int N=200005;
int n;
struct seg_tr1{
	struct Node{
		int ls,rs;
		int minn;
	}f[N<<1];
	int node_cnt;
	Finline void pushup(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
	}
	int build(int l=0,int r=n+1)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int pos,int C,int l=0,int r=n+1,int cur=1)
	{
		if(l==r) return (void)(f[cur].minn=C);
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,C,l,mid,f[cur].ls);
		else Update(pos,C,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	int Query(int L,int R,int l=0,int r=n+1,int cur=1)
	{
		if(L<=l&&r<=R) return f[cur].minn;
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid) return min(Query(L,R,l,mid,f[cur].ls),Query(L,R,mid+1,r,f[cur].rs));
		return L<=mid?Query(L,R,l,mid,f[cur].ls):Query(L,R,mid+1,r,f[cur].rs);
	}
	int find(int L,int tar,int l=0,int r=n+1,int cur=1)
	{
		if(l==r) return f[cur].minn<tar?l:n+1;
		int mid=(l+r)>>1;
		if(L<=l)
		{
			if(f[f[cur].ls].minn<tar) return find(L,tar,l,mid,f[cur].ls);
			return find(L,tar,mid+1,r,f[cur].rs);
		}
		if(L<=mid)
		{
			int tmp=find(L,tar,l,mid,f[cur].ls);
			return tmp<n+1?tmp:find(L,tar,mid+1,r,f[cur].rs);
		}
		return find(L,tar,mid+1,r,f[cur].rs);
	}
}tr1;
int root[N];
struct seg_tr2{
	struct Node{
		int ls,rs;
		ll k,b;
	}f[N*150];
	int node_cnt;
	int build(int l=0,int r=n+1)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	int Update(int L,int R,int l,int r,int rt,ll k,ll b)
	{
		int cur=++node_cnt;
		f[cur]=f[rt];
		if(L<=l&&r<=R)
		{
			f[cur].k+=k,f[cur].b+=b;
			return cur;
		}
		int mid=(l+r)>>1;
		if(L<=mid) f[cur].ls=Update(L,R,l,mid,f[rt].ls,k,b);
		if(R>mid) f[cur].rs=Update(L,R,mid+1,r,f[rt].rs,k,b);
		return cur;
	}
	ll Query(int pos,int l,int r,int cur,int i)
	{
		ll res=f[cur].k*i+f[cur].b;
		if(l==r) return res;
		int mid=(l+r)>>1;
		return res+(pos<=mid?Query(pos,l,mid,f[cur].ls,i):Query(pos,mid+1,r,f[cur].rs,i));
	}
	ll Query(int pos,int l,int r,int cur)
	{
		ll res=f[cur].k;
		if(l==r) return res;
		int mid=(l+r)>>1;
		return res+(pos<=mid?Query(pos,l,mid,f[cur].ls):Query(pos,mid+1,r,f[cur].rs));
	}
	Finline ll QueryG(int i,int k){return Query(k,0,n+1,root[i]);}
	Finline ll QuerySum(int i,int k){return Query(k,0,n+1,root[i],i);}
}tr2;
void Update(int id,int val)
{
	root[id]=root[id-1];
	tr1.Update(val,id);
	int pos=val+1;
	while(pos<=n+1)
	{
		int orig=tr2.QueryG(id-1,pos),cur=tr1.Query(0,pos-1);
		if(orig==cur) break;
		int nxt=tr1.find(pos,cur);
		root[id]=tr2.Update(pos,nxt,0,n+1,root[id],cur-orig,1ll*(id-1)*(orig-cur));
		pos=nxt+1;
	}
}
Finline ll f(ll x){return 1ll*x*(x+1)>>1;}
Finline ll calc(int L,int R,int k)
{
	if(!k) return (f(R)-f(L-1));
	int l=L-1,r=R;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(tr2.QueryG(mid,k)<L) l=mid;
		else r=mid-1;
	}
	return tr2.QuerySum(R,k)-tr2.QuerySum(l,k)+1ll*(L-1)*(l-(L-1));
}
Finline ll Query(int l,int r,int k)
{
	return calc(l,r,k)-calc(l,r,k+1);
}
int main()
{
	read(n);
	int x,l,r,k;
	ll lastans=0;
	tr1.build();
	root[0]=tr2.build();
	for(int i=1;i<=n;++i)
	{
		read(x,l,r,k);
		x=(x+lastans)%(n+1),l=(l+lastans)%i+1,r=(r+lastans)%i+1,k=(k+lastans)%(n+1);
		if(l>r) std::swap(l,r);
		Update(i,x);
		printf("%lld\n",lastans=Query(l,r,k));
	}
	return 0;
}