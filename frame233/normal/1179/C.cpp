// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
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
const int MAXN=1000005;
int a[MAXN];
int A[N],B[N];
struct seg_tr{
	struct node{
		int ls,rs,maxx;
		int tag;
	}f[MAXN<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].maxx=max(f[f[x].ls].maxx,f[f[x].rs].maxx);
	}
	Finline void add(const int &x,const int &C)
	{
		f[x].tag+=C;
		f[x].maxx+=C;
	}
	Finline void PushDown(const int &x)
	{
		if(f[x].tag)
		{
			add(f[x].ls,f[x].tag);
			add(f[x].rs,f[x].tag);
			f[x].tag=0;
		}
	}
	int build(const int &l,const int &r,int *arr)
	{
		int cur=++node_cnt;
		if(l==r) return f[cur].maxx=arr[l],cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid,arr);
		f[cur].rs=build(mid+1,r,arr);
		PushUp(cur);
		return cur;
	}
	void Update(const int &L,const int &R,const int &l,const int &r,const int &cur,const int &val)
	{
		if(L<=l&&r<=R)
		{
			add(cur,val);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,val);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,val);
		PushUp(cur);
	}
	int Query(const int &l,const int &r,const int &cur)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		PushDown(cur);
		if(f[f[cur].rs].maxx>=1) return Query(mid+1,r,f[cur].rs);
		if(f[f[cur].ls].maxx>=1) return Query(l,mid,f[cur].ls);
		return -1;
	}
}tr;
int main()
{
	int n,m,opt,x,y;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read(A[i]);
		++a[A[i]];
	}
	for(int i=1;i<=m;++i)
	{
		read(B[i]);
		--a[B[i]];
	}
	for(int i=1e6;i>=1;--i)
	{
		a[i]+=a[i+1];
	}
	int root=tr.build(1,1e6,a);
	int _;
	read(_);
	while(_--)
	{
		read(opt,x,y);
		if(opt==1)
		{
			tr.Update(1,A[x],1,1e6,root,-1);
			A[x]=y;
			tr.Update(1,y,1,1e6,root,1);
		}
		else
		{
			tr.Update(1,B[x],1,1e6,root,1);
			B[x]=y;
			tr.Update(1,y,1,1e6,root,-1);
		}
		printf("%d\n",tr.Query(1,1e6,root));
	}
	return 0;
}
//