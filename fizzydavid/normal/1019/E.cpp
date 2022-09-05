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
const int maxm=1000111;
//Point with integer coordinates
struct point//integer
{
	ll x,y;
	point(ll X=0,ll Y=0){x=X;y=Y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	ll len()const{return x*x+y*y;}
	ll det(const point &t)const{return x*t.y-y*t.x;}
	ll dot(const point &t)const{return x*t.x+y*t.y;}
	bool operator<(const point &t)const{return MP(x,y)<MP(t.x,t.y);}
	bool operator==(const point &t)const{return MP(x,y)==MP(t.x,t.y);}
	ll detll(const point &t)const
	{
		double tmp=1.0*x*t.y-1.0*y*t.x;
		if(tmp>1e18)return 1e18;
		if(tmp<-1e18)return -1e18;
		return x*t.y-y*t.x;
	}
	ll dotll(const point &t)const
	{
		double tmp=1.0*x*t.y+1.0*y*t.x;
		if(tmp>1e18)return 1e18;
		if(tmp<-1e18)return -1e18;
		return x*t.y+y*t.x;
	}
};

typedef vector<point> hull;
const int hull_type=1;//1 /\ -1 \/
hull ANS;
void debug(hull &v)
{
	cerr<<"SIZE="<<v.size()<<endl;
	for(int i=0;i<v.size();i++)cerr<<v[i].x<<","<<v[i].y<<" ";cerr<<endl;
}
hull make_convexhull_without_sort(const hull &v,int type=hull_type)//1 /\ -1 \/
{
	hull a;
	for(int i=0;i<v.size();i++)
	{
		const point &p=v[i];
		if(a.size()>0&&a[a.size()-1]==p)continue;
		while(a.size()>=2)
		{
			point &p0=a[a.size()-2],&p1=a[a.size()-1];
			if((p1-p0).detll(p-p0)*type>=0)a.pop_back();else break;
		}
		a.PB(p);
	}
	return a;
}
void make_convexhull(hull &v,int type=hull_type)
{
	sort(v.begin(),v.end());
	v=make_convexhull_without_sort(v,type);
}
hull merge_convexhull(hull &a,hull &b,int type=hull_type)
{
	hull v;
	v.resize(a.size()+b.size());
	merge(a.begin(),a.end(),b.begin(),b.end(),v.begin());
	return make_convexhull_without_sort(v,type);;
}
bool cmp_pp(point P,point Q)
{
	return Q.detll(P)>=0;
}
void Query(hull &a,hull &b)
{
	if(a.size()==0||b.size()==0)return;
	int it0=0,it1=0;
	while(true)
	{
		ANS.PB(a[it0]+b[it1]);
		if(it0+1==a.size()&&it1+1==b.size())break;
		else if(it0+1==a.size())it1++;
		else if(it1+1==b.size())it0++;
		else
		{
			if(cmp_pp(a[it0+1]-a[it0],b[it1+1]-b[it1]))it0++;
			else it1++;
		}
	}
}
int n,m;
vector<pair<int,pair<ll,ll>>> con[maxn];
int dlv[maxn];
int cur_lv,cur_rt;
int arr[maxn],an,sz[maxn];
void pdfs(int x,int pre=-1)
{
	sz[x]=1;arr[an++]=x;dlv[x]=cur_lv+1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(u==pre||dlv[u]<cur_lv)continue;
		pdfs(u,x);
		sz[x]+=sz[u];
	}
}
int find_rt(int x)
{
	an=0;
	pdfs(x);
	int ret=x;
	for(int i=0;i<an;i++)
	{
		if(sz[arr[i]]*2>=sz[x]&&sz[arr[i]]<sz[ret])
		{
			ret=arr[i];
		}
	}
	return ret;
}
hull CH;
vector<hull> V;
void dfs(int x,int pre,ll sa,ll sb)
{
	CH.PB(point(sa,sb));
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(dlv[u]<cur_lv||u==pre)continue;
		dfs(u,x,sa+con[x][i].SS.FF,sb+con[x][i].SS.SS);
	}
}
struct COMP
{
	bool operator()(int x,int y){return V[x].size()>V[y].size();}
};
int Merge(int x,int y)
{
	Query(V[x],V[y]);
	V[x]=merge_convexhull(V[x],V[y]);
	return x;
}
void solve(int x,int lv)
{
	cur_lv=lv;
	int rt=find_rt(x);
	dlv[rt]=lv;
	vector<hull>().swap(V);
	hull().swap(CH);
	CH.PB(point(0,0));
	V.PB(CH);
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i].FF;
		if(dlv[u]<lv)continue;
		hull().swap(CH);
		dfs(u,rt,con[rt][i].SS.FF,con[rt][i].SS.SS);
		make_convexhull(CH);
		V.PB(CH);
	}
	priority_queue<int,vector<int>,COMP> pq;
	for(int i=0;i<V.size();i++)pq.push(i);
	while(pq.size()>=2)
	{
		int x=pq.top();pq.pop();
		int y=pq.top();pq.pop();
//		cerr<<x<<","<<y<<endl;
		int z=Merge(x,y);
		pq.push(z);
	}
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i].FF;
		if(dlv[u]<lv)continue;
		solve(u,lv+1);
	}
}
int main()
{
	getii(n,m);
	if(n==1)
	{
		for(int i=0;i<m;i++)puti(0);
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		ll a,b;
		getii(a,b);
		con[x].PB(MP(y,MP(a,b)));
		con[y].PB(MP(x,MP(a,b)));
	}
	solve(1,0);
	make_convexhull(ANS);
	int it=0;
	for(int i=0;i<m;i++)
	{
		while(it+1<ANS.size()&&ANS[it+1].x*i+ANS[it+1].y>ANS[it].x*i+ANS[it].y)it++;
		puti(ANS[it].x*i+ANS[it].y);
	}
	return 0;
}