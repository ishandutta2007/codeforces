//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x)
#define putii(x,y) puti(x),putnum(y)
#define putiii(x,y,z) putii(x,y),putnum(z)
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}

struct edge
{
	int to,v,id;
};
edge make_edge(int to,int v,int id)
{
	edge tmp;
	tmp.to=to;
	tmp.v=v;
	tmp.id=id;
	return tmp;
}
int n;
ll sz[5011],dis[5011],ans,res=LINF;
vector<edge>con[5011];
pair<pair<int,int>,int>E[5011];
void dfs1(int x,int pre,ll &sum)
{
	sum+=dis[x];sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int v=con[x][i].to;
		if(v!=pre)
		{
			dis[v]=dis[x]+con[x][i].v;
			dfs1(v,x,sum);
			sz[x]+=sz[v];
		}
	}
}
ll dfs2(int x,int pre,ll sum,int t)
{
	ll ret=sum;
	for(int i=0;i<con[x].size();i++)
	{
		int v=con[x][i].to;
		if(v!=pre)
		{
			ret=min(ret,dfs2(v,x,sum-con[x][i].v*sz[v]+con[x][i].v*(sz[t]-sz[v]),t));
			ans+=con[x][i].v*sz[v]*(sz[t]-sz[v]);
		}
	}
	return ret;
}
int main()
{
	geti(n);
	int x,y,z;
	for(int i=1;i<n;i++)
	{
		getiii(x,y,z);
		con[x].PB(make_edge(y,z,i));
		con[y].PB(make_edge(x,z,i));
		E[i]=MP(MP(x,y),z);
	}
	for(int i=1;i<n;i++)
	{
		x=E[i].FF.FF,y=E[i].FF.SS,z=E[i].SS;
		dis[x]=dis[y]=0;
		ans=0;
		ll sum1=0,sum2=0;
		dfs1(x,y,sum1);
		dfs1(y,x,sum2);
		ans+=z*sz[x]*sz[y];
		ans+=dfs2(x,y,sum1,x)*sz[y];
		ans+=dfs2(y,x,sum2,y)*sz[x];
		res=min(res,ans);
	}
	putsi(res);
	return 0;
}