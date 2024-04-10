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
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
const ll pw[10]={1,42,1764,74088,3111696,130691232,5489031744,230539333248,9682651996416,406671383849472};
int a[N];
inline ll calc(ll x)
{
	for(int i=0;i<10;++i) if(pw[i]>=x) return pw[i]-x;
	return -1;
}
struct seg_tr{
	struct Node{
		int ls,rs;
		ll val,tag,cov;
		ll minn,TAG,COV;
	}f[N<<1];
	int node_cnt;
	inline void pushup(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
		f[x].val=(f[f[x].ls].val==-1||f[f[x].rs].val==-1||f[f[x].ls].val!=f[f[x].rs].val)?-1:f[f[x].ls].val;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].COV=-1;
		if(l==r)
		{
			f[cur].val=a[l];
			f[cur].minn=calc(a[l]);
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid),f[cur].rs=build(mid+1,r);
		return pushup(cur),cur;
	}
	inline void upd(int cur,ll C)
	{
		f[cur].tag+=C;
		if(~f[cur].val) f[cur].val+=C;
	}
	inline void cover(int cur,ll C)
	{
		f[cur].tag=0;
		f[cur].val=C,f[cur].cov=C;
	}
	inline void UPD(int cur,ll C)
	{
		f[cur].TAG+=C;
		f[cur].minn-=C;
	}
	inline void COVER(int cur,ll C)
	{
		f[cur].TAG=0;
		f[cur].minn=C,f[cur].COV=C;
	}
	inline void pushdown(int cur)
	{
		if(f[cur].cov) cover(f[cur].ls,f[cur].cov),cover(f[cur].rs,f[cur].cov),f[cur].cov=0;
		if(f[cur].tag) upd(f[cur].ls,f[cur].tag),upd(f[cur].rs,f[cur].tag),f[cur].tag=0;
		if(~f[cur].COV) COVER(f[cur].ls,f[cur].COV),COVER(f[cur].rs,f[cur].COV),f[cur].COV=-1;
		if(f[cur].TAG) UPD(f[cur].ls,f[cur].TAG),UPD(f[cur].rs,f[cur].TAG),f[cur].TAG=0;
	}
	void Update(int L,int R,int C,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			if(C<=f[cur].minn) upd(cur,C),UPD(cur,C);
			else
			{
				if(~f[cur].val) upd(cur,C),COVER(cur,calc(f[cur].val));
				else
				{
					pushdown(cur);
					int mid=(l+r)>>1;
					Update(L,R,C,l,mid,f[cur].ls);
					Update(L,R,C,mid+1,r,f[cur].rs);
					pushup(cur);
				}
			}
			return;
		}
		pushdown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,C,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,C,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	void Modify(int L,int R,int C,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return cover(cur,C),COVER(cur,calc(C));
		pushdown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Modify(L,R,C,l,mid,f[cur].ls);
		if(R>mid) Modify(L,R,C,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	ll Query(int pos,int l,int r,int cur)
	{
		if(l==r) return f[cur].val;
		pushdown(cur);
		int mid=(l+r)>>1;
		if(pos<=mid) return Query(pos,l,mid,f[cur].ls);
		return Query(pos,mid+1,r,f[cur].rs);
	}
}tr;
int main()
{
	int n,q;read(n,q);
	for(int i=1;i<=n;++i) read(a[i]);
	tr.build(1,n);
	int opt,x,y,z;
	while(q--)
	{
		read(opt);
		if(opt==1) read(x),printf("%lld\n",tr.Query(x,1,n,1));
		else if(opt==2) read(x,y,z),tr.Modify(x,y,z,1,n,1);
		else
		{
			read(x,y,z);
			tr.Update(x,y,z,1,n,1);
			while(tr.f[1].minn==0) tr.Update(x,y,z,1,n,1);
		}
	}
	return 0;
}