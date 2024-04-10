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

const int N=500005;
struct edge{
	int v,nxt;
}c[N<<5];
int front[N<<1],cnt,dg[N<<1];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
	++dg[v];
}
struct seg_tr{
	struct node{
		int ls,rs;
	}f[N<<1];
	int node_cnt;
	int build(const int &l,const int &r)
	{
		if(l==r)
		{
			f[l].ls=f[l].rs=0;
			return l;
		}
		int cur=++node_cnt;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		add(f[cur].ls,cur);
		add(f[cur].rs,cur);
		return cur;
	}
	void Update(const int &L,const int &R,const int &l,const int &r,const int &cur,const int &node)
	{
		if(L<=l&&r<=R)
		{
			add(cur,node);
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,node);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,node);
	}
}tr;
int _q[N<<1],_l,_r;
int f[N<<1];
struct node{
	int x,id;
	Finline bool operator < (const node &o)const{return x<o.x;}
}tmp[N];
void MAIN()
{
	int n,x;
	read(n);
	tr.node_cnt=n;
	cnt=0;
	memset(front,0,8*(n+2));
	memset(dg,0,8*(n+2));
	memset(f,0,8*(n+2));
	int root=tr.build(1,n);
	for(int i=1;i<=n;++i)
	{
		read(x);
		if(~x)
		{
			if(x!=n+1)
			{
				add(i,x);
			}
			if(i+2<=x)
			{
				tr.Update(i+1,x-1,1,n,root,i);
			}
		}
	}
	_l=1,_r=0;
	for(int i=1;i<=tr.node_cnt;++i)
	{
		if(!dg[i])
		{
			_q[++_r]=i;
			f[i]=1;
		}
	}
	int tot=0;
	while(_l!=_r+1)
	{
		++tot;
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt)
		{
			chmax(f[c[i].v],f[x]+1);
			if(!--dg[c[i].v])
			{
				_q[++_r]=c[i].v;
			}
		}
	}
	if(tot!=tr.node_cnt)
	{
		printf("-1\n");
		return;
	}
	for(int i=1;i<=n;++i)
	{
		tmp[i]=(node){f[i],i};
	}
	std::sort(tmp+1,tmp+n+1);
	for(int i=1;i<=n;++i)
	{
		f[tmp[i].id]=i;
	}
	for(int i=1;i<=n;++i) printf("%d ",f[i]);
	printf("\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}