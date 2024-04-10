/*
  !










*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
/** Interface */
 
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
 
/** Read */
 
static const int buf_size = 4096;
 
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}
 
inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}
 
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
 
/** Write */
 
static int write_pos = 0;
static char write_buf[buf_size];
 
inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
 
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
 
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
 
inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}
 
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
const int INF = 2000000000;
const int MAXN = 200228;
const int LOGN = 18;


int n, m; 
int father[MAXN]; 
int deep[MAXN], ans[MAXN];
vector<vector<int> > E, weight;
vector<pair<int, int> > e[MAXN];
int mark[MAXN], p[MAXN][20], pe[MAXN][20], pID[MAXN];


void dfs(int u, int f) {
	deep[u] = deep[f] + 1;
	for (auto w: e[u]) {
		int v = w.first;
		if (v == f) {
			continue;
		}
		p[v][0] = u;
		pID[v] = w.second;
		pe[v][0] = weight[pID[v]][0];
		dfs(v, u);
	}
}


int findSet(int x) {
	return father[x] == x ? x: father[x] = findSet(father[x]);
}


int lca(int u, int v) {
	if (deep[u] > deep[v]) {
		swap(u, v);
	}
	int mv = 0;
	for (int i = LOGN - 1; i >= 0; i--) {
		if (deep[p[v][i]] >= deep[u]) {
			chkmax(mv, pe[v][i]);
			v = p[v][i];
		}
	}
	if (u == v) {
		return mv;
	}
	for (int i = LOGN - 1; i >= 0; i--) {
		if (p[v][i] != p[u][i]) {
			chkmax(mv, max(pe[u][i], pe[v][i]));
			u = p[u][i];
			v = p[v][i];
		}
	}
	return max(mv, max(pe[u][0], pe[v][0]));
}


int main() {
	n = readInt(), m = readInt();
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int u = readInt(), v = readInt(), w = readInt();
		E.push_back(vector<int>{w, u, v, i});
		weight.push_back(vector<int>{w, u, v, i});
	}
	sort(all(E));
	for (int i = 0; i < m; i++) {
		int id = E[i][3], u = E[i][2], v = E[i][1];
		if (findSet(u) != findSet(v)) {
			mark[id] = 1;
			e[u].push_back(make_pair(v, id)); 
			e[v].push_back(make_pair(u,id));
			father[findSet(u)] = findSet(v);
		}
	}
	dfs(1, 0);
	for (int j = 1; j < LOGN; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			pe[i][j] = max(pe[i][j - 1], pe[p[i][j - 1]][j - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
	for (int i = 0; i < m; i++) {
		ans[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int id = E[i][3], u = E[i][2], v = E[i][1];
		if (!mark[id]) {
			ans[id] = lca(u, v);
			while (1) {
				u = findSet(u);
				v = findSet(v);
				if (u == v) {
					break;
				}
				if (deep[v] > deep[u]) {
					swap(u, v);
				}
				ans[pID[u]] = E[i][0];
				father[u] = findSet(p[u][0]);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (ans[i] == INF) {
			ans[i] = 0;
		}	
		writeInt(ans[i] - 1, ' ');
	}
	writeChar('\n');
	return 0;
}