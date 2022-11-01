#include <set>
#include <map>
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
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
const	int N = 200005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e15;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
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
#else
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int x,y,n,dp[N];
int a[N];
int Mx[20][N],lg[N],Mn[20][N];

int Max(int l,int r){
	int t=lg[r-l+1];
	return max(Mx[t][l],Mx[t][r-(1<<t)+1]);
}

int Min(int l,int r){
	int t=lg[r-l+1];
	return min(Mn[t][l],Mn[t][r-(1<<t)+1]);
}

int sum[N];
void add(int l,int r){
	sum[l]++;
	sum[r+1]--;
}

int chk(int xx,int l,int r,int xmd){
	int xmax=Max(l,r),xmin=Min(l,r);
	return abs(xmax-xx)<=xmd&&abs(xmin-xx)<=xmd;
}

int chk(int xmd){
	REP(i,1,n+4) dp[i]=0;
	dp[1]=dp[2]=1;
	REP(i,1,n+4) sum[i]=0;
	REP(i,1,n+2){
		sum[i]+=sum[i-1];
		if(sum[i]||dp[i]) dp[i]=1;
		if(!dp[i])continue;
		if(i==n+2) break;
		int xl=i+1,xr=n+2,aim=i;
		while(xl<=xr){
			int md=(xl+xr)/2;
			if(chk(a[i],i+1,md,xmd)){
				aim=md;
				xl=md+1;
			}else{
				xr=md-1;
			}
		}
		if(i+1<=aim) add(i+1,aim);
	}
	return dp[n+2];
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d%d",&n,&x,&y);
	a[1]=x;
	a[2]=y;
	REP(i,3,n+2) scanf("%d",a+i);

	REP(i,1,n+2) Mx[0][i]=a[i],Mn[0][i]=a[i];
	REP(i,2,n+2) lg[i]=lg[i>>1]+1;
	REP(i,1,19){
		REP(j,1,n+2-(1<<i)+1) Mx[i][j]=max(Mx[i-1][j],Mx[i-1][j+(1<<(i-1))]);
		REP(j,1,n+2-(1<<i)+1) Mn[i][j]=min(Mn[i-1][j],Mn[i-1][j+(1<<(i-1))]);
	}

	int l=abs(x-y),r=1e9,aim=1e9;
	while(l<=r){
		int md=(l+r)/2;
		if(chk(md)){
			r=md-1;
			aim=md;
		}else{
			l=md+1;
		}
	}

	printf("%d\n",aim);

	return 0;
}