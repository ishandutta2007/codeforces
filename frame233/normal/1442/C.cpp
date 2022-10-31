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

const int N=200005;
const int mod=998244353;
const int S=20;
std::vector<int> e[N],rev[N];
struct node{
	ll cnt,sum;
	inline bool operator != (const node &o)const
	{
		return cnt!=o.cnt||sum!=o.sum;
	}
	inline bool operator < (const node &o)const
	{
		if(cnt<=25&&o.cnt<=25) return (1LL<<cnt)+sum<(1LL<<o.cnt)+o.sum;
		return cnt==o.cnt?sum<o.sum:cnt<o.cnt;
	}
}dp[N][S+5];
int pos[N];
struct Node{
	int u;
	node d;
	inline bool operator < (const Node &o)const
	{
		return d.cnt==o.d.cnt?d.sum>o.d.sum:d.cnt>o.d.cnt;
	}
};
std::priority_queue<Node> q;
int main()
{
	int n,m;read(n,m);
	int x,y;
	for(int i=1;i<=m;++i) read(x,y),e[x].pb(y),rev[y].pb(x);
	for(int i=1;i<=n;++i) for(int j=0;j<=S;++j) dp[i][j]={-1LL,0LL};
	dp[1][++pos[1]]={0LL,0LL};
	q.push({1,dp[1][1]});
	while(!q.empty())
	{
		Node x=q.top();q.pop();
		if(x.d!=dp[x.u][pos[x.u]]) continue;
		if(pos[x.u]<S)
		{
			dp[x.u][++pos[x.u]]={x.d.cnt+1,x.d.sum};
			q.push({x.u,{x.d.cnt+1,x.d.sum}});
		}
		if(!(x.d.cnt&1))
		{
			for(auto v:e[x.u])
			{
				if(dp[v][pos[v]].cnt<x.d.cnt&&pos[v]<S)
				{
					dp[v][++pos[v]]={x.d.cnt,x.d.sum+1};
					q.push({v,dp[v][pos[v]]});
				}
				else if(dp[v][pos[v]].cnt==x.d.cnt&&x.d.sum+1<dp[v][pos[v]].sum)
				{
					dp[v][pos[v]]={x.d.cnt,x.d.sum+1};
					q.push({v,dp[v][pos[v]]});
				}
			}
		}
		else
		{
			for(auto v:rev[x.u])
			{
				if(dp[v][pos[v]].cnt<x.d.cnt&&pos[v]<S)
				{
					dp[v][++pos[v]]={x.d.cnt,x.d.sum+1};
					q.push({v,dp[v][pos[v]]});
				}
				else if(dp[v][pos[v]].cnt==x.d.cnt&&x.d.sum+1<dp[v][pos[v]].sum)
				{
					dp[v][pos[v]]={x.d.cnt,x.d.sum+1};
					q.push({v,dp[v][pos[v]]});
				}
			}
		}
	}
	node minn={inf,inf};
	for(int i=1;i<=pos[n];++i) minn=min(minn,dp[n][i]);
	int cur=1;
	while(minn.cnt--) cur=(cur+cur)%mod;
	cur+=minn.sum%mod;
	cur=(cur+mod-1)%mod;
	printf("%d\n",cur);
	return 0;
}