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
 
const int N=200005;
int K;
struct node{
	int a[5];
}a[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		int maxx[33],minn[33];
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		for(int i=0;i<(1<<K);++i)
		{
			f[x].maxx[i]=max(f[f[x].ls].maxx[i],f[f[x].rs].maxx[i]);
			f[x].minn[i]=min(f[f[x].ls].minn[i],f[f[x].rs].minn[i]);
		}
	}
	int build(const int &l,const int &r,node *arr)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			for(int i=0;i<(1<<K);++i)
			{
				for(int j=0;j<K;++j)
				{
					if((i>>j)&1)
					{
						f[cur].maxx[i]+=arr[l].a[j];
					}
					else
					{
						f[cur].maxx[i]-=arr[l].a[j];
					}
				}
				f[cur].minn[i]=f[cur].maxx[i];
			}
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid,arr);
		f[cur].rs=build(mid+1,r,arr);
		PushUp(cur);
		return cur;
	}
	void Update(const int &pos,const int &l,const int &r,const int &cur,const node &o)
	{
		if(l==r)
		{
			for(int i=0;i<(1<<K);++i)
			{
				f[cur].maxx[i]=0;
				for(int j=0;j<K;++j)
				{
					if((i>>j)&1)
					{
						f[cur].maxx[i]+=o.a[j];
					}
					else
					{
						f[cur].maxx[i]-=o.a[j];
					}
				}
				f[cur].minn[i]=f[cur].maxx[i];
			}
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,o);
		else Update(pos,mid+1,r,f[cur].rs,o);
		PushUp(cur);
	}
	int Query_max(const int &L,const int &R,const int &l,const int &r,const int &cur,const int &st)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].maxx[st];
		}
		int mid=(l+r)>>1;
		return max(L<=mid?Query_max(L,R,l,mid,f[cur].ls,st):-inf,R>mid?Query_max(L,R,mid+1,r,f[cur].rs,st):-inf);
	}
	int Query_min(const int &L,const int &R,const int &l,const int &r,const int &cur,const int &st)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].minn[st];
		}
		int mid=(l+r)>>1;
		return min(L<=mid?Query_min(L,R,l,mid,f[cur].ls,st):inf,R>mid?Query_min(L,R,mid+1,r,f[cur].rs,st):inf);
	}
}tr;
int main()
{
	int n;
	read(n,K);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<K;++j)
		{
			read(a[i].a[j]);
		}
	}
	int root=tr.build(1,n,a);
	int _;
	read(_);
	int opt;
	node tmp;
	int l,r;
	while(_--)
	{
		read(opt);
		if(opt==1)
		{
			read(l);
			for(int i=0;i<K;++i)
			{
				read(tmp.a[i]);
			}
			tr.Update(l,1,n,root,tmp);
		}
		else
		{
			read(l,r);
			int ans=0;
			for(int i=0;i<(1<<K);++i)
			{
				chmax(ans,tr.Query_max(l,r,1,n,root,i)-tr.Query_min(l,r,1,n,root,i));
			}
			printf("%d\n",ans);
		}
	}
    return 0;
}