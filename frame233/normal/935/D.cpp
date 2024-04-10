// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<bitset>
#include<set>
#include<map>

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

const int N=100005,mod=1000000007;
ll a[N],b[N];
ll ksm(ll a,int b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i) read(b[i]);
	ll ans=0,mul=1;
	ll sum=1ll*m*m%mod;
	ll inv_m=ksm(m);
	ll inv_sum=ksm(sum);
	ll inv_2=ksm(2);
	for(int i=1;i<=n;++i)
	{
		if(a[i]&&b[i])
		{
			if(a[i]<b[i])
			{
				break;
			}
			if(a[i]>b[i])
			{
				ans+=mul;
				ans%=mod;
				break;
			}
		}
		if(a[i]&&!b[i])
		{
			ans+=mul*(a[i]-1)%mod*inv_m%mod;
			ans%=mod;
			mul=mul*inv_m%mod;
		}
		if(!a[i]&&b[i])
		{
			ans+=mul*(m-b[i])%mod*inv_m%mod;
			ans%=mod;
			mul=mul*inv_m%mod;
		}
		if(!a[i]&&!b[i])
		{
			ans+=mul*(sum-m)%mod*inv_2%mod*inv_sum%mod;
			ans%=mod;
			mul=mul*m%mod*inv_sum%mod;
		}
	}
	printf("%lld\n",(ans%mod+mod)%mod);
    return 0;
}