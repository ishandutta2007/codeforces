//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
struct DSU
{
	int cnt,p[100111],sz[100111];
	int tmp[20000000],tot;
	void init(int n)
	{
		cnt=n;
		for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
		tot=0;
	}
	int gf(int x){while(p[x]!=x)x=p[x];return x;}
	void un(int x,int y)
	{
		x=gf(x);y=gf(y);
		if(x==y)return;
		if(sz[x]>sz[y])swap(x,y);
		tmp[tot++]=x;
		p[x]=y;
		tmp[tot++]=y;tmp[tot++]=sz[y];
		if((sz[x]&1)&&(sz[y]&1))cnt-=2;
		sz[y]=sz[y]+sz[x];
	}
	pair<int,int> getstate(){return MP(cnt,tot);}
	void rollback(pair<int,int> state)
	{
		cnt=state.FF;
		int ptot=state.SS;
		for(int i=tot-3;i>=ptot;i-=3)
		{
			p[tmp[i]]=tmp[i];
			sz[tmp[i+1]]=tmp[i+2];
		}
		tot=ptot;
	}
}A;
int n,m;
pair<pair<int,int>,int >e[300111];
int vw[300111],vwn,ans[300111];
vector<int> ve[300111];
void adde(int i)
{
//	cout<<"adde:"<<i<<endl;
	A.un(e[i].FF.FF,e[i].FF.SS);
}
void solve(int l,int r,int lo,int hi)
{
	if(l>r)return;
//	cout<<"solve:"<<l<<","<<r<<" "<<lo<<" "<<hi<<endl;
	if(A.cnt==0)
	{
		for(int i=l;i<=r;i++)ans[i]=lo;
		return;
	}
	if(lo==hi)
	{
		for(int i=l;i<=r;i++)ans[i]=vwn;
		return;
	}
	int m=l+r>>1;
	pair<int,int> st,st2;
	st=A.getstate();
	for(int i=l;i<=m;i++)if(e[i].SS<=lo)adde(i);
	st2=A.getstate();
	int mi=lo;
	while(A.cnt>0&&mi<hi)
	{
		mi++;
		for(int i=0;i<ve[mi].size();i++)if(ve[mi][i]<=m)adde(ve[mi][i]);
	}
	if(mi==hi)ans[m]=vwn;else ans[m]=mi;
	A.rollback(st2);
	solve(m+1,r,lo,mi+1);
	A.rollback(st);
	for(int i=lo+1;i<=mi;i++)
	{
		for(int x:ve[i])
		{
			if(x<l)
			{
				adde(x);
			}
		}
	}
	solve(l,m-1,mi,hi);
	A.rollback(st);
}
int main()
{
	getii(n,m);
	A.init(n);
	for(int i=1;i<=m;i++)
	{
		int x,y,l;
		getiii(x,y,l);
		e[i]=MP(MP(x,y),l);
		vw[vwn++]=l;
	}
	sort(vw,vw+vwn);
	vwn=unique(vw,vw+vwn)-vw;
	for(int i=1;i<=m;i++)
	{
		e[i].SS=lower_bound(vw,vw+vwn,e[i].SS)-vw;
		ve[e[i].SS].PB(i);
	}
//	for(int i=1;i<=m;i++)cout<<e[i].FF.FF<<","<<e[i].FF.SS<<" "<<e[i].SS<<endl;
	solve(1,m,0,vwn);
	vw[vwn]=-1;
	for(int i=1;i<=m;i++)putsi(vw[ans[i]]);
	return 0;
}