// Author -- Frame

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

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
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
const int S=1600;
int a[N],n;
struct qry{
	int r,id;
};
std::vector<qry> v[N];
struct BIT{
	int c[N];
	Finline void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
int ans[N];
struct node{
	int val,id;
	Finline bool operator < (const node &o)const
	{
		return val==o.val?id>o.id:val<o.val;
	}
};
struct seg_tr{
	struct Node{
		int ls,rs;
		node val;
		int tag;
	}f[N<<1];
	int node_cnt;
	Finline void pushup(int x)
	{
		f[x].val=min(f[f[x].ls].val,f[f[x].rs].val);
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].val=(node){inf,l};
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		pushup(cur);
		return cur;
	}
	Finline void upd(int cur,int C)
	{
		f[cur].val.val-=C;
		f[cur].tag+=C;
	}
	Finline void pushdown(int cur)
	{
		if(f[cur].tag)
		{
			upd(f[cur].ls,f[cur].tag);
			upd(f[cur].rs,f[cur].tag);
			f[cur].tag=0;
		}
	}
	void Update(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			upd(cur,1);
			return;
		}
		pushdown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	void Modify(int pos,int val,int l,int r,int cur)
	{
		if(l==r)
		{
			f[cur].val.val=val;
			return;
		}
		pushdown(cur);
		int mid=(l+r)>>1;
		if(pos<=mid) Modify(pos,val,l,mid,f[cur].ls);
		else Modify(pos,val,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	Finline node Query(){return f[1].val;}
}__;
int main()
{
	memset(a,255,sizeof(a));
	int q;read(n,q);
	for(int i=1;i<=n;++i) read(a[i]),a[i]=i-a[i];
	int l,r;
	for(int i=1;i<=q;++i)
	{
		read(l,r);
		v[l+1].pb((qry){n-r,i});
	}
	__.build(1,n);
	for(int i=n;i>=1;--i)
	{
		if(a[i]>=0) __.Modify(i,a[i],1,n,1);
		while(true)
		{
			node tmp=__.Query();
			if(tmp.val==0)
			{
				int pos=tmp.id;
				__.Update(pos,n,1,n,1);
				__.Modify(pos,inf,1,n,1);
				tr.add(pos,1);
			}
			else break;
		}
		for(auto it:v[i]) ans[it.id]=tr.sum(it.r);
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}