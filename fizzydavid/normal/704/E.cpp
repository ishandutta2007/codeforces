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
const int maxn=200111;
const double eps=1e-8;
bool is0(double x){return x<eps&&x>-eps;}
struct segment
{
	double k,b,l,r;
	bool operator<(const segment &t)const
	{
		return l<t.l;
	}
	double getv(double x)
	{
		return k*x+b;
	}
	double intersect_x(const segment &t)const
	{
		if(is0(k-t.k))
		{
			if(is0(b-t.b))return max(l,t.l);
			else return 1e9;
		}
		double x=(t.b-b)/(k-t.k);
		if(x>max(l,t.l)-eps&&x<min(r,t.r)+eps)return x;
		else return 1e9;
	}
	segment(double K=0,double B=0,double L=0,double R=0){k=K;b=B;l=L;r=R;}
};
struct node
{
	int tl,tr,rnd,pa,sz;
	node(){pa=tl=tr=sz=0;rnd=rand();}
}a[maxn];
#define ls a[p].tl
#define rs a[p].tr
int tot;
int update(int p){return a[p].sz=a[ls].sz+a[rs].sz+1,p;}
int merge(int p,int q)
{
	if(!p||!q)return p^q;
	if(a[p].rnd<a[q].rnd)return a[p].tr=merge(a[p].tr,q),a[a[p].tr].pa=p,update(p);
	else return a[q].tl=merge(p,a[q].tl),a[a[q].tl].pa=q,update(q);
}
pair<int,int> split(int p,int k)
{
	if(!p)return MP(0,0);
	pair<int,int> ret;
	if(k<=a[ls].sz)
	{
		a[ls].pa=0;
		ret=split(ls,k);
		ls=ret.SS;
		a[ls].pa=p;
		ret.SS=p;
	}
	else
	{
		a[rs].pa=0;
		ret=split(rs,k-a[ls].sz-1);
		rs=ret.FF;
		a[rs].pa=p;
		ret.FF=p;
	}
	update(p);
	return ret;
}
double CL;
segment seg[maxn];
vector<segment> v[maxn];
bool cmp(int x,int y)
{
	return seg[x].getv(CL)<seg[y].getv(CL);
}
int getrk(int p,int v)
{
	return !p?0:(cmp(v,p)?getrk(ls,v):getrk(rs,v)+a[ls].sz+1);
}
int getrealrk(int p,bool pd=1)//cnt_less+1
{
	return !p?0:(pd==1?a[ls].sz+1:0)+getrealrk(a[p].pa,a[a[p].pa].tr==p);
}
int leftmost(int p){return ls?leftmost(ls):p;}
int rightmost(int p){return rs?rightmost(rs):p;}
void debug(int p)
{
	if(!p)return;
	cerr<<"debug:"<<p<<" "<<a[p].tl<<","<<a[p].tr<<" "<<a[p].pa<<" "<<a[p].sz<<endl;
	debug(ls);debug(rs);
}
double FindLeftMostInt(vector<segment> vs)
{
//	cerr<<"solve:"<<endl;
	vector<pair<double,int> > v;
	int sz=vs.size();
	assert(sz<maxn);
//	for(int i=0;i<sz;i++)cerr<<vs[i].k<<" "<<vs[i].b<<" "<<vs[i].l<<" "<<vs[i].r<<endl;
	for(int i=0;i<sz;i++)
	{
		seg[i+1]=vs[i];
		v.PB(MP(vs[i].l,(i+1)));
		v.PB(MP(vs[i].r,-(i+1)));
	}
	sort(v.begin(),v.end());
	int rt=0;
	double ans=1e9;
	for(int i=0;i<v.size();i++)
	{
		int x=v[i].SS;
		CL=v[i].FF;
		if(x>0)
		{
//			cerr<<"add:"<<x<<endl;
			int k=getrk(rt,x);
			pair<int,int> pp=split(rt,k);
			a[x].sz=1;
			rt=merge(merge(pp.FF,x),pp.SS);
		}
		else
		{
			x=-x;
//			cerr<<"del:"<<x<<endl;
//			debug(rt);
			int k=getrealrk(x);
//			cerr<<"k="<<k<<endl;
			pair<int,int> pp=split(rt,k);
			pair<int,int> pp2=split(pp.FF,a[pp.FF].sz-1);
			int pre=rightmost(pp2.FF);
			int suf=leftmost(pp.SS);
//			cerr<<"pre="<<pre<<" suf="<<suf<<endl;
			rt=merge(pp2.FF,pp.SS);
			if(pre)ans=min(ans,seg[x].intersect_x(seg[pre]));
			if(suf)ans=min(ans,seg[x].intersect_x(seg[suf]));
		}
	}
	return ans;
}
int n,m;
vector<int> con[maxn];
int top[maxn],dfn[maxn],dtot,pa[maxn],son[maxn],sz[maxn],lv[maxn];
void dfs(int x,int pre=0)
{
	pa[x]=pre;sz[x]=1;son[x]=0;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		lv[u]=lv[x]+1;
		dfs(u,x);
		sz[x]+=sz[u];
		if(sz[u]>sz[son[x]])son[x]=u;
	}
}
void dfs2(int x,int tp)
{
	top[x]=tp;dfn[x]=++dtot;
	if(son[x])dfs2(son[x],tp);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pa[x]||u==son[x])continue;
		dfs2(u,u);
	}
}
int getlcadep(int x,int y)
{
	if(lv[top[x]]<lv[top[y]])swap(x,y);
	return top[x]==top[y]?min(lv[x],lv[y]):getlcadep(pa[top[x]],y);
}
void addseg(double x,int u,int k,double d,int coef)
{
	double h=lv[u];
	double len=1.0*(max(d,lv[top[u]]-1.0)-lv[u])/k;
	if(len<0)return;
	if(coef==1)v[top[u]].PB(segment(k,h-x*k,x,x+len+(1e-10)));
	else v[top[u]].PB(segment(-k,h-x*(-k),x-len,x+(1e-10)));
	if(d<lv[top[u]])addseg(x+len*coef,pa[top[u]],k,d,coef);
}
int main()
{
	getii(n,m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	lv[1]=1;dfs(1);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		int t,v,x,y;
		getii(t,v);
		getii(x,y);
		int dep=getlcadep(x,y);
		addseg(t,x,-v,dep,1);
		if(lv[y]!=dep)addseg(t+1.0*(lv[x]+lv[y]-dep*2)/v,y,-v,dep+eps*v,-1);
	}
	double ans=1e9;
	for(int i=1;i<=n;i++)
	{
		double tmp=FindLeftMostInt(v[i]);
		ans=min(ans,tmp);
	}
	if(ans>1e8)puts("-1");
	else cout<<fixed<<setprecision(8)<<ans<<endl;
	return 0;
}