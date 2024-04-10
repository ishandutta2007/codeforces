// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
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
const ll INF=0x7fffffffffffffff;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
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
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
bool pr[N];
int p[N],pos;
int mu[N];
int val[N];
int f[N],dp[N];
void sieve()
{
	mu[1]=1;
	for(int i=2;i<N;++i)
	{
		if(!pr[i])
		{
			p[++pos]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=pos&&i*p[j]<N;++j)
		{
			pr[i*p[j]]=true;
			if(!(i%p[j]))
			{
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	
}
int main()
{
	sieve();
	int n;
	read(n);
	int m=n;
	dp[1]=0;
	ll inv=ksm(m);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		add(dp[i],1ll*val[i]*(m/i)%mod);
		if(i!=1)
		{
			ll tmp=inv*(n/i)%mod;
			dp[i]=ksm((1-tmp+mod))*(inv*dp[i]%mod+1)%mod;
		}
		for(int j=i,t=1;j<=n;j+=i,++t)
		{
			if(mu[t]==1) add(val[j],dp[i]);
			else if(mu[t]==-1) sub(val[j],dp[i]);
		}
		val[i]=1ll*val[i]*(m/i)%mod;
		for(int j=i+i;j<=n;j+=i)
		{
			add(dp[j],val[i]);
		}
		add(ans,dp[i]);
	}
	ans=ans*inv%mod;
	add(ans,1);
	printf("%lld\n",ans);
	return 0;
}