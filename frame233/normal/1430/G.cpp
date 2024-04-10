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

const int N=19;
int dp[N][N][1<<18];
int id[N][N][1<<18];
int a[N],n;
std::vector<int> e[N],r[N];
int ans[N];
void print(int i,int j,int st)
{
	if(!st) return;
	if(~id[i][j][st]) ans[id[i][j][st]]=j==0?i-1:i,st^=1<<id[i][j][st];
	if(j) print(i,j-1,st);
	else print(i-1,n-1,st);
}
int _q[N],_l,_r;
int t[N],dg[N];
bool valid[1<<18][N];
int main()
{
	int m;read(n,m);
	int x,y,z;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		--x,--y,++dg[y],a[x]+=z,a[y]-=z;
		e[x].pb(y),r[y].pb(x);
	}
	_l=1,_r=0;
	for(int i=0;i<n;++i) if(r[i].empty()) _q[++_r]=i;
	int pos=0;
	while(_l!=_r+1)
	{
		int x=_q[_l++];t[pos++]=x;
		for(auto v:e[x]) if(!--dg[v]) _q[++_r]=v;
	}
	memset(dp,63,sizeof(dp));
	dp[0][0][0]=0;
	for(int st=0;st<1<<n;++st)
	{
		for(int j=0;j<n;++j)
		{
			int qwq=t[j];
			if(!((st>>qwq)&1))
			{
				bool flag=true;
				for(auto it:e[qwq]) flag&=(st>>it)&1;
				for(auto it:r[qwq]) flag&=!((st>>it)&1);
				valid[st][j]=flag;
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			for(int st=0;st<1<<n;++st) dp[i][j+1][st]=dp[i][j][st],id[i][j+1][st]=-1;
			int qwq=t[j];
			for(int st=0;st<1<<n;++st)
			{
				if(valid[st][j]&&dp[i][j+1][st|(1<<qwq)]>dp[i][j][st]+1ll*i*a[qwq])
				{
					dp[i][j+1][st|(1<<qwq)]=dp[i][j][st]+1ll*i*a[qwq];
					id[i][j+1][st|(1<<qwq)]=qwq;
				}
			}
		}
		for(int st=0;st<1<<n;++st) dp[i+1][0][st]=dp[i][n][st],id[i+1][0][st]=id[i][n][st];
	}
	print(n,0,(1<<n)-1);
	for(int i=0;i<n;++i) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}