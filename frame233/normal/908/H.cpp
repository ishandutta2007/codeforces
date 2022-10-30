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
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=55;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
char s[N][N];
int fa[N],id[N],siz[N];
int a[23],c[1<<23],e[1<<23],d[1<<23],b[1<<23];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)read_str(s[i]+1),fa[i]=i;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(s[i][j]=='A')fa[find(i)]=find(j);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(s[i][j]=='X'&&find(i)==find(j))return puts("-1"),0;
	for(int i=1;i<=n;++i)++siz[find(i)];
	memset(id,255,sizeof(id));int cnt=0;
	for(int i=1;i<=n;++i)if(fa[i]==i&&siz[i]>1)id[i]=cnt++;
	for(int i=1;i<=n;++i)id[i]=id[find(i)];
	for(int i=0;i<cnt;++i)a[i]=(1<<cnt)-1;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(s[i][j]=='X'&&~id[i]&&~id[j])a[id[i]]&=~(1<<id[j]);
	for(int i=0;i<cnt;++i)e[1<<i]=a[i]^((1<<cnt)-1);
	for(int st=0;st<1<<cnt;++st)
	{
		e[st]=e[lowbit(st)]|e[st^lowbit(st)],b[st]=b[st>>1]+(st&1);
		if(!(e[st]&st)) c[st]=1;
	}
	for(int i=0;i<cnt;++i)for(int j=0;j<1<<cnt;++j)if((j>>i)&1)add(c[j],c[j^(1<<i)]);
	for(int j=0;j<1<<cnt;++j)d[j]=(cnt-b[j])&1?mod-1:1;
	for(int i=0;i<=cnt;++i)
	{
		int cur=0;for(int j=0;j<1<<cnt;++j)add(cur,d[j]);
		if(cur)return printf("%d\n",n-1+i),0;
		for(int j=0;j<1<<cnt;++j)d[j]=1LL*d[j]*c[j]%mod;
	}
	return 0;
}