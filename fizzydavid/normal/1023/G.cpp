//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
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
const int maxn=100111;
int CURT;
struct Function
{
	#define Qv(M,x) ((M).find(x)==(M).end()?0:M[x])
	int T;
	void UPDT(){CURT=T;}
	struct element
	{
		int x,v;
		element(int X=0,int V=0){x=X;v=V;}
		inline int getT()const{return v>0?x-CURT:x+CURT;}
		bool operator<(const element &t)const
		{
			if(getT()!=t.getT())return getT()<t.getT();
			return v<t.v;
		}
	};
	int get_element_T(const element &t){UPDT();return t.getT();}
	unordered_map<int,int> M[2];//0-negative 1-positive
	set<element> all;
	set<pair<int,pair<int,int> > > st;
	void debug(int id)
	{
		UPDT();
		cerr<<"Debug "<<id<<" T="<<T<<endl;
		for(set<element>::iterator it=all.begin();it!=all.end();it++)cerr<<it->getT()<<","<<it->v<<" ";cerr<<endl;
		for(auto it:M[0])cerr<<it.FF<<","<<it.SS<<" ";cerr<<endl;
		for(auto it:M[1])cerr<<it.FF<<","<<it.SS<<" ";cerr<<endl;
	}
	void add_relation(int x,int y)
	{
		int t=(y-x+1)/2;
		assert(t>0);
		st.insert(MP(t,MP(x,y)));
	}
	void all_insert(element x)
	{
		if(x.v==0)return;
		UPDT();
		all.insert(x);
		set<element>::iterator it=all.find(x);
		if(x.v>0&&it!=all.begin())
		{
			it--;
			if(it->v<0)add_relation(it->x,x.x);
		}
		else if(x.v<0)
		{
			it++;
			if(it!=all.end()&&it->v>0)add_relation(x.x,it->x);
		}
	}
	void all_del(element x)
	{
		if(x.v==0)return;
		UPDT();
		set<element>::iterator it=all.find(x),it0=it,it1=it0;
		assert(it!=all.end());
		it1++;
		if(it0!=all.begin()&&it1!=all.end())
		{
			it0--;
			if(it0->v<0&&it1->v>0)add_relation(it0->x,it1->x);
		}
		all.erase(x);
	}
	void add(int t,int p,int v)
	{
		if(v==0)return;
		int cur=0;
		if(M[t].find(p)!=M[t].end())all_del(element(p,M[t][p])),cur=M[t][p];
		M[t][p]=cur+v;
		all_insert(element(p,M[t][p]));
	}
	void Add(int x,int v)
	{
		if(v==0)return;
		int t=v>0,p,q;
		if(t)p=x+T,q=x-T;else p=x-T,q=x+T;
		int qval=Qv(M[t^1],q);
		if(qval)
		{
			if(abs(qval)>=abs(v))add(t^1,q,v),v=0;
			else add(t^1,q,-qval),v+=qval;
		}
		add(t,p,v);
		assert((Qv(M[t],p)!=0)+(Qv(M[t^1],q)!=0)<=1);
	}
	
	void merge(int x,int y)
	{
		if(M[0].find(x)!=M[0].end()&&M[1].find(y)!=M[1].end())
		{
			int dlt=min(-M[0][x],M[1][y]);
			assert(dlt>=0);
			add(0,x,dlt);
			add(1,y,-dlt);
		}
	}
	void go(int dt)
	{
		int nT=T+dt;
		while(st.size()>0&&st.begin()->FF<=nT)
		{
			merge(st.begin()->SS.FF,st.begin()->SS.SS);
			st.erase(st.begin());
		}
		T=nT;
	}
	int getmx()
	{
		UPDT();
		int v=0,mx=0;
		for(set<element>::iterator it=all.begin();it!=all.end();it++)
		{
			v+=it->v;
			mx=max(mx,v);
		}
		return mx;
	}
	int getdlt(int x)
	{
		return Qv(M[0],x-T)+Qv(M[1],x+T);
	}
	int getndlt(int x,int f)
	{
		int d0=getdlt(x);
		int d1=getdlt(x+1);
		return max(0,f-max(0,max(0-d0,d1)));
	}
}yxg[maxn*2];
int tot;
int Merge(int x,int y)
{
	if(yxg[x].all.size()>yxg[y].all.size())return Merge(y,x);
//	cerr<<"======Merge:"<<endl;
//	yxg[x].debug(x);
//	yxg[y].debug(y);
//	cerr<<"------------"<<endl;
	for(set<Function::element>::iterator it=yxg[x].all.begin();it!=yxg[x].all.end();it++)
	{
		yxg[y].Add(yxg[x].get_element_T(*it),it->v);
	}
//	yxg[y].debug(y);
//	cerr<<"==========="<<endl;
	return y;
}
int n,m;
vector<pair<int,int> > con[maxn];
vector<pair<int,int> > v[maxn];
int id[maxn];
void dfs(int x,int pre=-1)
{
//	cerr<<"dfs:"<<x<<endl;
	id[x]=0;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(u==pre)continue;
		dfs(u,x);
		yxg[id[u]].go(con[x][i].SS*2-1);
		if(id[x]==0)id[x]=id[u];
		else id[x]=Merge(id[x],id[u]);
	}
	if(id[x]==0)id[x]=++tot;
	if(x!=1)
	{
		vector<int> V;
		for(int i=0;i<v[x].size();i++)
		{
			int d=v[x][i].FF;
			int f=v[x][i].SS;
			V.PB(yxg[id[x]].getndlt(d*2,f));
//			cerr<<"ndlt="<<yxg[id[x]].getndlt(d*2,f)<<endl;
		}
		yxg[id[x]].go(1);
		for(int i=0;i<v[x].size();i++)
		{
			int d=v[x][i].FF;
			int f=v[x][i].SS;
			yxg[id[x]].Add(d*2,V[i]);
			yxg[id[x]].Add(d*2+1,-V[i]);
		}
	}
	else
	{
		for(int i=0;i<v[x].size();i++)
		{
			int d=v[x][i].FF;
			int f=v[x][i].SS;
			yxg[id[x]].Add(d*2,f);
			yxg[id[x]].Add(d*2+1,-f);
		}
	}
//	cerr<<"_____________"<<x<<" "<<yxg[id[x]].getmx()<<endl;
//	yxg[id[x]].debug(x);
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y,d;
		getiii(x,y,d);
		con[x].PB(MP(y,d));
		con[y].PB(MP(x,d));
	}
	geti(m);
	for(int i=1;i<=m;i++)
	{
		int d,f,p;
		getiii(d,f,p);
		v[p].PB(MP(d,f));
	}
	dfs(1);
	int ans=yxg[id[1]].getmx();
	cout<<ans<<endl;
	return 0;
}