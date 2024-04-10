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
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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

const int N=300005;
struct node{
	int minn,cnt;
	Finline node operator + (const node &o)const
	{
		if(o.minn==minn) return (node){minn,cnt+o.cnt};
		if(o.minn<minn) return o;
		return *this;
	}
};
struct seg_tr{
	struct Node{
		int ls,rs;
		int tag1,tag3;
		node val;
		ll cnt;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val=f[f[x].ls].val+f[f[x].rs].val;
		f[x].cnt=f[f[x].ls].cnt+f[f[x].rs].cnt;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].val=(node){inf-l,1};
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	Finline void add3(int cur,int x,int val)
	{
		if(f[cur].val.minn==val)
		{
			f[cur].cnt+=1ll*x*f[cur].val.cnt;
			f[cur].tag3+=x;
		}
	}
	Finline void add1(int cur,int x)
	{
		/*
		if(f[cur].tag3)
		{
			add3(f[cur].ls,f[cur].tag3,f[cur].val.minn);
			add3(f[cur].rs,f[cur].tag3,f[cur].val.minn);
			f[cur].tag3=0;
		}
		*/
		f[cur].tag1+=x;
		f[cur].val.minn+=x;
	}
	Finline void PushDown(int cur)
	{
		if(f[cur].tag1)
		{
			add1(f[cur].ls,f[cur].tag1);
			add1(f[cur].rs,f[cur].tag1);
			f[cur].tag1=0;
		}
		if(f[cur].tag3)
		{
			add3(f[cur].ls,f[cur].tag3,f[cur].val.minn);
			add3(f[cur].rs,f[cur].tag3,f[cur].val.minn);
			f[cur].tag3=0;
		}
	}
	void Update1(int L,int R,int l,int r,int cur,int C)
	{
		if(L<=l&&r<=R)
		{
			add1(cur,C);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update1(L,R,l,mid,f[cur].ls,C);
		if(R>mid) Update1(L,R,mid+1,r,f[cur].rs,C);
		PushUp(cur);
	}
	ll Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return f[cur].cnt;
		PushDown(cur);
		int mid=(l+r)>>1;
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
}tr;
int a[N];
int st1[N],top1;
int st2[N],top2;
struct Qry{
	int r,id;
};
std::vector<Qry> v[N];
ll ans[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	int _;
	read(_);
	int x,y;
	for(int i=1;i<=_;++i)
	{
		read(x,y);
		v[x].push_back((Qry){y,i});
	}
	tr.build(1,n);
	st1[0]=st2[0]=n+1;
	top1=top2=0;
	for(int i=n;i>=1;--i)
	{
		while(top1&&a[i]>a[st1[top1]])
		{
			tr.Update1(st1[top1],st1[top1-1]-1,1,n,1,a[i]-a[st1[top1]]);
			--top1;
		}
		st1[++top1]=i;
		tr.Update1(i,i,1,n,1,a[i]-inf);
		while(top2&&a[i]<a[st2[top2]])
		{
			tr.Update1(st2[top2],st2[top2-1]-1,1,n,1,-(a[i]-a[st2[top2]]));
			--top2;
		}
		st2[++top2]=i;
		tr.Update1(i,i,1,n,1,-a[i]);
		tr.add3(1,1,-i);
		for(auto it:v[i])
		{
			ans[it.id]=tr.Query(i,it.r,1,n,1);
		}
	}
	for(int i=1;i<=_;++i) printf("%lld\n",ans[i]);
	return 0;
}