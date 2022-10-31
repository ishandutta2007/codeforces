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

const int N=200005;
int a[N],n;
struct seg_tr{
	struct Node{
		int ls,rs;
		int minn,tag;
		ll sum;
	}f[N<<1];
	int node_cnt;
	inline void pushup(int x){f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum,f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return f[cur].sum=f[cur].minn=a[l],cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid),f[cur].rs=build(mid+1,r);
		return pushup(cur),cur;
	}
	inline void upd(int cur,int l,int r,int C){f[cur].minn=C,f[cur].sum=1LL*(r-l+1)*C,f[cur].tag=C;}
	inline void pushdown(int cur,int l,int r){int mid=(l+r)>>1;if(f[cur].tag)upd(f[cur].ls,l,mid,f[cur].tag),upd(f[cur].rs,mid+1,r,f[cur].tag),f[cur].tag=0;}
	void Update(int L,int R,int C,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return upd(cur,l,r,C);
		pushdown(cur,l,r);int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,C,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,C,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	ll Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return f[cur].sum;
		pushdown(cur,l,r);int mid=(l+r)>>1;
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
	int query1(int C,int l,int r,int cur)
	{
		if(l==r) return f[cur].minn<=C?l:n+1;
		pushdown(cur,l,r);int mid=(l+r)>>1;
		if(f[f[cur].ls].minn<=C) return query1(C,l,mid,f[cur].ls);
		return query1(C,mid+1,r,f[cur].rs);
	}
	int query2(ll C,int l,int r,int cur)
	{
		if(l==r) return C>=f[cur].sum?n+1:l;
		pushdown(cur,l,r);int mid=(l+r)>>1;
		if(C>=f[f[cur].ls].sum) return query2(C-f[f[cur].ls].sum,mid+1,r,f[cur].rs);
		return query2(C,l,mid,f[cur].ls);
	}
}tr;
int main()
{
	int q;read(n,q);
	for(int i=1;i<=n;++i) read(a[i]);
	tr.build(1,n);
	int opt,x,y;
	while(q--)
	{
		read(opt,x,y);
		if(opt==1)
		{
			int pos=tr.query1(y,1,n,1);
			if(pos<=x) tr.Update(pos,x,y,1,n,1);
		}
		else
		{
			int ans=0;
			while(y)
			{
				int pos=max(x,tr.query1(y,1,n,1));
				if(pos>n) break;
				ll pre=pos>1?tr.Query(1,pos-1,1,n,1):0;
				int nxt=tr.query2(pre+y,1,n,1);
				y-=tr.Query(pos,nxt-1,1,n,1);
				ans+=nxt-pos;
				if(nxt>n) break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}