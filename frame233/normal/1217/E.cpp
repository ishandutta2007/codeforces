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

const int N=200005;
struct seg_tr{
	struct Node{
		int ls,rs;
		int minn1[10],minn2[10];
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		for(int i=0;i<10;++i)
		{
			f[x].minn1[i]=f[f[x].ls].minn1[i];
			f[x].minn2[i]=f[f[x].ls].minn2[i];
			if(f[f[x].rs].minn1[i]<f[x].minn1[i])
			{
				f[x].minn2[i]=f[x].minn1[i];
				f[x].minn1[i]=f[f[x].rs].minn1[i];
			}
			else if(f[f[x].rs].minn1[i]<f[x].minn2[i])
			{
				f[x].minn2[i]=f[f[x].rs].minn1[i];
			}
			if(f[f[x].rs].minn2[i]<f[x].minn1[i])
			{
				f[x].minn2[i]=f[x].minn1[i];
				f[x].minn1[i]=f[f[x].rs].minn2[i];
			}
			else if(f[f[x].rs].minn2[i]<f[x].minn2[i])
			{
				f[x].minn2[i]=f[f[x].rs].minn2[i];
			}
		}
	}
	int build(const int &l,const int &r,int *arr)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			int mul=1;
			for(int i=0;i<10;++i)
			{
				if((arr[l]/mul)%10)
				{
					f[cur].minn1[i]=arr[l];
				}
				else
				{
					f[cur].minn1[i]=inf;
				}
				f[cur].minn2[i]=inf;
				mul*=10;
			}
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid,arr);
		f[cur].rs=build(mid+1,r,arr);
		PushUp(cur);
		return cur;
	}
	void Update(const int &l,const int &r,const int &cur,const int &pos,const int &val)
	{
		if(l==r)
		{
			int mul=1;
			for(int i=0;i<10;++i)
			{
				if((val/mul)%10)
				{
					f[cur].minn1[i]=val;
				}
				else
				{
					f[cur].minn1[i]=inf;
				}
				f[cur].minn2[i]=inf;
				mul*=10;
			}
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(l,mid,f[cur].ls,pos,val);
		else Update(mid+1,r,f[cur].rs,pos,val);
		PushUp(cur);
	}
	std::pair<int,int> Query(const int &L,const int &R,const int &l,const int &r,const int &cur,const int &pos)
	{
		if(L<=l&&r<=R)
		{
			return std::make_pair(f[cur].minn1[pos],f[cur].minn2[pos]);
		}
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			std::pair<int,int> lt=Query(L,R,l,mid,f[cur].ls,pos);
			std::pair<int,int> rt=Query(L,R,mid+1,r,f[cur].rs,pos);
			if(rt.first<lt.first)
			{
				lt.second=lt.first;
				lt.first=rt.first;
			}
			else if(rt.first<lt.second)
			{
				lt.second=rt.first;
			}
			if(rt.second<lt.first)
			{
				lt.second=lt.first;
				lt.first=rt.second;
			}
			else if(rt.second<lt.second)
			{
				lt.second=rt.second;
			}
			return lt;
		}
		else if(L<=mid)
		{
			return Query(L,R,l,mid,f[cur].ls,pos);
		}
		else
		{
			return Query(L,R,mid+1,r,f[cur].rs,pos);
		}
	}
}tr;
int a[N];
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	int root=tr.build(1,n,a);
	int opt,x,y;
	std::pair<int,int> ans;
	while(m--)
	{
		read(opt,x,y);
		if(opt==1)
		{
			tr.Update(1,n,root,x,y);
		}
		else
		{
			int res=Inf;
			for(int i=0;i<10;++i)
			{
				ans=tr.Query(x,y,1,n,root,i);
				if(ans.first<inf&&ans.second<inf)
				{
					chmin(res,ans.first+ans.second);
				}
			}
			if(res==Inf)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n",res);
			}
		}
	}
    return 0;
}