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

const int N=200005;
const int mod=998244353;
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll d[55],a[55],S,val[55];
int cnt[1<<14],SIZ,ans[55],res[55],C[55][55];
inline int popc(ll x){return cnt[x&0x3fff]+cnt[(x>>14)&0x3fff]+cnt[(x>>28)&0x3fff]+cnt[(x>>42)&0x3fff];}
void dfs(int dep,ll s)
{
	if(dep==SIZ)return ++ans[popc(s)],void();
	dfs(dep+1,s),dfs(dep+1,s^a[dep]);
}
void DFS(int dep,ll s,int c)
{
	if(dep==SIZ)return ++res[popc(s)+c],void();
	DFS(dep+1,s,c),DFS(dep+1,s^val[dep],c+1);
}
int main()
{
	for(int i=0;i<55;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	for(int i=0;i<1<<14;++i)cnt[i]=cnt[i>>1]+(i&1);
	int n,m;read(n,m);
	ll x;
	for(int i=1;i<=n;++i)
	{
		read(x);
		for(int j=m-1;j>=0;--j)if(x>>j&1){if(d[j])x^=d[j];else{d[j]=x;break;}}
	}
	for(int i=m-1;i>=0;--i)if(d[i])for(int j=i+1;j<m;++j)if(d[j]>>i&1)d[j]^=d[i];
	std::vector<ll> v;for(int i=0;i<m;++i)if(d[i])v.pb(d[i]);
	ll mul=ksm(2,n-SZ(v));
	if(SZ(v)<=m-SZ(v))
	{
		for(int i=0;i<SZ(v);++i)a[i]=v[i];
		SIZ=SZ(v),dfs(0,0);
		for(int i=0;i<=m;++i)printf("%lld%c",mul*ans[i]%mod," \n"[i==m]);
		return 0;
	}
	SIZ=0;for(int i=0;i<m;++i)if(!d[i]){for(int j=0;j<SZ(v);++j)if(v[j]>>i&1)val[SIZ]|=1LL<<j;++SIZ;}
	DFS(0,0,0);
	for(int a=0;a<=m;++a)for(int b=0;b<=m;++b)
	{
		int coef=0;
		for(int i=0;i<=a&&i<=b;++i)
		{
			int tmp=1LL*C[a][i]*C[m-a][b-i]%mod;
			i&1?sub(coef,tmp):add(coef,tmp);
		}
		add(ans[b],1LL*res[a]*coef%mod);
	}
	mul=mul*ksm((mod+1)/2,m-SZ(v))%mod;
	for(int i=0;i<=m;++i)printf("%lld%c",mul*ans[i]%mod," \n"[i==m]);
	return 0;
}