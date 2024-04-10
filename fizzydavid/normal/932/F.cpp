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
struct point//integer
{
	ll x,y;
	point(ll X=0,ll Y=0){x=X;y=Y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	ll det(const point &t)const
	{
		double tmp=1.0*x*t.y-1.0*y*t.x;
		if(tmp>1e18)return 1e18;
		if(tmp<-1e18)return -1e18;
		return x*t.y-y*t.x;
	}
	bool operator<(const point &t)const{return MP(x,y)<MP(t.x,t.y);}
};
struct point_cmp
{
	point p;
	bool operator<(const point_cmp &t)const{return p.det(t.p)>0;}
};
point_cmp mkcmp(const point &p){point_cmp ret;ret.p=p;return ret;}
struct DynamicConvexHull
{
	set<point> a;
	int type;//1 up  -1 down
	set<pair<point_cmp,point> > st;
	#define checkt(p,q,r) ((q)-(p)).det((r)-(p))*type>=0
	void del(set<point>::iterator it)
	{
		point pre,nxt;
		bool ip=0,in=0;
		if(it!=a.begin())it--,ip=1,pre=*it,it++;
		it++;if(it!=a.end())in=1,nxt=*it;it--;
		if(ip)st.erase(MP(mkcmp(*it-pre),pre));
		if(in)st.erase(MP(mkcmp(nxt-*it),*it));
		if(ip&&in)st.insert(MP(mkcmp(nxt-pre),pre));
		a.erase(it);
	}
	void ins(point p)
	{
		a.insert(p);
		point pre,nxt;
		set<point>::iterator it=a.lower_bound(p);
		bool ip=0,in=0;
		if(it!=a.begin())it--,ip=1,pre=*it,it++;
		it++;if(it!=a.end())in=1,nxt=*it;it--;
		if(ip)st.insert(MP(mkcmp(*it-pre),pre));
		if(in)st.insert(MP(mkcmp(nxt-*it),*it));
		if(ip&&in)st.erase(MP(mkcmp(nxt-pre),pre));
	}
	void insert(point p)
	{
		if(a.find(p)!=a.end())return;
		if(a.size()>=2)
		{
			set<point>::iterator i,j=a.lower_bound(p),ni;
			if(j!=a.end()&&j!=a.begin())
			{
				i=j;i--;
				if(checkt(*i,p,*j))return;
			}
			i=j;ni=i;if(ni!=a.end())ni++;
			for(;ni!=a.end();i=ni,ni++)
			{
				if(checkt(p,*i,*ni))del(i);
			}
			i=a.lower_bound(p);if(i!=a.begin())i--;
			ni=i;if(ni!=a.begin())ni--;
			for(;i!=ni;i=ni,ni--)
			{
				if(checkt(*ni,*i,p))del(i);
				if(ni==a.begin())break;
			}
		}
		ins(p);
	}
	ll querymn(ll k)//(x,y) k*x+y
	{
		assert(type==-1);
		ll ret=9e18;
		if(a.size()==0)return ret;
		if(a.size()==1)return k*a.begin()->x+a.begin()->y;
		pair<point_cmp,point> tmp=MP(mkcmp(point(1,-k)),point(0,0));
		set<pair<point_cmp,point> >::iterator it=st.lower_bound(tmp);
		if(it==st.end())it--;
		assert(st.size()>0);
		point p=it->SS;
		ret=min(ret,k*p.x+p.y);
		p=p+it->FF.p;
		ret=min(ret,k*p.x+p.y);
		return ret;
	}
};
ll a[100111],b[100111];
vector<int> con[100111];
int n;
ll dp[100111];
int sz[100111];
int dfn[100111],dfnr[100111],arr[100111],dtot;
DynamicConvexHull dfs(int x,int pre=-1)
{
	dfn[x]=++dtot;arr[dtot]=x;
	DynamicConvexHull ret;
	ret.type=-1;
	if(con[x].size()==1&&pre!=-1)
	{
		dp[x]=0;
		ret.insert(point(b[x],dp[x]));
		dfnr[x]=dtot;
		return ret;
	}
	sz[x]=1;
	int mxs=0;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		DynamicConvexHull tmp=dfs(u,x);
		if(sz[u]>sz[mxs])
		{
			mxs=u;
			ret=tmp;
		}
		sz[x]+=sz[u];
	}
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||u==mxs)continue;
		for(int j=dfn[u];j<=dfnr[u];j++)ret.insert(point(b[arr[j]],dp[arr[j]]));
	}
	dp[x]=ret.querymn(a[x]);
	ret.insert(point(b[x],dp[x]));
	dfnr[x]=dtot;
	return ret;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<=n;i++)geti(b[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++)puti(dp[i]);
	return 0;
}