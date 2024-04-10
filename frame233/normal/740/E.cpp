
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
 
const int N=300005;
struct seg_tr{
	struct node{
		int ls,rs;
		ll lft,rgt;
		int l,r;
		int ans;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x,const int &l,const int &r)
	{
		int mid=(l+r)>>1;
		f[x].ans=max(f[f[x].ls].ans,f[f[x].rs].ans);
		if((f[f[x].ls].rgt>0&&f[f[x].rs].lft<0)||(f[f[x].ls].rgt>0&&f[f[x].rs].lft>0)||(f[f[x].ls].rgt<0&&f[f[x].rs].lft<0))
		{
			chmax(f[x].ans,f[f[x].ls].r+f[f[x].rs].l);
		}
		f[x].lft=f[f[x].ls].lft,f[x].rgt=f[f[x].rs].rgt;
		if(f[f[x].ls].l==mid-l+1&&((f[f[x].ls].rgt>0&&f[f[x].rs].lft<0)||(f[f[x].ls].rgt>0&&f[f[x].rs].lft>0)||(f[f[x].ls].rgt<0&&f[f[x].rs].lft<0)))
		{
			f[x].l=f[f[x].ls].l+f[f[x].rs].l;
		}
		else
		{
			f[x].l=f[f[x].ls].l;
		}
		if(f[f[x].rs].r==r-mid&&((f[f[x].ls].rgt>0&&f[f[x].rs].lft<0)||(f[f[x].ls].rgt>0&&f[f[x].rs].lft>0)||(f[f[x].ls].rgt<0&&f[f[x].rs].lft<0)))
		{
			f[x].r=f[f[x].rs].r+f[f[x].ls].r;
		}
		else
		{
			f[x].r=f[f[x].rs].r;
		}
	}
	int build(const int &l,const int &r,int *arr)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			if(arr[l])
			{
				f[cur].ans=f[cur].l=f[cur].r=1;
			}
			f[cur].lft=f[cur].rgt=arr[l];
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid,arr);
		f[cur].rs=build(mid+1,r,arr);
		PushUp(cur,l,r);
		return cur;
	}
	void Update(const int &pos,const int &l,const int &r,const int &cur,const int &C)
	{
		if(l==r)
		{
			f[cur].lft+=C;
			f[cur].rgt+=C;
			if(f[cur].lft)
			{
				f[cur].ans=f[cur].l=f[cur].r=1;
			}
			else
			{
				f[cur].ans=f[cur].l=f[cur].r=0;
			}
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,C);
		else Update(pos,mid+1,r,f[cur].rs,C);
		PushUp(cur,l,r);
	}
}tr;
int a[N];
int main()
{
	int n;
	int _,l,r,x;
	read(n);
	if(n==1)
	{
		read(x);
		read(_);
		while(_--)
		{
			printf("1\n");
		}
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	for(int i=1;i<n;++i) a[i]=a[i+1]-a[i];
	int root=tr.build(1,n-1,a);
	read(_);
	while(_--)
	{
		read(l,r,x);
		if(l!=1) tr.Update(l-1,1,n-1,root,x);
		if(r!=n) tr.Update(r,1,n-1,root,-x);
		printf("%d\n",tr.f[root].ans+1);
	}
    return 0;
}