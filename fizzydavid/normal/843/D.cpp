//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,m,q;
int head[100111],nxt[100111],to[100111],w[100111],tot;
int dis2[100111];
bool vis[100111];
set<pair<ll,int> >st;
ll dis[100111];
void prework()
{
	for(int i=2;i<=n;i++)dis[i]=Lbig;
	st.clear();
	st.insert(MP(0,1));
	dis[1]=0;
	memset(vis,0,sizeof(vis));
	while(st.size()>0)
	{
		int u=st.begin()->SS;
		st.erase(st.begin());
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
		{
			if(dis[u]+w[i]<dis[to[i]])
			{
				dis[to[i]]=dis[u]+w[i];
				st.insert(MP(dis[to[i]],to[i]));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			for(int j=head[i];j;j=nxt[j])
			{
				w[j]-=dis[to[j]]-dis[i];
			}
		}
	}
}
vector<int> v[1000111];
void update()
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=m;i++)v[i].clear();
	for(int i=1;i<=n;i++)dis2[i]=mod;
	v[0].PB(1);
	dis2[1]=0;
	for(int i=0;i<=m;i++)
	{
		for(int it=0;it<v[i].size();it++)
		{
			int u=v[i][it];
			if(vis[u])continue;
			vis[u]=1;
			for(int j=head[u];j;j=nxt[j])
			{
				if(i+w[j]<min(m+1,dis2[to[j]])&&!vis[to[j]])
				{
					v[i+w[j]].PB(to[j]);
					dis2[to[j]]=i+w[j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			for(int j=head[i];j;j=nxt[j])
			{
				w[j]-=dis2[to[j]]-dis2[i];
			}
		}
	}
	for(int i=1;i<=n;i++)if(dis2[i]!=mod)dis[i]+=dis2[i];
	m=0;
}
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	getiii(n,m,q);
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		getiii(x,y,c);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		w[tot]=c;
	}
	m=0;
	prework();
	for(int i=1;i<=q;i++)
	{
		int cmd;
		geti(cmd);
		if(cmd==1)
		{
			int x;
			geti(x);
			if(dis[x]==Lbig)
			{
				puts("-1");
			}
			else
			{
				update();
				putsi(dis[x]);
			}
		}
		else
		{ 
			int k;
			geti(k);m+=k;
			while(k--)
			{
				int x;
				geti(x);
				w[x]++;
			}
		}
	}
	return 0;
}