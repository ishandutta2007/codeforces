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

char s[10005];
int len;
int app[35], kd, cnt;
int dp[4005], pre[4005];

int add(char x){
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
		FOR(j, 0, 26) app[j] = 0;
		kd = 0;
		cnt = 0;
		return 1;
	}
	x -= 'a';
	if(!app[x]){
		app[x] = 1;
		kd ++;
	}
	cnt ++;
	if(cnt >= 3 && kd >= 2) return 0;
	return 1;
}

void dfs(int x){
	if(!x) return;
	dfs(pre[x]);
	if(pre[x]) printf(" ");
	REP(i, pre[x] + 1, x) putchar(s[i]);
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	
	scanf("%s", s + 1);
	len = strlen(s + 1);
	int las = 1;
	dp[0] = 0;
	REP(i, 1, len) dp[i] = 1 << 30;
	REP(i, 0, len){
		FOR(j, 0, 26) app[j] = 0;
		kd = 0;
		cnt = 0;
		REP(j, i + 1, len){
			if(!add(s[j])) break;
			if(dp[i] + 1 < dp[j]){
				dp[j] = dp[i] + 1;
				pre[j] = i;
			}
		}
	}

	dfs(len);
	puts("");

	return 0;
}