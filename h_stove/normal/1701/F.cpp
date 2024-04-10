//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e6+5000;
template<typename typC> struct bit
{
	vector<typC> a;
	int n;
	bit(){}
	bit(int nn):n(nn),a(nn+1){}
	template<typename T> bit(int nn,T *b):n(nn),a(nn+1)
	{
		for (int i=1;i<=n;i++) a[i]=b[i];
		for (int i=1;i<=n;i++) if (i+(i&-i)<=n) a[i+(i&-i)]+=a[i];
	}
	void add(int x,typC y)
	{
		//cerr<<"add "<<x<<" by "<<y<<endl;
		assert(1<=x&&x<=n);
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		//cerr<<"sum "<<x;
		assert(0<=x&&x<=n);
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		//cerr<<"= "<<r<<endl;
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
bit<int> t1,t2;
struct Q
{
	ll sa,sb,sab,saa,sbb,len;
	Q(){sa=sb=sab=saa=sbb=len=0;}
	Q(ll a,ll b,ll c,ll d,ll e,ll f):sa(a),sb(b),sab(c),saa(d),sbb(e),len(f){}
	Q operator+(const Q &o) const
	{
		return {sa+o.sa,sb+o.sb,sab+o.sab,saa+o.saa,sbb+o.sbb,len+o.len};
	}
	void adda(const int &o)
	{
		saa+=2*o*sa+len*o*o;
		sab+=o*sb;
		sa+=len*o;
	}
	void addb(const int &o)
	{
		sbb+=2*o*sb+len*o*o;
		sab+=o*sa;
		sb+=len*o;
	}
};
int d;
struct seg
{
	Q s[N];
	int lza[N],lzb[N],ys[N];
	int n=4e5+10;
	int z,y,dt;
	void build(int x,int l,int r)
	{
		if (l==r)
		{
			ys[l]=x;
			return;
		}
		int c=x*2,m=l+r>>1;
		build(c,l,m);build(c+1,m+1,r);
	}
	void adda(int x,int l,int r)
	{
		if (z<=l&&r<=y)
		{
			s[x].adda(dt);
			lza[x]+=dt;
			return;
		}
		int c=x*2,m=l+r>>1;
		if (lza[x])
		{
			s[c].adda(lza[x]);s[c+1].adda(lza[x]);
			lza[c]+=lza[x];lza[c+1]+=lza[x];
			lza[x]=0;
		}
		if (lzb[x])
		{
			s[c].addb(lzb[x]);s[c+1].addb(lzb[x]);
			lzb[c]+=lzb[x];lzb[c+1]+=lzb[x];
			lzb[x]=0;
		}
		if (z<=m) adda(c,l,m);
		if (y>m) adda(c+1,m+1,r);
		s[x]=s[c]+s[c+1];
	}
	void adda(int l,int v)
	{
		if (l>n) return;
		t1.add(l,v);
		z=l;y=n;dt=v;
		adda(1,1,n);
	}
	void addb(int x,int l,int r)
	{
		if (z<=l&&r<=y)
		{
			s[x].addb(dt);
			lzb[x]+=dt;
			return;
		}
		int c=x*2,m=l+r>>1;
		if (lza[x])
		{
			s[c].adda(lza[x]);s[c+1].adda(lza[x]);
			lza[c]+=lza[x];lza[c+1]+=lza[x];
			lza[x]=0;
		}
		if (lzb[x])
		{
			s[c].addb(lzb[x]);s[c+1].addb(lzb[x]);
			lzb[c]+=lzb[x];lzb[c+1]+=lzb[x];
			lzb[x]=0;
		}
		if (z<=m) addb(c,l,m);
		if (y>m) addb(c+1,m+1,r);
		s[x]=s[c]+s[c+1];
	}
	void addb(int l,int v)
	{
		if (l>n) return;
		t2.add(l,v);
		z=l;y=n;dt=v;
		addb(1,1,n);
	}
	ll ans;
	void ask(int x,int l,int r)
	{
		if (z<=l&&r<=y)
		{
			ans+=s[x].saa+s[x].sbb-2*s[x].sab-s[x].sa*3+s[x].sb*3;
			//dbg(l,r,s[x].saa,s[x].sbb,s[x].sab,s[x].sa,s[x].sb);
			return;
		}
		int c=x*2,m=l+r>>1;
		if (lza[x])
		{
			s[c].adda(lza[x]);s[c+1].adda(lza[x]);
			lza[c]+=lza[x];lza[c+1]+=lza[x];
			lza[x]=0;
		}
		if (lzb[x])
		{
			s[c].addb(lzb[x]);s[c+1].addb(lzb[x]);
			lzb[c]+=lzb[x];lzb[c+1]+=lzb[x];
			lzb[x]=0;
		}
		if (z<=m) ask(c,l,m);
		if (y>m) ask(c+1,m+1,r);
	}
	ll ask(int l,int r)
	{
		z=l;y=r;
		ans=2*s[1].len;
		ask(1,1,n);
		return ans;
	}
	void mdf(int p,int v)
	{
		if (p<=d) return;
		int l=1,r=n,c,m,x=1;
		while (l<r)
		{
			m=l+r>>1;c=x*2;
			if (lza[x])
			{
				s[c].adda(lza[x]);s[c+1].adda(lza[x]);
				lza[c]+=lza[x];lza[c+1]+=lza[x];
				lza[x]=0;
			}
			if (lzb[x])
			{
				s[c].addb(lzb[x]);s[c+1].addb(lzb[x]);
				lzb[c]+=lzb[x];lzb[c+1]+=lzb[x];
				lzb[x]=0;
			}
			if (p<=m) x=c,r=m; else x=c+1,l=m+1;
		}
		s[x].len=v;
		s[x].sa=v*t1.sum(p);
		s[x].sb=v*t2.sum(p);
		s[x].saa=s[x].sa*s[x].sa;
		s[x].sab=s[x].sa*s[x].sb;
		s[x].sbb=s[x].sb*s[x].sb;
		while (x>>=1) s[x]=s[x*2]+s[x*2+1];
	}
};
seg s;
bool ed[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int q;
	t1=bit<int>(400'500);
	t2=bit<int>(400'500);
	cin>>q>>d;
	while (q--)
	{
		int x,dt;
		cin>>x;x+=2e5+1;
		dt=ed[x]?-1:1;
		ed[x]^=1;
		s.mdf(x,ed[x]);
		s.adda(max(x,d+1),dt);
		s.addb(x+d+1,dt);
		//auto ans=s.s[1];
		//dbg(ans.sa,ans.sb,ans.saa,ans.sab);
		cout<<s.ask(d+1,s.n)/2<<'\n';
	}
}