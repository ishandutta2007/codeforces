#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define dprintf(...) fprintf(stderr, __VA__ARGS__)
#define dln()        fprintf(stderr, "\n")
using namespace std;
typedef double db;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<PII> VPI;
typedef vector<long long> VL;
const	int N = 100005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e18;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

int n,m,a[N];
inline LL Pow(LL x, LL y){
	LL an = 1;
	for(; y; y >>= 1, x = min(x*x,m+1LL)) if(y & 1) an = min(an*x,m+1LL);
	return an;
}

inline int Pow(int x,int y,int p){
	int an=1;
	for(;y;y>>=1,x=(LL)x*x%p)if(y&1)an=(LL)an*x%p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
	freopen((a + ".in").c_str(), "r", stdin);
	freopen((a + ".out").c_str(), "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int gtphi[10005];
int Gt[N][8],nxt[N];
int dp[N][35];

int getphi(int x){
	int ans=x;
	for(int t=2;t*t<=x;t++) if(x%t==0){
		ans=ans-ans/t;
		while(x%t==0)x/=t;
	}
	if(x>1) ans=ans-ans/x;
	return ans;
}

int Ans(int l,int r,int t){
	if(l>r||gtphi[t]==1) return 0;
	if(l==r) return a[l]%gtphi[t];
	if(a[l]==1) return 1;
	int nxtr=min(nxt[l],r);
	if(nxtr>l+6){
		int gtw=Ans(l+1,r,t+1);
		return Pow(a[l],gtw+gtphi[t+1],gtphi[t]);
	}else{
		int xx=Gt[l+1][nxtr-(l+1)];
		if(xx<=gtphi[t]){
			return Pow(a[l],xx,gtphi[t]);
		}else{
			int gtw=Ans(l+1,r,t+1);
			return Pow(a[l],gtw+gtphi[t+1],gtphi[t]);
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d",&n,&m);
	int now=n+1;
	gtphi[1]=m;
	REP(i,1,1000){
		gtphi[i+1]=getphi(gtphi[i]);
		if(!gtphi[i+1])break;
	}
	REP(i,1,n) scanf("%d",a+i);
	PER(i,n,1){
		nxt[i]=now;
		if(a[i]==1) now=i;
	}
	PER(i,n,1){
		Gt[i][0]=a[i];
		REP(j,1,6){
			Gt[i][j]=Pow(a[i],Gt[i+1][j-1]);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",Ans(l,r,1));
	}
	

	return 0;
}