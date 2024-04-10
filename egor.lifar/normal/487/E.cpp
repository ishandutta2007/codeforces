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
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
     
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
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
     
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
     
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
const int MAXN = 200228;
const int INF = 1000000000;


struct edge {
	int to, next;
}e[MAXN * 4];


multiset<int> s[MAXN];
vector<int> g[MAXN];
int dfn[MAXN], low[MAXN], q[MAXN], bl[MAXN], head[MAXN], a[MAXN];
int mn[MAXN * 4], dep[MAXN], fa[MAXN], size[MAXN], son[MAXN], top[MAXN];
int sz, n, m, qq, x, y, tp, cnt, to, ind, bcc;
char op[3];


inline void ins(int x, int y){
	e[++cnt] = (edge){y, head[x]};
	head[x] = cnt;
}


void dfs(int x, int fa){
	dfn[x] = low[x] = ++ind;
	q[++tp] = x;
	for (auto h: g[x]) {
		if(!dfn[h]){
			dfs(h, x);
			chkmin(low[x], low[h]);
			if (low[h] >= dfn[x]) {
				bcc++;
				y = -1;
				while (y != h) {
					y = q[tp--];
					bl[y] = bcc; 
					ins(bcc, y);
					s[bcc].insert(a[y]);
				}
				ins(x, bcc);
			}
		} else if (h != fa) {
			chkmin(low[x], dfn[h]);
		}
	}
}


void dfs1(int x, int y) {
	size[x] = 1; 
	for (int i = head[x]; i; i = e[i].next){
		dep[e[i].to] = dep[x] + 1;
		fa[e[i].to] = x;
		dfs1(e[i].to, x);
		size[x] += size[e[i].to];
		if (size[e[i].to] > size[son[x]]) {
			son[x] = e[i].to;
		}
	}
}


void dfs2(int x, int y){
	dfn[x] = ++sz; 
	top[x] = y;
	if (son[x]) {
		dfs2(son[x], y);
	}
	for (int i = head[x]; i; i = e[i].next) {
		if (e[i].to != son[x]) {
			dfs2(e[i].to, e[i].to);
		}
	}
}


#define lson (k << 1)
#define rson (k << 1 | 1)


void modify(int k, int l, int r, int x, int y) {
	if (l == r) {
		mn[k] = y; 
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) {
		modify(lson, l, mid, x, y);
	} else {
		modify(rson, mid + 1, r, x, y);
	}
	mn[k] = min(mn[lson], mn[rson]);
}


int query(int k, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return mn[k];
	}
	int mid = (l + r) >> 1, res = INF;
	if (ql <= mid) {
		chkmin(res, query(lson, l, mid, ql, qr));
	}
	if (qr > mid) {
		chkmin(res, query(rson, mid + 1, r, ql, qr));
	} 
	return res;
}


inline void modify(int x, int y) {
	if (bl[x]) {
		s[bl[x]].erase(s[bl[x]].find(a[x]));
		s[bl[x]].insert(y);
		modify(1, 1, sz, dfn[bl[x]], *s[bl[x]].begin());
	}
	a[x] = y; 
	modify(1, 1, sz, dfn[x], y);
}


inline int query(int x,int y) {
	int res = INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) {
			swap(x, y);
		}
		chkmin(res, query(1, 1, sz, dfn[top[x]], dfn[x]));
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) {
		swap(x, y);
	}
	chkmin(res, query(1, 1, sz, dfn[y], dfn[x]));
	if (y > n && fa[y]) {
		chkmin(res, a[fa[y]]);
	}
	return res;
}


int main(){
	n = readInt(), m = readInt(), qq = readInt();
	bcc = n;
	for (int i = 1; i <= n; i++) { 
		a[i] = readInt();
	}
	for(int i = 1; i <= m; i++){
		x = readInt(), y = readInt();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	dfs1(1, 0); 
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) { 
		modify(1, 1, sz, dfn[i], a[i]);
	}
	for(int i = n + 1; i <= sz; i++) {
		modify(1, 1, sz, dfn[i], *s[i].begin());
	}
	for (int i = 1; i <= qq; i++){
		char t = readChar();
		x = readInt(), y = readInt();
		if (t == 'C') {
			modify(x, y);
		} else {
			writeInt(query(x, y), '\n');
		}
	}
	return 0;
}