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

const int N=100005;
struct node{
	int a,b,c;
	Finline bool operator < (const node &o)const{return b==o.b?a>o.a:b>o.b;}
}a[N];
ll f[N];
struct seg_tr{
	struct node{
		int ls,rs;
		ll maxx;
	}f[N<<5];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].maxx=max(f[f[x].ls].maxx,f[f[x].rs].maxx);
	}
	void Update(const int &l,const int &r,const int &pos,const ll &val,int &cur)
	{
		if(!cur) cur=++node_cnt;
		if(l==r)
		{
			chmax(f[cur].maxx,val);
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(l,mid,pos,val,f[cur].ls);
		else Update(mid+1,r,pos,val,f[cur].rs);
		PushUp(cur);
	}
	ll Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(!cur) return 0;
		if(L<=l&&r<=R) return f[cur].maxx;
		int mid=(l+r)>>1;
		return max(L<=mid?Query(L,R,l,mid,f[cur].ls):0,R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
}tr;
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].a,a[i].b,a[i].c);
	}
	std::sort(a+1,a+n+1);
	int root=0;
	for(int i=1;i<=n;++i)
	{
		f[i]=a[i].b==1?0:tr.Query(1,a[i].b-1,1,1e9,root)+a[i].c;
		tr.Update(1,1e9,a[i].a,f[i],root);
	}
	ll ans=0;
	for(int i=1;i<=n;++i) chmax(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}