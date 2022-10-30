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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
bool pr[N];
int mu[N],p[N],pos,pw[N];
void sieve()
{
	mu[1]=1;
	for(int i=2;i<N;++i)
	{
		if(!pr[i])p[++pos]=i,mu[i]=-1;
		for(int j=1;j<=pos&&p[j]*i<N;++j)
		{
			pr[i*p[j]]=true;
			if(i%p[j]==0){mu[i*p[j]]=0;break;}
			mu[i*p[j]]=-mu[i];
		}
	}
}
int cnt[N<<1];
int main()
{
	sieve();
	int n,k;read(n,k);
	pw[0]=1;for(int i=1;i<=n;++i)pw[i]=1LL*pw[i-1]*k%mod;
	int ans=0;
	for(int g=1;g<n;++g)
	{
		int m=(n-1)/g;
		memset(cnt,0,(m+m+3)<<2);
		for(int d=1;d<=m;++d)if(mu[d])
		{
			int lim=m/d;
			if(mu[d]==1)for(int j=1;j<=lim+lim;++j)add(cnt[d*j],min(j-1,lim+lim-j+1));
			else for(int j=1;j<=lim+lim;++j)sub(cnt[d*j],min(j-1,lim+lim-j+1));
		}
		for(int i=1;i<=m+m;++i)add(ans,1LL*pw[max(g,i*g-n)]*cnt[i]%mod);
	}
	printf("%lld\n",1LL*ans*ksm(ksm(k,n))%mod);
	return 0;
}