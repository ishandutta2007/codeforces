// luogu-judger-enable-o2
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
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;

uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
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
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=100005;
struct node{
	int r,a,id;
	int l_s;
	Finline bool operator < (const node &o)const
	{
		return r<o.r;
	}
}a[N],b[N];
struct BIT{
	int c[N],n;
	Finline void add(int x,const int &C){for(;x<=n;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
struct qry{
	int r;
	int l_,r_;
	int id;
	Finline bool operator < (const qry &o)const
	{
		return r>o.r;
	}
}q[N];
struct seg_tr{
	struct node{
		int ls,rs;
		int maxx;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].maxx=max(f[f[x].ls].maxx,f[f[x].rs].maxx);
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		f[cur].maxx=-1;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(const int &pos,const int &l,const int &r,const int &cur,const int &C)
	{
		if(l==r)
		{
			chmax(f[cur].maxx,C);
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,C);
		else Update(pos,mid+1,r,f[cur].rs,C);
		PushUp(cur);
	}
	int Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].maxx;
		}
		int mid=(l+r)>>1;
		return max(L<=mid?Query(L,R,l,mid,f[cur].ls):-1,R>mid?Query(L,R,mid+1,r,f[cur].rs):-1);
	}
}Tr;
int cnt[N];
int t[N],pos;
int l_s[N];
int ans[N];
int main()
{
	int n,k;
	read(n,k);
	for(int i=1;i<=n;++i)
	{
		read(a[i].r);
	}
	for(int i=1;i<=n;++i)
	{
		read(a[i].a);
		t[++pos]=a[i].a;
		a[i].id=i;
		b[i]=a[i];
	}
	std::sort(t+1,t+n+1);
	int len=std::unique(t+1,t+n+1)-t-1;
	tr.n=len;
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		l_s[i]=std::lower_bound(t+1,t+len+1,a[i].a)-t;
		a[i].l_s=l_s[i];
	}
	for(int i=1;i<=n;)
	{
		tr.add(l_s[i],1);
		int j=i;
		while(j<n&&a[j+1].r==a[i].r)
		{
			++j;
			tr.add(l_s[j],1);
		}
		int tmp=tr.sum(std::upper_bound(t+1,t+len+1,a[i].a+k)-t-1)-tr.sum(std::lower_bound(t+1,t+len+1,a[i].a-k)-t-1);
		while(i<=j)
		{
			cnt[a[i++].id]=tmp;
		}
	}
	std::reverse(a+1,a+n+1);
	int _,x,y;
	read(_);
	for(int i=1;i<=_;++i)
	{
		read(x,y);
		q[i]=(qry){max(b[x].r,b[y].r),std::lower_bound(t+1,t+len+1,max(b[x].a,b[y].a)-k)-t,std::upper_bound(t+1,t+len+1,min(b[x].a,b[y].a)+k)-t-1,i};
	}
	std::sort(q+1,q+_+1);
	int root=Tr.build(1,len);
	int pos=0;
	for(int i=1;i<=_;++i)
	{
		while(pos<n&&a[pos+1].r>=q[i].r)
		{
			++pos;
			Tr.Update(a[pos].l_s,1,len,root,cnt[a[pos].id]);
		}
		if(q[i].l_>q[i].r_)
		{
			ans[q[i].id]=-1;
			continue;
		}
		ans[q[i].id]=Tr.Query(q[i].l_,q[i].r_,1,len,root);
	}
	for(int i=1;i<=_;++i) printf("%d\n",ans[i]);
    return 0;
}