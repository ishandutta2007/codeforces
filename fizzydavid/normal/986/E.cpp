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
int n,ANS[100111];
vector<int> con[100111];
int dfn[100111],dfnr[100111],dtot,lv[100111],fa[20][100111],a[100111];

const int BITsz=100000+10;
struct BITadd
{
	ll a[BITsz];int tag[BITsz],ctag;
	void init(){memset(tag,0,sizeof(tag));ctag=1;}
	BITadd(){init();}
	void add(int p,ll x)
	{
		assert(p>0);
//		p=BITsz-5-p;
		for(int i=p;i<BITsz;i+=i&(-i))
		{
			if(tag[i]!=ctag)tag[i]=ctag,a[i]=0;
			a[i]=a[i]+x;
		}
	}
	ll query(int p)
	{
//		p=BITsz-5-p;
		ll ans=0;
		for(int i=p;i>0;i-=i&(-i))
		{
			if(tag[i]!=ctag)tag[i]=ctag,a[i]=0;
			ans=ans+a[i];
		}
		return ans;
	}
	void addseg(int l,int r,ll x)
	{
		add(l,x);add(r+1,-x);
	}
	void clear(){ctag++;}
}bit;

void pdfs(int x)
{
	dfn[x]=++dtot;
	for(int i=1;i<20;i++)fa[i][x]=fa[i-1][fa[i-1][x]];
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==fa[0][x])continue;
		fa[0][u]=x;
		lv[u]=lv[x]+1;
		pdfs(u);
	}
	dfnr[x]=dtot;
}
void init_tree()
{
	lv[1]=1;
	pdfs(1);
}
int get_lca(int x,int y)
{
	if(lv[x]>lv[y])swap(x,y);
	for(int i=19;i>=0;i--)if((lv[y]-lv[x])>=(1<<i))y=fa[i][y];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}

vector<pair<int,int> > factorize(int x)
{
	vector<pair<int,int> > v;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			int cnt=0;
			while(x%i==0)x/=i,cnt++;
			v.PB(MP(i,cnt));
		}
	}
	if(x>1)v.PB(MP(x,1));
	return v;
}
map<int,int> prid;
int prtot,ptab[1000111];
int getprid(int pr)
{
	int &v=prid[pr];
	if(v==0)v=++prtot,ptab[prtot]=pr;
	return v;
}
int pu[100111],pv[100111],pp[100111];
vector<pair<int,int> > cmd[1000111];
vector<pair<int,int> > qr[1000111];
void solve()
{
	static ll pre_ans[100111];
	for(int i=1;i<=prtot;i++)
	{
//		cerr<<"i="<<i<<" "<<ptab[i]<<endl;
		bit.clear();
		sort(cmd[i].begin(),cmd[i].end());
		reverse(cmd[i].begin(),cmd[i].end());
		sort(qr[i].begin(),qr[i].end());
		reverse(qr[i].begin(),qr[i].end());
//		for(int j=0;j<cmd[i].size();j++)cerr<<cmd[i][j].FF<<","<<cmd[i][j].SS<<" ";cerr<<endl;
//		for(int j=0;j<qr[i].size();j++)cerr<<qr[i][j].FF<<","<<qr[i][j].SS<<" ";cerr<<endl;
		
		int it=0;
		for(int j=0;j<qr[i].size();j++)
		{
			int curp=qr[i][j].FF;
			while(it<cmd[i].size()&&cmd[i][it].FF>=curp)
			{
				int x=cmd[i][it].SS;
				bit.addseg(dfn[x],dfnr[x],1);
				it++;
			}
			int id=qr[i][j].SS;
			ll cur_ans=bit.query(dfn[pu[id]])+bit.query(dfn[pv[id]])
			          -bit.query(dfn[pp[id]])-bit.query(dfn[fa[0][pp[id]]]);
//			cerr<<"Q:"<<curp<<","<<id<<":"<<cur_ans<<" "<<pre_ans[id]<<" "<<1ll*curp*(cur_ans-pre_ans[id])<<endl;
			ANS[id]=1ll*ANS[id]*qpow(ptab[i],1ll*curp*(cur_ans-pre_ans[id]))%mod;
			pre_ans[id]=cur_ans;
		}
		for(int j=0;j<qr[i].size();j++)pre_ans[qr[i][j].SS]=0;
	}
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		vector<pair<int,int> > v=factorize(a[i]);
		for(int j=0;j<v.size();j++)
		{
			int id=getprid(v[j].FF);
			cmd[id].PB(MP(v[j].SS,i));
		}
	}
	init_tree();
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int u,v,x;
		getiii(u,v,x);
		int p=get_lca(u,v);
//		cerr<<"p="<<p<<endl;
		pu[i]=u;pv[i]=v;pp[i]=p;
		vector<pair<int,int> > fac=factorize(x);
		for(int j=0;j<fac.size();j++)
		{
			if(prid.find(fac[j].FF)==prid.end())continue;
			int id=getprid(fac[j].FF);
			for(int t=1;t<=fac[j].SS;t++)qr[id].PB(MP(t,i));
		}
	}
	for(int i=1;i<=q;i++)ANS[i]=1;
	solve();
	for(int i=1;i<=q;i++)putsi(ANS[i]);
	return 0;
}