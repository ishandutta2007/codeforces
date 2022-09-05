//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define SZ(x) int((x).size())
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
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,m;
vector<int> con[300111],ncon[300111],ANS;
int dis[300111],pre[300111];
int q[300111],qn;
void pre_bfs(int S)
{
	qn=0;
	q[qn++]=S;
	memset(dis,-1,sizeof(dis));
	dis[S]=0;
	for(int i=0;i<qn;i++)
	{
		int u=q[i];
		for(int j=0;j<con[u].size();j++)
		{
			int v=con[u][j];
			if(dis[v]==-1)
			{
				dis[v]=dis[u]+1;
				pre[v]=u;
				q[qn++]=v;
			}
		}
	}
}
bool mk[300111];
int id[300111];
bool f[300111];
bool solve(int S)
{
	qn=0;
	q[qn++]=S;
	mk[S]=1;
	for(int i=0;i<qn;i++)
	{
		int u=q[i];
		id[u]=i;
		for(int j=0;j<ncon[u].size();j++)
		{
			int v=ncon[u][j];
			if(id[v]!=-1)f[id[v]]=1;
			if(!mk[v])
			{
				mk[v]=1;
				q[qn++]=v;
			}
		}
		for(int j=0;j+1<i;j++)
		{
			if(f[j]^f[j+1])
			{
				assert(i>=2);
				int to=j,nto=j+1;
				if(!f[to])swap(to,nto);
				ANS.clear();
				ANS.PB(1);
				ANS.PB(u);
				ANS.PB(q[to]);
				ANS.PB(q[nto]);
				ANS.PB(u);
				ANS.PB(n);
				return true;
			}
		}
		for(int j=0;j<i;j++)f[j]=0;
	}
	for(int i=0;i<qn;i++)id[q[i]]=-1;
	return false;
}
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	pre_bfs(1);
	if(dis[n]!=-1)
	{
		int T=n;
		while(T!=1)
		{
			ANS.PB(T);
			T=pre[T];
		}
		ANS.PB(1);
		reverse(ANS.begin(),ANS.end());
	}
	if(ANS.size()>4||ANS.size()==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(dis[i]==2)
			{
				ANS.clear();
				ANS.PB(1);
				ANS.PB(pre[i]);
				ANS.PB(i);
				ANS.PB(1);
				ANS.PB(n);
				break;
			}
		}
	}
	if(ANS.size()>5||ANS.size()==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(dis[i]!=1)continue;
			for(int j=0;j<con[i].size();j++)
			{
				if(dis[con[i][j]]!=1)continue;
				ncon[i].PB(con[i][j]);
			}
		}
		memset(id,-1,sizeof(id));
		for(int i=1;i<=n;i++)
		{
			if(dis[i]!=1)continue;
			if(!mk[i])
			{
				if(solve(i))break;
			}
		}
	}
	if(ANS.size()==0)puts("-1");
	else
	{
		putsi(int(ANS.size())-1);
		for(int i=0;i<ANS.size();i++)puti(ANS[i]);
	}
	return 0;
}