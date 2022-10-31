// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<bitset>
#include<queue>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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
 
const int N=500005;
struct seg_tr{
	struct node{
		int ls,rs;
		int cnt;
		ll sum;
		bool tag;
	}f[N<<5];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].cnt=f[f[x].ls].cnt+f[f[x].rs].cnt;
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	Finline void cover(int cur)
	{
		if(!cur) return;
		f[cur].cnt=0;
		f[cur].sum=0;
		f[cur].tag=1;
	}
	Finline void PushDown(int cur)
	{
		if(f[cur].tag)
		{
			cover(f[cur].ls);
			cover(f[cur].rs);
			f[cur].tag=0;
		}
	}
	void Update(int l,int r,int &cur,int pos,int val)
	{
		if(!cur)
		{
			cur=++node_cnt;
		}
		if(l==r)
		{
			f[cur].sum+=1ll*pos*val;
			f[cur].cnt+=val;
			return;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		if(pos<=mid) Update(l,mid,f[cur].ls,pos,val);
		else Update(mid+1,r,f[cur].rs,pos,val);
		PushUp(cur);
	}
	void Modify(int L,int R,int l,int r,int cur)
	{
		if(!cur) return;
		if(L<=l&&r<=R)
		{
			cover(cur);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Modify(L,R,l,mid,f[cur].ls);
		if(R>mid) Modify(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	int Query1(int L,int R,int l,int r,int cur)
	{
		if(!cur) return 0;
		if(L<=l&&r<=R)
		{
			return f[cur].cnt;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		return (L<=mid?Query1(L,R,l,mid,f[cur].ls):0)+(R>mid?Query1(L,R,mid+1,r,f[cur].rs):0);
	}
	Finline ll Query(){return f[1].sum;}
}tr;
const int MAXX=1000000001;
int a[N];
ll val1[N],val2[N];
int res[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	int root=0;
	for(int i=1;i<=n;++i)
	{
		int cnt=tr.Query1(a[i]+1,MAXX,1,MAXX,root);
		tr.Modify(a[i]+1,MAXX,1,MAXX,root);
		tr.Update(1,MAXX,root,a[i],cnt+1);
		val1[i]=tr.Query();
	}
	tr.Modify(1,MAXX,1,MAXX,root);
	for(int i=n;i>=1;--i)
	{
		int cnt=tr.Query1(a[i]+1,MAXX,1,MAXX,root);
		tr.Modify(a[i]+1,MAXX,1,MAXX,root);
		tr.Update(1,MAXX,root,a[i],cnt+1);
		val2[i]=tr.Query();
	}
	ll ans=-1;
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		if(val1[i]+val2[i]-a[i]>ans)
		{
			ans=val1[i]+val2[i]-a[i];
			pos=i;
		}
	}
	int qwq=a[pos];
	for(int i=pos;i>=1;--i)
	{
		chmin(qwq,a[i]);
		res[i]=qwq;
	}
	qwq=a[pos];
	for(int i=pos;i<=n;++i)
	{
		chmin(qwq,a[i]);
		res[i]=qwq;
	}
	for(int i=1;i<=n;++i) printf("%d ",res[i]);
	printf("\n");
	return 0;
}