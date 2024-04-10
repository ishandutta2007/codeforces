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
 
const int N=1200005;
struct node{
	bool l,r;
	int ans;
	Finline node operator + (const node &o)const
	{
		return (node){l,o.r,ans+o.ans-(r==o.l)};
	}
};
int L[N],R[N];
int t[N];
int a[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		node val1,val2;
		bool tag;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val1=f[f[x].ls].val1+f[f[x].rs].val1;
		f[x].val2=f[f[x].ls].val2+f[f[x].rs].val2;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].tag=0;
		if(l==r)
		{
			f[cur].ls=f[cur].rs=0;
			f[cur].val1=(node){a[l]==0,a[l]==0,1};
			f[cur].val2=(node){a[l]==1,a[l]==1,1};
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	Finline void upd(int cur)
	{
		f[cur].tag^=1;
		std::swap(f[cur].val1,f[cur].val2);
	}
	Finline void PushDown(int cur)
	{
		if(f[cur].tag)
		{
			upd(f[cur].ls);
			upd(f[cur].rs);
			f[cur].tag=0;
		}
	}
	void Update(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			upd(cur);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	Finline int Query(){return f[1].val1.ans;}
}tr;
void MAIN()
{
	tr.node_cnt=0;
	int n;
	read(n);
	int len=0;
	for(int i=1;i<=n;++i)
	{
		read(L[i],R[i]);
		t[++len]=L[i];
		t[++len]=R[i];
	}
	std::sort(t+1,t+len+1);
	len=std::unique(t+1,t+len+1)-t-1;
	memset(a,0,8*(len+2));
	for(int i=1;i<=n;++i)
	{
		L[i]=std::lower_bound(t+1,t+len+1,L[i])-t;
		R[i]=std::lower_bound(t+1,t+len+1,R[i])-t;
		L[i]<<=1;
		R[i]<<=1;
		++a[L[i]];
		--a[R[i]+1];
	}
	len<<=1;
	for(int i=1;i<=len;++i) a[i]+=a[i-1];
	int root=tr.build(1,len);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		tr.Update(L[i],R[i],1,len,root);
		chmax(ans,tr.Query()>>1);
		tr.Update(L[i],R[i],1,len,root);
	}
	printf("%d\n",ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}