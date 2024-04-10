// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
const int n=100000;
const int mod=998244353;
const int inv2=(mod+1)>>1;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int a[N];
bool pr[N];
int p[N],pos,mu[N];
void sieve()
{
	mu[1]=1;
	for(int i=2;i<N;++i)
	{
		if(!pr[i]) p[++pos]=i,mu[i]=-1;
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
ll val1[N],val2[N],val3[N];
inline ll f1(ll x)
{
	return x==0?0:ksm(2,x-1)*x%mod;
}
inline ll f2(ll x)
{
	return x==0?0:x==1?1:ksm(2,x-2)*x%mod*(x+1)%mod;
}
inline ll f3(ll x)
{
	return x==0?0:x==1?1:x==2?10:ksm(2,x-3)*x%mod*x%mod*(x+3)%mod;
}
int main()
{
	sieve();
	int m;read(m);
	int x,y;
	for(int i=1;i<=m;++i) read(x,y),a[x]=y;
	for(int i=1;i<=n;++i) val1[i]=f1(a[i])*ksm(inv2,a[i])%mod,val2[i]=f2(a[i])*ksm(inv2,a[i])%mod,val3[i]=f3(a[i])*ksm(inv2,a[i])%mod;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		ll A=0,B=0,sum=0;
		for(int j=i;j<=n;j+=i) sum+=a[j],add(A,val1[j]),add(B,val1[j]*j%mod);
		sum=ksm(2,sum);
		ll tmp=A*B%mod*B%mod;
		sub(tmp,B*B%mod);
		for(int j=i;j<=n;j+=i) sub(tmp,2ll*val1[j]%mod*val1[j]%mod*j%mod*B%mod);
		for(int j=i;j<=n;j+=i) sub(tmp,val1[j]*j%mod*val1[j]%mod*j%mod*A%mod);
		for(int j=i;j<=n;j+=i) add(tmp,2ll*val1[j]*val1[j]%mod*j%mod*val1[j]%mod*j%mod);
		for(int j=i;j<=n;j+=i) add(tmp,2ll*val2[j]*j%mod*B%mod);
		for(int j=i;j<=n;j+=i) add(tmp,val2[j]*j%mod*j%mod*A%mod);
		for(int j=i;j<=n;j+=i) sub(tmp,3ll*val2[j]*j%mod*val1[j]%mod*j%mod);
		for(int j=i;j<=n;j+=i) add(tmp,val3[j]*j%mod*j%mod);
		for(int j=i;j<=n;j+=i) add(tmp,val1[j]*j%mod*val1[j]%mod*j%mod);
		for(int j=i;j<=n;j+=i) sub(tmp,val2[j]*j%mod*j%mod);
		tmp=tmp*sum%mod;
		if(mu[i]==1) add(ans,tmp);
		else if(mu[i]==-1) sub(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}