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

char s[70005][15];
int n, cnt = 1, tim;
int tr[70001 * 45][10];
int app[70001 * 45], vis[70001 * 45];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d", &n);
	REP(xx, 1, n){
		scanf("%s", s[xx] + 1);
		int len = strlen(s[xx] + 1);
		++tim;
		REP(i, 1, len){
			int p = 1;
			REP(j, i, len){
				int &v = tr[p][s[xx][j] - '0'];
				if(!v) v = ++cnt;
				if(vis[v] != tim){
					app[v] ++;
					vis[v] = tim;
				}
				p = v;
			}
		}
	}

	REP(xx, 1, n){
		int ans = 1 << 30;
		int l = 0, r = 0;
		int len = 9;
		REP(i, 1, len){
			int p = 1;
			REP(j, i, len){
				int v = tr[p][s[xx][j] - '0'];
				if(app[v] == 1){
					if(j - i + 1 < ans){
						ans = j - i + 1;
						l = i;
						r = j;
					}
					break;
				}
				p = v;
			}
		}
		REP(x, l, r) putchar(s[xx][x]); puts("");
	}

	return 0;
}