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
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
struct dsu
{
	int f[500111],sz[500111],tmp[1500111],tn;
	dsu()
	{
		for(int i=0;i<500111;i++)f[i]=i,sz[i]=1;
		tn=0;
	}
	int gf(int x)
	{
		return f[x]==x?x:gf(f[x]);
	}
	void un(int x,int y)
	{
		x=gf(x);y=gf(y);
		if(x==y)return;
		if(sz[x]>sz[y])swap(x,y);
		tmp[tn++]=x;
		tmp[tn++]=f[x];
		tmp[tn++]=y;
		f[x]=y;
		sz[y]+=sz[x];
	}
	void rollback(int v)
	{
		for(int i=tn-3;i>=v;i-=3)
		{
			f[tmp[i]]=tmp[i+1];
			sz[tmp[i+2]]-=sz[tmp[i]];
		}
		tn=v;
	}
}d;
int n,m;
int px[500111],py[500111],pv[500111];
struct edge
{
	int x,y,v,id;
	bool operator<(const edge &t)const
	{
		return v<t.v;
	}
}e[500111];
int it[500111];
vector<pair<int,int> > qr[500111],qv;
bool ans[500111];
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y,v;
		getiii(x,y,v);
		e[i].x=x;
		e[i].y=y;
		e[i].v=v;
		e[i].id=i;
		px[i]=x;
		py[i]=y;
		pv[i]=v;
	}
	sort(e+1,e+m+1);
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int k;
		geti(k);
		for(int j=1;j<=k;j++)
		{
			int id;
			geti(id);
			qr[i].PB(MP(pv[id],id));
			qv.PB(MP(pv[id],i));
		}
		sort(qr[i].begin(),qr[i].end());
	}
	sort(qv.begin(),qv.end());
	int qvit=0;
	for(int i=1;i<=m;)
	{
		int r=i;
		while(r<=m&&e[r].v==e[i].v)r++;
		while(qvit<qv.size()&&qv[qvit].FF==e[i].v)
		{
			int id=qv[qvit].SS;
			if(it[id]<qr[id].size()&&qr[id][it[id]].FF==e[i].v)
			{
				int ver=d.tn;
				while(it[id]<qr[id].size()&&qr[id][it[id]].FF==e[i].v)
				{
					int t=qr[id][it[id]].SS;
					if(d.gf(px[t])==d.gf(py[t]))ans[id]=1;
					d.un(px[t],py[t]);
					it[id]++;
				}
				d.rollback(ver);
			}
			qvit++;
		}
		for(int j=i;j<r;j++)
		{
			d.un(e[j].x,e[j].y);
		}
		
		i=r;
	}
	for(int i=1;i<=q;i++)if(!ans[i])puts("YES");else puts("NO");
	return 0;
}