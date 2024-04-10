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
 
const int N=1005;
const int mod=998244353;
struct node{
	int x,y;
};
std::vector<node> v[N*N];
int a[N][N];
int t[N*N];
ll inv[N*N];
int sum[N*N];
Finline void add(ll &a,const ll &b){(a+=b)>=mod&&(a-=mod);}
Finline void sub(ll &a,const ll &b){(a-=b)<0&&(a+=mod);}
ll x2,x_2,y2,y_2;
ll f;
Finline void _add(const int &x,const int &y,const ll &ans)
{
	add(x2,x*x%mod);
	add(x_2,2ll*x%mod);
	add(y2,y*y%mod);
	add(y_2,2ll*y%mod);
	add(f,ans);
}
int main()
{
	inv[0]=inv[1]=1;
	for(int i=2;i<=1000000;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	int n,m;
	read(n,m);
	int len=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(a[i][j]);
			t[++len]=a[i][j];
		}
	}
	std::sort(t+1,t+len+1);
	len=std::unique(t+1,t+len+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			v[std::lower_bound(t+1,t+len+1,a[i][j])-t].push_back((node){i,j});
		}
	}
	for(int i=1;i<=len;++i)
	{
		sum[i]=sum[i-1]+v[i].size();
	}
	int r,c;
	read(r,c);
	int cur=std::lower_bound(t+1,t+len+1,a[r][c])-t;
	if(cur==1)
	{
		printf("0\n");
		return 0;
	}
	for(auto it:v[1])
	{
		_add(it.x,it.y,0);
	}
	for(int i=2;i<cur;++i)
	{
		std::vector<std::pair<node,ll> > _v;
		ll _inv=inv[sum[i-1]];
		for(auto it:v[i])
		{
			ll tmp=f*_inv%mod;
			
			add(tmp,x2*_inv%mod);
			sub(tmp,x_2*it.x%mod*_inv%mod);
			add(tmp,it.x*it.x%mod);
			
			add(tmp,y2*_inv%mod);
			sub(tmp,y_2*it.y%mod*_inv%mod);
			add(tmp,it.y*it.y%mod);
			
			_v.push_back(std::make_pair(it,tmp));
		}
		for(auto it:_v)
		{
			_add(it.first.x,it.first.y,it.second);
		}
	}
	ll _inv=inv[sum[cur-1]];
	ll tmp=f*_inv%mod;
	add(tmp,x2*_inv%mod);
	sub(tmp,x_2*r%mod*_inv%mod);
	add(tmp,r*r%mod);
	
	add(tmp,y2*_inv%mod);
	sub(tmp,y_2*c%mod*_inv%mod);
	add(tmp,c*c%mod);
	printf("%lld\n",tmp);
    return 0;
}