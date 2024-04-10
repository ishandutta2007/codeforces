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
set<pair<int,int> > st[10];
int n,k,a[50111][10];
int sz[50111],f[50111],fmn[50111][10],fmx[50111][10];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void un(int x,int y)
{
//	cerr<<"un:"<<x<<","<<y<<endl;
	x=gf(x);y=gf(y);
	if(x==y)return;
	f[x]=y,sz[y]+=sz[x];
	for(int i=0;i<k;i++)fmn[y][i]=min(fmn[y][i],fmn[x][i]);
	for(int i=0;i<k;i++)fmx[y][i]=max(fmx[y][i],fmx[x][i]);
}
void del(int id)
{
	for(int i=0;i<k;i++)st[i].erase(MP(fmx[id][i],id));
}
void add(int id)
{
	for(int i=0;i<k;i++)st[i].insert(MP(fmx[id][i],id));
}
int rt;
void updatert()
{
	bool flag=1;
	while(flag)
	{
		flag=0;
		for(int i=0;i<k;i++)
		{
			if(st[i].size()>0&&(--st[i].end())->FF>fmn[rt][i])
			{
				flag=1;
				int tid=(--st[i].end())->SS;
				del(tid);
				un(tid,rt);
				rt=gf(rt);
				break;
			}
		}
	}
}
int main()
{
	getii(n,k);
	for(int i=0;i<n;i++)f[i]=i,sz[i]=1;
	rt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)geti(a[i][j]),fmn[i][j]=fmx[i][j]=a[i][j];
		if(i>0)
		{
			if(a[i][0]>fmx[rt][0])
			{
				add(rt);
				rt=i;
				updatert();
			}
			else add(i);
		}
		updatert();
		putsi(sz[rt]);
	}
	return 0;
}