#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl 
#define POP(x) (__builtin_popcount(x))
#define POPL(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=10100;
int pos[50],base[50],posb[50],baseb[50];
int a[N],b[N],n,cbs[N];
vector<PII> waya,wayb,wayc;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",a+i);
		int d=a[i];
		for (int k=29;k>=0;k--) {
			if ((d^base[k])<d) {
				waya.pb(mp(i,pos[k]));
				d=d^base[k];
			}
			if (d>=(1<<k)) {
				base[k]=d; pos[k]=i;
				break;
			}
		}
	}
	rep(i,0,n) {
		scanf("%d",b+i);
		int d=b[i];
		for (int k=29;k>=0;k--) d=min(d,d^base[k]);
		if (d!=0) return puts("-1"),0;
		d=b[i];
		for (int k=29;k>=0;k--) {
			if ((d^baseb[k])<d) {
				wayb.pb(mp(i,posb[k]));
				d=d^baseb[k];
			}
			if (d>=(1<<k)) {
				baseb[k]=d; posb[k]=i;
				break;
			}
		}
	}
	for (int k=29;k>=0;k--) if (base[k]) {
		if (!baseb[k]) { wayc.pb(mp(pos[k],pos[k]));continue;}
		int d=baseb[k]^base[k];
		for (int k2=k-1;k2>=0;k2--) {
			if ((d^base[k2])<d) {
				wayc.pb(mp(pos[k],pos[k2]));
				d^=base[k2];
			}
		}
		assert(d==0);
	}
	rep(i,0,n) cbs[i]=-1;
	rep(i,0,30) if (base[i]) cbs[pos[i]]=i;
	for (int k=29;k>=0;k--) if (base[k]&&baseb[k]) {
		int ps=0;
		rep(i,0,n) if (cbs[i]==k) { ps=i; break;}
		if (ps==posb[k]) continue;
		wayc.pb(mp(ps,posb[k]));
		wayc.pb(mp(posb[k],ps));
		wayc.pb(mp(ps,posb[k]));
		swap(cbs[posb[k]],cbs[ps]);
	}		
	printf("%d\n",SZ(waya)+SZ(wayb)+SZ(wayc));
	rep(i,0,SZ(waya)) printf("%d %d\n",waya[i].fi+1,waya[i].se+1);
	rep(i,0,SZ(wayc)) printf("%d %d\n",wayc[i].fi+1,wayc[i].se+1);
	per(i,0,SZ(wayb)) printf("%d %d\n",wayb[i].fi+1,wayb[i].se+1);
}