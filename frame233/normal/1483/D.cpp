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

const int N=605;
ll d[N][N],a[N][N],e[N][N];
int main()
{
	memset(d,63,sizeof(d)),memset(e,63,sizeof(e));
	int n,m;read(n,m);
	int x,y,z;
	for(int i=1;i<=n;++i)d[i][i]=0;
	for(int i=1;i<=m;++i)read(x,y,z),d[x][y]=z,d[y][x]=z,e[x][y]=e[y][x]=z;
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)chmin(d[i][j],d[i][k]+d[k][j]);
	int q;read(q);
	memset(a,-1,sizeof(a));
	for(int i=1;i<=q;++i)
	{
		read(x,y,z);
		for(int u=1;u<=n;++u)chmax(a[y][u],z-d[x][u]);
		for(int u=1;u<=n;++u)chmax(a[x][u],z-d[y][u]);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(e[i][j]<inf)for(int k=1;k<=n;++k)if(e[i][j]+d[j][k]<=a[k][i]){++ans;break;}
	printf("%lld\n",ans);
	return 0;
}