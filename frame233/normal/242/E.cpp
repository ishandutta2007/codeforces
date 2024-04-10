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
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
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
int a[N];
struct seg_tr{
	struct node{
		int ls,rs;
		int cnt[2];
		bool rev;
	}f[N<<2];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].cnt[0]=f[f[x].ls].cnt[0]+f[f[x].rs].cnt[0];
		f[x].cnt[1]=f[f[x].ls].cnt[1]+f[f[x].rs].cnt[1];
	}
	Finline void flip(const int &x)
	{
		std::swap(f[x].cnt[0],f[x].cnt[1]);
		f[x].rev^=1;
	}
	Finline void PushDown(const int &x)
	{
		if(f[x].rev)
		{
			if(f[x].ls) flip(f[x].ls);
			if(f[x].rs) flip(f[x].rs);
			f[x].rev=0;
		}
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			++f[cur].cnt[a[l]&1];
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return PushUp(cur),cur;
	}
	void Update(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			flip(cur);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	int Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R) return f[cur].cnt[1];
		int mid=(l+r)>>1;
		PushDown(cur);
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
}tr[21];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=0;i<=20;++i)
	{
		tr[i].build(1,n);
		for(int j=1;j<=n;++j)
		{
			a[j]>>=1;
		}
	}
	int m,opt,l,r,x;
	ll ans;
	read(m);
	for(int i=1;i<=m;++i)
	{
		read(opt);
		if(opt==1)
		{
			read(l,r);
			ans=0;
			for(int bit=0;bit<=20;++bit)
			{
				ans+=(1ll<<bit)*tr[bit].Query(l,r,1,n,1);
			}
			printf("%lld\n",ans);
		}
		else
		{
			read(l,r,x);
			for(int bit=0;bit<=20;++bit)
			{
				if((x>>bit)&1)
				{
					tr[bit].Update(l,r,1,n,1);
				}
			}
		}
	}
	return 0;
}