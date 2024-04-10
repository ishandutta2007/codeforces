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
pair<int,pair<int,int> > a[200111];
int mx[200111],f[200111];
bool used[200111];
set<pair<int,int> >st[200111],nst;
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void dfs(int x)
{
//	cerr<<"dfs:"<<x<<endl;
	used[x]=1;
	foreach(it,st[x])
	{
		int u=it->FF;
		if(mx[it->SS])continue;
		assert(!used[u]);
		mx[it->SS]=u;
		dfs(u);
	}
	st[x].clear();
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		getiii(a[i].SS.FF,a[i].SS.SS,a[i].FF);
	}
	sort(a+1,a+m+1);
	ll ans=0;
	for(int i=m;i>=1;i--)
	{
		int x=a[i].SS.FF,y=a[i].SS.SS;
//		cerr<<x<<" "<<y<<endl;
		if(used[x]&&used[y])continue;
		ans+=a[i].FF;
		if(used[x])
		{
			mx[i]=y;
			dfs(y);
		}
		else if(used[y])
		{
			mx[i]=x;
			dfs(x);
		}
		else
		{
			if(gf(x)!=gf(y))
			{
				f[gf(x)]=gf(y);
				st[x].insert(MP(y,i));
				st[y].insert(MP(x,i));
			}
			else
			{
				mx[i]=x;
				dfs(x);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}