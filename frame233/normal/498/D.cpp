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
const double eps=1e-10;

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

const int N=100005;
int a[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		int t[61];
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		for(int i=0;i<60;++i)
		{
			f[x].t[i]=f[f[x].ls].t[i]+f[f[x].rs].t[(i+f[f[x].ls].t[i])%60];
		}
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			for(int i=0;i<60;++i)
			{
				if(!(i%a[l]))
				{
					f[cur].t[i]=2;
				}
				else
				{
					f[cur].t[i]=1;
				}
			}
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update(const int &pos,const int &l,const int &r,const int &cur,const int &val)
	{
		if(l==r)
		{
			for(int i=0;i<60;++i)
			{
				if(!(i%val))
				{
					f[cur].t[i]=2;
				}
				else
				{
					f[cur].t[i]=1;
				}
			}
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,val);
		if(pos>mid) Update(pos,mid+1,r,f[cur].rs,val);
		PushUp(cur);
	}
	int Query(const int &L,const int &R,const int &l,const int &r,const int &cur,const int &_)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].t[_];
		}
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			int tmp=Query(L,R,l,mid,f[cur].ls,_);
			return tmp+Query(L,R,mid+1,r,f[cur].rs,(tmp+_)%60);
		}
		else if(L<=mid)
		{
			return Query(L,R,l,mid,f[cur].ls,_);
		}
		else
		{
			return Query(L,R,mid+1,r,f[cur].rs,_);
		}
	}
}tr;
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	int root=tr.build(1,n);
	int _;
	read(_);
	char opt;
	int x,y;
	while(_--)
	{
		opt=getchar();
		while(opt!='A'&&opt!='C') opt=getchar();
		read(x,y);
		if(opt=='C')
		{
			tr.Update(x,1,n,root,y);
		}
		else
		{
			printf("%d\n",tr.Query(x,y-1,1,n,root,0));
		}
	}
    return 0;
}