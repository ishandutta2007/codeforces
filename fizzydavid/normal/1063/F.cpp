//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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
const int maxn=1000111;
char s[maxn];
int n,dp[maxn];
int tot=1,go[maxn][26],pre[maxn],len[maxn],st[maxn];
int fa[20][maxn];
vector<int> son[maxn];
int append(int p,char ch)
{
	int c=ch-'a';
	int np=++tot;
	len[np]=len[p]+1;
	while(p&&!go[p][c])go[p][c]=np,p=pre[p];
	if(!p)
	{
		pre[np]=1;
		return np;
	}
	int q=go[p][c];
	if(len[q]==len[p]+1)pre[np]=q;
	else
	{
		int nq=++tot;
		len[nq]=len[p]+1;
		pre[nq]=pre[q];
		pre[q]=pre[np]=nq;
		for(int i=0;i<26;i++)go[nq][i]=go[q][i];
		while(p&&go[p][c]==q)go[p][c]=nq,p=pre[p];
	}
	return np;
}
void prework()
{
	int p=1;
	for(int i=n;i>=1;i--)
	{
		p=append(p,s[i]);
		st[i]=p;
	}
	for(int i=1;i<=tot;i++)fa[0][i]=pre[i];
	for(int i=1;i<20;i++)for(int j=1;j<=tot;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
}
bool vis[maxn];
int T,vit[maxn];
vector<pair<int,int> > v[maxn];
void addv(int ti,int p,int l)
{
	if(v[p].size()==0||l>v[p].back().FF)v[p].PB(MP(l,ti));
}
void add(int ti,int p,int l)
{
	for(int i=19;i>=0;i--)if(fa[i][p]>0&&len[fa[i][p]]>=l)p=fa[i][p];
	addv(ti,p,l);
	p=pre[p];
	while(p&&!vis[p])
	{
		vis[p]=1;
		addv(ti,p,len[p]);
		p=pre[p];
	}
}
int queryp(int x)
{
	int &it=vit[x];
	while(it<v[x].size()&&T<=v[x][it].SS-v[x][it].FF-1)it++;
	int ret=0;
	if(it>0)ret=v[x][it-1].FF;
	if(it<v[x].size())ret=max(ret,min(v[x][it].SS-T-1,v[x][it].FF));
	return ret;
}
int query(int p)
{
	for(int i=19;i>=0;i--)
	{
		if(fa[i][p]&&queryp(fa[i][p])<len[fa[i][p]])p=fa[i][p];
	}
	int ret=0;
	if(pre[p])ret=len[pre[p]];
	return max(ret,queryp(p));
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	prework();
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		T=i;
		dp[i]=query(st[i])+1;
		if(i<n)dp[i]=max(dp[i],query(st[i+1])+1);
		add(i,st[i],dp[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}