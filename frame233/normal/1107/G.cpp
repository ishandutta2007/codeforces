// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

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
int d[N];
int c[N];
struct Pair{
	ll maxl,maxr,maxx,sum;
};
struct seg_tr{
	struct node{
		int ls,rs;
		ll maxl,maxr,maxx,sum;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].maxl=max(f[f[x].ls].maxl,f[f[x].ls].sum+f[f[x].rs].maxl);
		f[x].maxr=max(f[f[x].rs].maxr,f[f[x].rs].sum+f[f[x].ls].maxr);
		f[x].maxx=max(max(f[f[x].ls].maxx,f[f[x].rs].maxx),f[f[x].ls].maxr+f[f[x].rs].maxl);
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].maxl=f[cur].maxr=f[cur].maxx=f[cur].sum=c[l];
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	Pair Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			return (Pair){f[cur].maxl,f[cur].maxr,f[cur].maxx,f[cur].sum};
		}
		int mid=(l+r)>>1;
		if(L>mid)
		{
			return Query(L,R,mid+1,r,f[cur].rs);
		}
		else if(R<=mid)
		{
			return Query(L,R,l,mid,f[cur].ls);
		}
		else
		{
			Pair Lt=Query(L,R,l,mid,f[cur].ls),Rt=Query(L,R,mid+1,r,f[cur].rs);
			return (Pair)
			{
				max(Lt.maxl,Lt.sum+Rt.maxl),
				max(Rt.maxr,Rt.sum+Lt.maxr),
				max(max(Lt.maxx,Rt.maxx),Lt.maxr+Rt.maxl),
				Lt.sum+Rt.sum
			};
		}
	}
}tr;
int st[N],top;
int L[N],R[N];
int main()
{
	int n,a;
	read(n,a);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		read(d[i],c[i]);
		chmax(ans,(ll)(a-c[i]));
		c[i]=a-c[i];
	}
	for(int i=1;i<n;++i)
	{
		d[i]=d[i+1]-d[i];
	}
	tr.build(1,n);
	for(int i=1;i<n;++i)
	{
		while(top&&d[st[top]]<=d[i]) --top;
		L[i]=st[top]+1;
		st[++top]=i;
	}
	top=0;
	for(int i=n-1;i>=1;--i)
	{
		while(top&&d[st[top]]<=d[i]) --top;
		R[i]=!top?n-1:st[top]-1;
		st[++top]=i;
	}
	for(int i=1;i<n;++i)
	{
		ll tmp=tr.Query(L[i],R[i]+1,1,n,1).maxx;
		chmax(ans,tmp-1ll*d[i]*d[i]);
	}
	printf("%lld\n",ans);
	return 0;
}