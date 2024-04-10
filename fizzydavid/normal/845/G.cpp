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
int n,m;
vector<pair<int,int> >con[100111];
int path[100111];
int a[33],an;
bool vis[100111];
void add(int msk){
	for(int i=an-1;i>=0;i--)msk=min(msk,msk^a[i]);
	if(msk==0)return;
	a[an++]=msk;
	sort(a,a+an);
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(vis[u])
		{
			add(path[x]^path[u]^con[x][i].SS);
			continue;
		}
		path[u]=path[x]^con[x][i].SS;
		dfs(u);
	}
}
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		getiii(x,y,w);
		con[x].PB(MP(y,w));
		con[y].PB(MP(x,w));
	}
	dfs(1);
	int ans=path[n];
	for(int i=an-1;i>=0;i--)ans=min(ans,ans^a[i]);
	cout<<ans<<endl;
	return 0;
}