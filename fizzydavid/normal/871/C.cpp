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
int n;
map<int,int> mpx,mpy;
int tot;
int getidx(int v)
{
	int &id=mpx[v];
	if(id==0)id=++tot;
	return id;
}
int getidy(int v)
{
	int &id=mpy[v];
	if(id==0)id=++tot;
	return id;
}
int cmk;
ll cur;
bool cyc;
ll pw[200111];
int mk[200111];
vector<int>con[200111];
void dfs(int x,int pre=-1)
{
	mk[x]=cmk;
	cur=cur*2%mod;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		if(!mk[u])
		{
			dfs(u,x);
		}
		else if(mk[u]==mk[x])
		{
			cyc=1;
		}
	}
}
int main()
{
	pw[0]=1;
	for(int i=1;i<=200005;i++)pw[i]=pw[i-1]*2%mod;
	geti(n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		getii(x,y);
		x=getidx(x);
		y=getidy(y);
		con[x].PB(y);
		con[y].PB(x);
	}
	ll ans=1;
	for(int i=1;i<=tot;i++)
	{
		if(!mk[i])
		{
			cmk=i;cur=1;cyc=0;
			dfs(i);
			if(!cyc)cur=(cur-1+mod)%mod;
			ans=ans*cur%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}