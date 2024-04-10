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

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
bool check(int n,int k)
{
	if(!(n&1)) return false;
	if(n==1) return k==0;
	if(k>((n-3)>>1)) return false;
	if(k==0) return lowbit(n+1)==n+1;
	if(k==1) return lowbit(n+1)!=n+1;
	if(k==2) return n!=9;
	return true;
}
int node_cnt,fa[N];
int solve(int n,int k)
{
//	assert(check(n,k));
	int cur=++node_cnt;
	if(n==1) return cur;
	if(k==0)
	{
		fa[solve((n-1)>>1,k)]=cur;
		fa[solve((n-1)>>1,k)]=cur;
		return cur;
	}
	if(k==1)
	{
		if(__builtin_popcount(n+1)==2)
		{
			fa[solve(lowbit(n+1)-1,0)]=cur;
			fa[solve(((n+1)^lowbit(n+1))-1,0)]=cur;
		}
		else
		{
			int qwq=n+1;
			for(int i=17;i>=0;--i)
			{
				if((qwq>>i)&1)
				{
					if((qwq>>(i-1))&1)
					{
						fa[solve((1<<i)-1,0)]=cur;
						fa[solve((qwq^(1<<i))-1,1)]=cur;
					}
					else
					{
						fa[solve((1<<(i-1))-1,0)]=cur;
						fa[solve(n-(1<<(i-1)),1)]=cur;
					}
					break;
				}
			}
		}
		return cur;
	}
	if(n==11&&k==3)
	{
		fa[solve(3,0)]=cur;
		fa[solve(7,2)]=cur;
	}
	else
	{
		if(k==2&&lowbit(n-1)==n-1)
		{
			fa[solve(3,0)]=cur;
			fa[solve(n-4,1)]=cur;
		}
		else
		{
			fa[solve(1,0)]=cur;
			fa[solve(n-2,k-1)]=cur;
		}
	}
	return cur;
}
int main()
{
	int n,k;
	read(n,k);
	if(check(n,k))
	{
		printf("YES\n");
		solve(n,k);
		for(int i=1;i<=n;++i) printf("%d ",fa[i]);
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}