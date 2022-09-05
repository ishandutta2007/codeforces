//by yjz
#include<bits/stdc++.h>
#include<ctime>
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
int head[300111],nxt[600111],to[600111],tot=1;
void adde(int x,int y)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
}
int pe[300111],lv[300111];
bool f[300111],vis[300111];
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(vis[to[i]])continue;
//		p[0][to[i]]=x;
//		lv[to[i]]=lv[x]+1;
		pe[to[i]]=i/2;
		dfs(to[i]);
	}
}
vector<int> v,ans;
void connect(int x,int y)
{
	f[x]^=1;
	f[y]^=1;
//	cerr<<"connect:"<<x<<" "<<y<<endl;
}

void sumup(int x)
{
//	cerr<<"x="<<x<<endl;
	for(int i=head[x];i;i=nxt[i])
	{
		if(pe[to[i]]==(i>>1))
		{
			sumup(to[i]);
			f[x]^=f[to[i]];
		}
	}
}
int main()
{
	getii(n,m);
	int sup=-1;
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		if(x==-1)sup=i;
		else if(x==1)v.PB(i);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		adde(x,y);
		adde(y,x);
	}
	dfs(1);
	if(sup==-1&&int(v.size())%2==1)
	{
		puts("-1");
		return 0;
	}
	if(int(v.size())%2==1)v.PB(sup);
	for(int i=0;i<v.size();i+=2)connect(v[i],v[i+1]);
	sumup(1);
	for(int i=1;i<=n;i++)if(f[i])ans.PB(pe[i]);
	sort(ans.begin(),ans.end());
	putsi(ans.size());
	for(int i=0;i<ans.size();i++)putsi(ans[i]);
	return 0;
}