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
struct point
{
	int x,y;
	point(int X=0,int Y=0){x=X;y=Y;}
	point operator+(const point &t){return point(x+t.x,y+t.y);}
	point operator-(const point &t){return point(x-t.x,y-t.y);}
	point operator-(){return point(-x,-y);}
	int det(const point &t){return x*t.y-y*t.x;}
	int dot(const point &t){return x*t.x+y*t.y;}
};
point P[22];
int pn;
void addpoint(point p)
{
	if(pn==0)P[pn++]=p,P[pn++]=-p;
	else
	{
		if((P[1]-P[0]).det(p)>=0)p=-p;
		P[pn]=P[0];
		point Q[3]={p,-p,p};
		int it0=0,it1=0;
		point nP[22];
		int nn=0;
		for(int i=0;i<pn+2;i++)
		{
			nP[nn++]=P[it0]+Q[it1];
			if(it1==2||it0<pn&&(P[it0+1]-P[it0]).det(Q[it1+1]-Q[it1])>=0)it0++;
			else it1++;
		}
		swap(P,nP);
		swap(pn,nn);
	}
//	for(int i=0;i<pn;i++)cerr<<P[i].x<<","<<P[i].y<<" ";cerr<<endl;
}
struct data
{
	ll x,y,v;
	int id;
	void in(int i){getiii(x,y,v);id=i;}
}a0[100111],b0[100111],a[100111],b[100111];
int k,n,m;
ll ans[100111];
pair<ll,int> pp[200111];
ll tab[100111];
ll vv[100111],vvn;
int findv(ll x){return lower_bound(vv,vv+vvn,x)-vv+1;}
void tabadd(int x,ll v){for(int i=x;i<=100005;i+=i&(-i))tab[i]+=v;}
ll tabsum(int x){ll ret=0;for(int i=x;i>0;i-=i&(-i))ret+=tab[i];return ret;}
void solve_query(ll coef)
{
	vvn=0;
	for(int i=1;i<=n;i++)pp[i]=MP(a[i].y,i),vv[vvn++]=a[i].x;
	for(int i=1;i<=m;i++)pp[n+i]=MP(b[i].v,n+i);
	sort(vv,vv+vvn);
	sort(pp+1,pp+n+m+1);
	memset(tab,0,sizeof(tab));
	for(int i=1;i<=n+m;)
	{
		int r=i;
		while(pp[i].FF==pp[r].FF)r++;
//		cerr<<"lv="<<pp[i].FF<<endl;
		for(int j=i;j<r;j++)
		{
			int id=pp[j].SS;
			if(id<=n)
			{
//				cerr<<"add:"<<a[id].x<<" "<<a[id].v<<endl;
				int pos=findv(a[id].x);
				tabadd(pos,a[id].v);
			}
		}
		for(int j=i;j<r;j++)
		{
			int id=pp[j].SS;
			if(id>n)
			{
				id-=n;
//				cerr<<"query:"<<b[id].x<<" "<<b[id].y<<" "<<b[id].id<<endl;
				int pl=findv(b[id].x),pr=findv(b[id].y+1)-1;
				ll tmp=tabsum(pr)-tabsum(pl-1);
				ans[b[id].id]+=tmp*coef;
			}
		}
		i=r;
	}
}
void solve(ll p,ll q,ll xl,bool fl,ll xr,bool fr,ll B,ll coef)
{
//	cerr<<"solve:"<<p<<","<<q<<" "<<xl<<","<<fl<<" "<<xr<<","<<fr<<" "<<B<<" "<<coef<<endl;
	for(int i=1;i<=n;i++)
	{
		a[i].v=a0[i].v;
		a[i].x=a0[i].x;
		a[i].y=-a0[i].x*p+a0[i].y*q;
//		cerr<<a[i].x<<","<<a[i].y<<endl;
	}
	fl^=1;fr^=1;
	for(int i=1;i<=m;i++)
	{
		b[i].x=b0[i].x+xl*b0[i].v+fl;
		b[i].y=b0[i].x+xr*b0[i].v-fr;
		b[i].id=i;
		b[i].v=-(b0[i].x+xl*b0[i].v)*p+(b0[i].y+B*b0[i].v)*q-(coef==-1);
//		cerr<<b[i].v<<" "<<b[i].x<<","<<b[i].y<<endl;
	}
	solve_query(coef);
}
int main()
{
	getiii(k,n,m);
	for(int i=1;i<=k;i++)
	{
		point p;
		getii(p.x,p.y);
		addpoint(p);
	}
	P[pn]=P[0];
	int mn=P[0].x,mx=P[0].x;
	for(int i=0;i<pn;i++)mn=min(mn,P[i].x),mx=max(mx,P[i].x);
	for(int i=1;i<=n;i++)a0[i].in(i);
	for(int i=1;i<=m;i++)b0[i].in(i);
	for(int i=0;i<pn;i++)
	{
		if(P[i].x==P[i+1].x)continue;
		ll xl,xr,p,q,B,coef;
		if(P[i+1].x>P[i].x)
		{
			xl=P[i].x;
			xr=P[i+1].x;
			q=xr-xl;
			p=P[i+1].y-P[i].y;
			coef=-1;
			B=P[i].y;
		}
		else
		{
			xl=P[i+1].x;
			xr=P[i].x;
			q=xr-xl;
			p=P[i].y-P[i+1].y;
			coef=1;
			B=P[i+1].y;
		}
		solve(p,q,xl,1,xr,xr==mx,B,coef);
//		for(int j=1;j<=m;j++)puti(ans[j]);puts("");
	}
	for(int i=1;i<=m;i++)putsi(ans[i]);puts("");
	return 0;
}