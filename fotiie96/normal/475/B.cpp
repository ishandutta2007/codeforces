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

const int N=410;
int n,m,g[N][N];
char s[N],t[N];
int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	scanf("%s",t);
	rep(i,0,n) {
		if (s[i]=='<') { 
			rep(j,1,m) g[i*m+j][i*m+j-1]=1;
		} else {
			rep(j,0,m-1) g[i*m+j][i*m+j+1]=1;
		}
	}
	rep(j,0,m) {
		if (t[j]=='^') {
			rep(i,1,n) g[i*m+j][(i-1)*m+j]=1;
		} else {
			rep(i,0,n-1) g[i*m+j][(i+1)*m+j]=1;
		}
	}
	rep(i,0,n*m) g[i][i]=1;
	rep(k,0,n*m) rep(i,0,n*m) rep(j,0,n*m) if (i!=j&&i!=k&&j!=k)
		g[i][j]|=g[i][k]&g[k][j];
	rep(i,0,n*m) rep(j,0,n*m) if (!g[i][j]) {
		puts("NO"); return 0;
	}
	puts("YES");
}