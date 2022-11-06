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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,m,a[N],l,r,k;
int binom[N][130];
ll s[N][130];
int main() {
	scanf("%d%d",&n,&m);
	binom[0][0]=1;
	rep(i,1,n+200) {
		binom[i][0]=1;
		for (int j=1;j<=102&&j<=i;j++) {
			binom[i][j]=binom[i-1][j]+binom[i-1][j-1];
			if (binom[i][j]>=mod) binom[i][j]-=mod;
		}
	}
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,0,m) {
		scanf("%d%d%d",&l,&r,&k);
		s[l][100-k]+=1;
		rep(j,100-k,101) {
			s[r+1][j]-=binom[r-l+j-(100-k)][j-(100-k)];
		} 
	}
	rep(i,1,n+1) rep(j,0,101) {
		s[i][j]+=s[i][j-1]+s[i-1][j];
		s[i][j]%=mod;
	}
	rep(i,1,n+1) {
		a[i]+=s[i][100];
		a[i]%=mod;
		if (a[i]<0) a[i]+=mod;
	}
	rep(i,1,n+1) printf("%d ",a[i]);
}