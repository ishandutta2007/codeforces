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

int Gt[25][25];
int E[25],all,n,m;

int ans=1e9;
VI res;
int seq[N],stot;
void dfs(int x,int y){
	if(y>=ans) return;
	if(x>n){
		REP(i,1,n) if(E[i]!=all) return;
		ans=y;
		res.clear();
		REP(i,1,stot) res.pb(seq[i]);
		return;
	}
	dfs(x+1,y);
	REP(i,1,n) Gt[x][i]=E[i];
	REP(i,1,n) if((E[i]>>x)&1) E[i]|=E[x];
	seq[++stot]=x;
	dfs(x+1,y+1);
	REP(i,1,n) E[i]=Gt[x][i];
	--stot;
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d",&n,&m);
	REP(i,1,n) all|=1<<i;
	REP(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		E[x]|=1<<y;
		E[y]|=1<<x;
	} 
	REP(i,1,n) E[i]|=1<<i;
	
	VI dd;
	dfs(1,0);

	printf("%d\n",ans);
	for(auto v:res) printf("%d ",v); puts("");

	return 0;
}