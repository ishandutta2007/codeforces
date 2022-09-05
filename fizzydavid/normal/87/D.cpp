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
int lv[100111];
struct edge
{
	int x,y,l,id;
	bool operator<(const edge &t)const
	{
		if(l!=t.l)return l<t.l;
		return lv[x]>lv[t.x];
	}
}e[100111];
vector<int>con[100111];
void dfs(int x,int pre=-1)
{
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		lv[u]=lv[x]+1;
		dfs(u,x);
	}
}
int f[100111],sz[100111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void un(int x,int y)
{
	x=gf(x);y=gf(y);
	f[y]=x;
	sz[x]+=sz[y];
}
ll lsz[100111],rsz[100111];
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	for(int i=1;i<n;i++)
	{
		int x,y,l;
		getiii(x,y,l);
		e[i].x=x;
		e[i].y=y;
		e[i].l=l;
		e[i].id=i;
		con[x].PB(y);
		con[y].PB(x);
	}
	lv[1]=1;
	dfs(1);
	for(int i=1;i<n;i++)
	{
		if(lv[e[i].x]<lv[e[i].y])swap(e[i].x,e[i].y);
	}
	sort(e+1,e+n);
	for(int i=1;i<n;)
	{
		int r=i;
		while(e[r].l==e[i].l)r++;
		for(int j=i;j<r;j++)
		{
			int x=e[j].x,y=e[j].y;
			lsz[j]=sz[gf(x)];
			un(x,y);
		}
		for(int j=i;j<r;j++)
		{
			int x=e[j].x,y=e[j].y;
			rsz[j]=sz[gf(x)]-lsz[j];
		}
		i=r;
	}
	ll mx=0,cnt=0;
	for(int i=1;i<n;i++)
	{
//		cerr<<lsz[i]<<","<<rsz[i]<<endl;
		if(lsz[i]*rsz[i]>mx)
		{
			mx=lsz[i]*rsz[i];cnt=1;
		}
		else if(lsz[i]*rsz[i]==mx)
		{
			cnt++;
		}
	}
	vector<int>v;
	for(int i=1;i<n;i++)if(1ll*lsz[i]*rsz[i]==mx)v.PB(e[i].id);
	sort(v.begin(),v.end());
	putsii(mx*2,cnt);
	for(int i=0;i<v.size();i++)puti(v[i]);
	return 0;
}