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
const ll hsmx=2000111;
const ll hssz=2000001;
struct hashtable
{
	ll key[hsmx];
	int v[hsmx];
	void init()
	{
		memset(key,-1,sizeof(key));
	}
	hashtable(){init();}
	int& getv(ll hs)
	{
		int p=hs%hssz;
		while(key[p]!=-1&&key[p]!=hs)p=p+1>=hssz?p+1-hssz:p+1;
		if(key[p]==-1)key[p]=hs,v[p]=-1;
		return v[p];
	}
	int find(ll hs)
	{
		int p=hs%hssz;
		while(key[p]!=-1&&key[p]!=hs)p=p+1>=hssz?p+1-hssz:p+1;
		if(key[p]==-1)return -1;
		return v[p];
	}
}hstab;
int n;
int head[500111],nxt[1000111],to[1000111],tot=1;
int head2[500111],nxt2[1000111],to2[1000111],tot2=1;
int f[500111];
bool oc[500111],oc2[500111];
void adde(int x,int y)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
}
void adde2(int x,int y)
{
	nxt2[++tot2]=head2[x];
	head2[x]=tot2;
	to2[tot2]=y;
}
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int nid[500111];
void dfs(int x,int p=-1)
{
	for(int i=head[x];i;i=nxt[i])
	{
		int u=to[i];
		if(u==p)continue;
		dfs(u,x);
		if(oc[i>>1])continue;
		int tmp=nid[gf(u)];
		if(!tmp)continue;
		putii(u,x);
		putsii(to2[tmp],to2[tmp^1]);
	}
}
void dfs2(int x,int p=-1)
{
	for(int i=head2[x];i;i=nxt2[i])
	{
		int u=to2[i];
		if(u==p)continue;
		if(!oc2[i>>1])nid[gf(u)]=i;
		dfs2(u,x);
	}
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		if(x>y)swap(x,y);
		hstab.getv((1ll*x)<<40|(1ll*y)<<10)=i;
		adde(x,y);
		adde(y,x);
	}
	int cnt=n-1;
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		if(x>y)swap(x,y);
		int tmp=hstab.find((1ll*x)<<40|(1ll*y)<<10);
		if(tmp!=-1)
		{
			oc[tmp]=1;
			oc2[i]=1;
			cnt--;
			f[gf(x)]=gf(y);
		}
		adde2(x,y);
		adde2(y,x);
	}
	dfs2(1);
	putsi(cnt);
	dfs(1);
	return 0;
}