// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=(1<<18)+5;
int a[N];
struct BIT{
	ll c[N];
	Finline void add(int x,int C){++x;for(;x<N;x+=lowbit(x))c[x]+=C;}
	Finline ll sum(int x){++x;ll ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
int main()
{
	int n,q;read(n,q);
	for(int i=0;i<1<<n;++i) read(a[i]),tr.add(i,a[i]);
	int tag=0,opt,x,y;
	while(q--)
	{
		read(opt);
		if(opt==1)
		{
			read(x,y),--x,x^=tag;
			tr.add(x,y-a[x]);
			a[x]=y;
		}
		else if(opt==2)
		{
			read(x);
			tag^=(1<<x)-1;
		}
		else if(opt==3)
		{
			read(x);
			tag^=1<<x;
		}
		else
		{
			auto calc=[&](int r)->ll
			{
				if(r<0) return 0ll;
				ll ans=0;
				int qwq=0;
				for(int i=n;i>=0;--i)
				{
					if((tag>>i)&1) qwq|=1<<i;
					if((r>>i)&1)
					{
						ans+=tr.sum(qwq+(1<<i)-1)-tr.sum(qwq-1);
						qwq^=1<<i;
					}
				}
				return ans;
			};
			read(x,y);
			printf("%lld\n",calc(y)-calc(x-1));
		}
	}
	return 0;
}