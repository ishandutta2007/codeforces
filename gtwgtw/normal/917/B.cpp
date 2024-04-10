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
const	int N = 105;
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
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int n,m;
VI e[N][27];
bool f[N][N][27][2],vis[N][N][27][2];

bool work(int u,int v,int a,int now)
{
	if(vis[u][v][a][now]) return f[u][v][a][now];
	bool &res=f[u][v][a][now]; res=0;
	vis[u][v][a][now]=1;
	if(now == 1)
	{
		REP(w,a,27) for(auto gt:e[v][w]) if(!work(u,gt,w,!now)) return res=1;
		return res=0;
	}else
	{
		REP(w,a,27) for(auto gt:e[u][w]) if(!work(gt,v,w,!now)) return res=1;
		return res=0;
	}
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	
	scanf("%d%d",&n,&m);
	REP(i,1,m)
	{
		int x,y;
		char op[15];
		scanf("%d%d%s",&x,&y,op);
		e[x][*op-'a'+1].pb(y);
	}

	REP(i,1,n){
		REP(j,1,n) if(work(i,j,0,0)) putchar('A');
		else putchar('B');
		puts("");
	}


	return 0;
}