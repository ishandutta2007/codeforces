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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int B=524288;
struct SGT
{
	int a[B*2];
	void init()
	{
		memset(a,31,sizeof(a));
	}
	SGT(){init();}
	void mini(int x,int v)
	{
		x+=B;
		a[x]=min(a[x],v);
		for(int i=x>>1;i;i>>=1)a[i]=min(a[i<<1],a[i<<1|1]);
	}
	int query(int x,int y)
	{
		x+=B-1;y+=B+1;
		int ret=1e9;
		while(x^y^1)
		{
			if(~x&1)ret=min(ret,a[x^1]);
			if( y&1)ret=min(ret,a[y^1]);
			x>>=1;y>>=1;
		}
		return ret;
	}
}S1,S2;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int go[300111][4];
int n;
pair<int,int> p[300111];
map<pair<int,int>,int> mp;
int gou[300111],god[300111];
vector<int> con[300111];
void adde(int x,int y)
{
	con[x].PB(y);
	con[y].PB(x);
}
int cur_rt,cur_lv;
int dlv[300111],dfa[300111];
pair<int,int> ddis[20][300111];
int sz[300111],a[300111],an;
void pdfs(int x,int pre=-1)
{
	dlv[x]=cur_lv+1;
	a[an++]=x;
	sz[x]=gou[x]-god[x]+1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||dlv[u]<cur_lv)continue;
		pdfs(u,x);
		sz[x]+=sz[u];
	}
}
int findrt(int x)
{
	an=0;
	pdfs(x);
	int ret=x;
	for(int i=0;i<an;i++)
	{
		if(sz[a[i]]*2>=sz[x]&&sz[a[i]]<=sz[ret])ret=a[i];
	}
	return ret;
}
int q[300111],qn;

void bfs(int x,int lv)
{
	assert(lv<20);
	qn=0;
	for(int i=god[x];i<=gou[x];i++)
	{
		q[qn++]=i;
		ddis[lv][i]=MP(0,i);
	}
	for(int i=0;i<qn;i++)
	{
		int u=q[i];
		for(int d=0;d<4;d++)
		{
			int v=go[u][d];
			if(!v||dlv[god[v]]<cur_lv)continue;
			if(ddis[lv][v].SS==0)
			{
				ddis[lv][v]=MP(ddis[lv][u].FF+1,ddis[lv][u].SS);
				q[qn++]=v;
			}
		}
	}
}
int solve(int x,int lv)
{
//	cerr<<"solve:"<<x<<","<<lv<<endl;
	cur_lv=lv;
	int rt=findrt(x);
	dlv[rt]=lv;
//	cerr<<"rt="<<rt<<endl;
//	for(int i=1;i<=n;i++)cerr<<dlv[i]<<" ";cerr<<endl;
	bfs(rt,lv);
//	for(int i=1;i<=n;i++)cerr<<ddis[lv][i].FF<<","<<ddis[lv][i].SS<<" ";cerr<<endl;
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
		if(dlv[u]>=dlv[rt])
		{
			dfa[solve(u,lv+1)]=rt;
		}
	}
	return rt;
}
void Add(int x,int y)
{
	int id=mp[MP(x,y)];
	for(int p=god[id];p;p=dfa[p])
	{
		pair<int,int> dis=ddis[dlv[p]][id];
		assert(dis.SS>0);
		int h=dis.SS-god[dis.SS];
//		cerr<<p<<":"<<h<<" "<<dis.FF<<" "<<dis.SS<<endl;
		S1.mini(dis.SS,dis.FF+h);
		S2.mini(dis.SS,dis.FF-h);
	}
}
int Query(int x,int y)
{
//	cerr<<"Query:"<<x<<","<<y<<endl;
	int id=mp[MP(x,y)];
	int ret=1e9;
	for(int p=god[id];p;p=dfa[p])
	{
		pair<int,int> dis=ddis[dlv[p]][id];
		assert(dis.SS>0);
		int h=dis.SS-god[dis.SS];
//		cerr<<p<<":"<<h<<" "<<dis.FF<<" "<<dis.SS<<endl;
		ret=min(ret,S1.query(dis.SS,gou[dis.SS])-h+dis.FF);
		ret=min(ret,S2.query(god[dis.SS],dis.SS)+h+dis.FF);
	}
	if(ret>1e6)return -1;
	return ret;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		getii(x,y);
		p[i]=MP(x,y);
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
	{
		mp[MP(p[i].FF,p[i].SS)]=i;
		if(i==1||p[i-1].FF!=p[i].FF||p[i-1].SS!=p[i].SS-1)god[i]=i;
		else god[i]=god[i-1];
	}
	for(int i=n;i>=1;i--)gou[i]=i==n||god[i+1]!=god[i]?i:gou[i+1];
	
//	for(int i=1;i<=n;i++)cerr<<god[i]<<" ";cerr<<endl;
//	for(int i=1;i<=n;i++)cerr<<gou[i]<<" ";cerr<<endl;
	
	for(int i=1;i<=n;i++)
	{
		int g=god[i];
		int x=p[i].FF,y=p[i].SS;
		if(mp.find(MP(x-1,y))!=mp.end())adde(god[mp[MP(x-1,y)]],god[i]);
		if(mp.find(MP(x+1,y))!=mp.end())adde(god[mp[MP(x+1,y)]],god[i]);
		for(int d=0;d<4;d++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(mp.find(MP(nx,ny))!=mp.end())go[i][d]=mp[MP(nx,ny)];
		}
	}
	for(int i=1;i<=n;i++)
	{
		sort(con[i].begin(),con[i].end());
		con[i].erase(unique(con[i].begin(),con[i].end()),con[i].end());
	}
	
	solve(1,0);
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int t,x,y;
		getiii(t,x,y);
		if(t==1)Add(x,y);
		else putsi(Query(x,y));
	}
	return 0;
}