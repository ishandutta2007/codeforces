//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
namespace _fac
{
	typedef unsigned int ui;
	typedef unsigned long long ll;
	const int N=1e6+2;
	const ui p=998244353;
	ui fac[N];
	ui ifac[N];
	ui inv[N];
	ui ksm(ui x,int y)
	{
		ui r=1;
		while (y)
		{
			if (y&1) r=(ll)r*x%p;
			x=(ll)x*x%p;
			y>>=1;
		}
		return r;
	}
	ui C(int n,int m)
	{
		if (n<m||m<0) return 0;
		return (ll)fac[n]*ifac[m]%p*ifac[n-m]%p;
	}
	void init_fac()
	{
		int i;
		fac[0]=1;
		for (i=1; i<N; i++) fac[i]=(ll)fac[i-1]*i%p;

		ifac[N-1]=ksm(fac[N-1],p-2);
		for (i=N-1; i; i--) ifac[i-1]=(ll)ifac[i]*i%p;

		ui x; inv[1]=1;
		for (i=2; i<N; i++)
		{
			x=p/i;
			inv[i]=(ll)x*(p-inv[p-x*i])%p;
		}
	}
}
using _fac::init_fac; using _fac::fac; using _fac::ifac; using _fac::inv;
using _fac::ksm; using _fac::C; using _fac::p;
const int N=1e6+5;
ll mi[N];
int main()
{
	init_fac();
	mi[0]=1;
	for (int i=1; i<N; i++) mi[i]=(mi[i-1]<<1)%p;
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		vector<ll> s(n+1);
		for (i=1; i<=n; i++) cin>>s[i],s[i]+=s[i-1];
		map<ll,int> cnt;
		for (i=1; i<n; i++) ++cnt[s[i]];
		// dbg(s);
		ll r=1;
		for (auto [x,y]:cnt)
		{
			if (x*2>s[n]) break;
			if (cnt.count(s[n]-x))
			{
				if (x*2==s[n])
				{
					r=r*mi[y]%p;
				}
				else
				{
					int z=cnt[s[n]-x];
					r=r*C(z+y,z)%p;
				}
			}
		}
		cout<<r<<'\n';
	}
}