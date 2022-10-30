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

const int N=205;
int mp[N][N],dis[N][N];
struct edge{
	int v,nxt;
}c[4005];
int front[N],edge_cnt;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int col[N];
bool dfs(int x,int C)
{
	if(~col[x]) return col[x]==C;
	col[x]=C;
	for(int i=front[x];i;i=c[i].nxt) if(!dfs(c[i].v,!C)) return false;
	return true;
}
int main()
{
	memset(col,255,sizeof(col));
	memset(mp,63,sizeof(mp));
	int n,m;read(n,m);
	int x,y,z;
	for(int i=1;i<=n;++i) mp[i][i]=0;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z),addedge(x,y),addedge(y,x);
		if(z) mp[x][y]=1,mp[y][x]=-1;
		else mp[x][y]=mp[y][x]=1;
	}
	if(!dfs(1,0)) return puts("NO"),0;
	memcpy(dis,mp,sizeof(dis));
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)chmin(dis[i][j],dis[i][k]+dis[k][j]);
	bool flag=true;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) flag&=dis[i][k]+dis[k][j]>=dis[i][j];
	if(!flag) return puts("NO"),0;
	int maxx=-1,id=0;
	for(int i=1;i<=n;++i)
	{
		int tmp=*std::max_element(dis[i]+1,dis[i]+n+1);
		if(tmp>maxx) maxx=tmp,id=i;
	}
	puts("YES");
	printf("%d\n",maxx);
	for(int i=1;i<=n;++i) printf("%d%c",dis[id][i]," \n"[i==n]);
	return 0;
}