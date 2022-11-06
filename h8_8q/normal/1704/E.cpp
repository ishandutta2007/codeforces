#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>
 
#define int long long
 
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f
 
using namespace std;
 
inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}
 
inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}
 
template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}
 
const int N=2e5+5,mod=998244353;
int t,n,m,a[N],du1[N],du2[N],id[N];
 
struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;
 
inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}
 
struct Node
{
	int l,r,tg;
	bool operator < (const Node &x)const
	{
		return l<x.l;
	}
};
 
vector<Node> hv[N];
 
void prework()
{
	int cnt=0;
	queue<int> qu;
	for(int i=1;i<=n;++i)
		if(!du1[i]) qu.push(i);
	while(!qu.empty())
	{
		int u=qu.front();
		qu.pop();id[++cnt]=u;
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(e[i].w!=0)
				continue;
			du1[v]--;
			if(!du1[v])
				qu.push(v);
		}
	}
}
 
signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=m;++i)
		{
			int u=read(),v=read();
			add(u,v,0);add(v,u,1);
			du1[v]++;du2[u]++;
		}
		int ps=-1;
		for(int i=1;i<=n;++i)
			if(du2[i]==0)
				ps=i;
		prework();
		for(int i=1;i<=n;++i)
		{
			int u=id[i];
			vector<Node> tmp;
			for(int j=head[u];j;j=e[j].ne)
			{
				int v=e[j].v;
				if(e[j].w!=1)
					continue;
				for(auto k:hv[v])
					tmp.push_back(k);
			}
			sort(tmp.begin(),tmp.end());
			int nl=0,nr=0,ntg=0;
			if(a[u])
			{
				nl=1,nr=a[u];
				if(nr>n) ntg=1;
				nr%=mod;
			}
			for(auto j:tmp)
			{
				int l=j.l,r=j.r,tg=j.tg;
				l++;r=(r+1)%mod;
				if(ntg||nr+1>=l)
				{
					nr=(nr+r-l+1)%mod;
					if(tg) ntg=1;
					else if(!ntg&&nr+r-l+1>n) ntg=1;
				}
				else
				{
					if(nl)
						hv[u].push_back((Node){nl,nr,ntg});
					nl=l;nr=r;ntg=tg;
				}
			}
			if(nl) hv[u].push_back((Node){nl,nr,ntg});
		}
		int ans;
		if(hv[ps].empty()) ans=0;
		else ans=hv[ps].back().r;
		write(ans);puts("");
		for(int i=1;i<=n;++i)
			head[i]=0,hv[i].clear(),du1[i]=du2[i]=0;
		tot=0;
	}
	return 0;
}