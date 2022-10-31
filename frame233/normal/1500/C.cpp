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

const int N=1505;
int a[N][N],d[N][N],b[N][N],n,m,c[N],rest[N],p;
bool mark[N],vis[N];
int main()
{
	read(n,m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)read(a[i][j]);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)read(b[i][j]);
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<n;++j)c[i]+=b[j][i]>b[j+1][i];
		if(!c[i])rest[++p]=i,vis[i]=true;
	}
	std::vector<int> v;
	mark[1]=mark[n+1]=true;
	while(p)
	{
		int x=rest[p--];
		v.pb(x);
		for(int i=1;i<=n;++i)
		{
			int j=i;while(!mark[j+1]&&b[j+1][x]==b[j][x])++j;
			if(!mark[j+1])
			{
				mark[j+1]=true;
				for(int k=1;k<=m;++k)if(!vis[k]&&!(c[k]-=b[j][k]>b[j+1][k]))vis[k]=true,rest[++p]=k;
			}
			i=j;
		}
	}
	std::reverse(v.begin(),v.end());
	std::vector<int> tp(n);std::iota(tp.begin(),tp.end(),1);
	for(auto it:v)std::stable_sort(tp.begin(),tp.end(),[&](int A,int B)->bool{return a[A][it]<a[B][it];});
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(b[i][j]!=a[tp[i-1]][j])return puts("-1"),0;
	printf("%d\n",SZ(v));
	for(auto it:v)printf("%d ",it);
	printf("\n");
	return 0;
}