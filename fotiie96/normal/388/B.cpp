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
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
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
#define PRINTC(x) printf("Case #%d: %d\n",++__,x)
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
ll powmod(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int g[1010][1010],cnt;
VI e[1010];
int k;
void add(int u,int v) { e[u].pb(v);e[v].pb(u);}

int len,cp;
void build(int k) {
	if (k==1) { cnt=3;cp=3;add(1,3);len=1; return;}
	if (k%2==1) {
		build(k-1);
		add(1,cnt+1);
		rep(i,1,len-1) add(cnt+i,cnt+i+1);
		add(cnt+len-1,cp);
		cnt+=len-1;
	} else {
		build(k/2);
		add(cp,cnt+1);
		add(cp,cnt+2);
		add(cnt+1,cnt+3);
		add(cnt+2,cnt+3);
		cnt+=3;cp=cnt;
		len+=2;
	}
}

int main() {
	scanf("%d",&k);
	cnt=2;
	build(k);
	add(cp,2);
	printf("%d\n",cnt);
	rep(i,1,cnt+1) rep(j,0,SZ(e[i])) g[i][e[i][j]]=1;
	rep(i,1,cnt+1) {
		rep(j,1,cnt+1) putchar(g[i][j]?'Y':'N');
		puts("");
	}
}