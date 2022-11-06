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

const int N=301000;
int a[18][N];
VI vq;
int Q[N],n,q;
ll ret[N];
void gao(int r,int v) {
	vector<int>::iterator it=lower_bound(all(vq),v);
	if (it==vq.end()||*it!=v) return;
	ret[it-vq.begin()]+=r;
}
ll query(int v) { return ret[lower_bound(all(vq),v)-vq.begin()];}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a[0]+i); a[0][n]=1;
	rep(i,1,17) rep(j,0,n+1) a[i][j]=__gcd(a[i-1][j],a[i-1][j+(1<<(i-1))]);
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d",Q+i);
		vq.pb(Q[i]);
	}
	sort(all(vq));
	vq.erase(unique(all(vq)),vq.end());
	rep(i,0,n) {
		int cr=i,v=a[0][i];
		while (1) {
			if (v==1) {
				gao(n-cr,1);
				break;
			}
			int cp=cr+1;
			per(j,0,17) if (a[j][cp]%v==0) cp=cp+(1<<j);
			gao(cp-cr,v);
			cr=cp;
			v=__gcd(v,a[0][cr]);
		}
	}
	rep(i,0,q) printf("%I64d\n",query(Q[i]));
}