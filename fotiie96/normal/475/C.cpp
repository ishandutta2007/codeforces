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

const int N=1010;
char g[N][N],s[N][N];
int l[N],r[N];
int n,m,ret;
void check(int px,int py,int sx,int sy,int n,int m) {
	if (sx<=0||sy<=0) return;
	rep(i,0,n) rep(j,0,m) g[i][j]='.';
	rep(i,0,sx) rep(j,0,sy) g[px+i][py+j]='X';
	while (1) {
		if (s[px+sx][py]=='X') {
			rep(j,0,sy) g[px+sx][py+j]='X';
			px++;
		} else if (s[px][py+sy]=='X') {
			rep(j,0,sx) g[px+j][py+sy]='X';
			py++;
		} else break;
	}
	rep(i,0,n) rep(j,0,m) if (s[i][j]!=g[i][j]) return;
	if (ret==-1) ret=sx*sy;
	else ret=min(ret,sx*sy);
}
void gao(int n,int m) {
	rep(i,0,n) {
		l[i]=r[i]=-1;
		rep(j,0,m) if (s[i][j]=='X') {
			if (l[i]!=-1) return;
			l[i]=j;
			while (s[i][j]=='X') j++;
			r[i]=j-1;
		}
	}
	int px=-1; l[n]=-1;
	rep(i,0,n) if (l[i]!=-1) {
		if (px!=-1) return;
		px=i;
		while (l[i]!=-1) ++i;
	}
	int qx=px;
	while (l[qx]==l[px]) ++qx;
	if (l[qx]==-1) check(px,l[px],qx-px,1,n,m);
	else check(px,l[px],qx-px,r[px]-l[qx]+1,n,m);
}
int main() {
	ret=-1;
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%s",s[i]);
	gao(n,m);
	rep(i,0,max(n,m)) rep(j,0,max(n,m)) if (i>j) swap(s[i][j],s[j][i]);
	gao(m,n);
	printf("%d\n",ret);
}