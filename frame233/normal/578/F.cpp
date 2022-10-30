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

const int N=605;
int mod;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
char s[N][N];
int n,m,fa[N*N];
int id[N][N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int a[N][N];
int ID[N*N];
inline void addedge(int u,int v)
{
	add(a[u][u],1),add(a[v][v],1);
	sub(a[u][v],1),sub(a[v][u],1);
}
int calc(int n)
{
	ll ans=1;
	for(int i=1;i<n;++i)
	{
		int pos=0;
		for(int j=i;j<n;++j)if(a[j][i]){pos=j;break;}
		if(!pos) return 0;
		if(i!=pos) ans*=-1,add(ans,mod),std::swap(a[i],a[pos]);
		ans=ans*a[i][i]%mod;
		ll inv=ksm(a[i][i]);
		for(int j=i;j<n;++j) a[i][j]=inv*a[i][j]%mod;
		for(int j=i+1;j<n;++j) for(int k=n-1;k>=i;--k) sub(a[j][k],1ll*a[j][i]*a[i][k]%mod);
	}
	return (ans%mod+mod)%mod;
}
int solve(int k)
{
	memset(id,0,sizeof(id));
	memset(ID,0,sizeof(ID));
	memset(a,0,sizeof(a));
	int cur=0;
	for(int i=1;i<=n+1;++i) for(int j=1;j<=m+1;++j) if(((i+j)&1)==k) id[i][j]=++cur;
	for(int i=1;i<=cur;++i) fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int a=-1,b=-1;
			if(s[i][j]=='\\'&&id[i][j]) a=find(id[i][j]),b=find(id[i+1][j+1]);
			else if(s[i][j]=='/'&&id[i+1][j]) a=find(id[i+1][j]),b=find(id[i][j+1]);
			if(a==-1||b==-1) continue;
			if(a==b) return 0;
			fa[a]=b;
		}
	}
	int qwq=0;
	for(int i=1;i<=cur;++i) if(!ID[find(i)]) ID[find(i)]=++qwq;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='*')
			{
				if(id[i][j]) addedge(ID[find(id[i][j])],ID[find(id[i+1][j+1])]);
				else addedge(ID[find(id[i+1][j])],ID[find(id[i][j+1])]);
			}
		}
	}
	return calc(qwq);
}
int main()
{
	read(n,m,mod);
	for(int i=1;i<=n;++i) read_str(s[i]+1);
	printf("%d\n",(solve(0)+solve(1))%mod);
	return 0;
}