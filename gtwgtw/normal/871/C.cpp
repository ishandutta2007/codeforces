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
const	int N = 100005;
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

int cir,sz;
int n,x[N],y[N],cnt,vis[N<<1];
map<int,int> mps[3];
VI e[N<<1];

void dfs(int x,int par){
	if(vis[x]){
		cir=1;
		return;
	}
	vis[x]=1;
	sz++;
	for(auto v:e[x]) if(v!=par) dfs(v,x);
}

int add(int x,int y){
	if(mps[x].count(y)) return mps[x][y];
	return mps[x][y]=++cnt;
}

void adde(int x,int y){
	e[x].pb(y);
	e[y].pb(x);
}

VI seq;

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);

	REP(i,1,n){
		scanf("%d%d",x+i,y+i);
		adde(add(1,x[i]),add(2,y[i]));
	}

	int ans=Pow(2,cnt,P);
	int cf=1;
	REP(i,1,cnt) if(!vis[i]){
		cir=sz=0;
		dfs(i,0);
		if(!cir) seq.pb(sz);
	}

	int szsum=cnt;
	for(auto v:seq){
		szsum-=v;
		ans=(ans-(LL)cf*Pow(2,szsum,P))%P;
		cf=(LL)cf*(Pow(2,v,P)+P-1)%P;
	}

	ans=(ans+P)%P;

	printf("%d\n",ans);

	return 0;
}