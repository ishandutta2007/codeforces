/*
  !










*/
#pragma GCC optimize "-O3"
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


int n;
vector<int> g[MAXN];


struct Tree {
    int root;
    int curRoot;
    int parent;
    vector<pair<int, int> > vs;
};


vector<Tree> trees;


struct Triple {
    int x, y, z;
};


vector<Triple> ans;
int c1 = -1, c2 = -1;


int dfs1(int v, int p = -1) {
    int s = 1;
    for (auto h: g[v]) {
        if (h != p) {
            s += dfs1(h, v);
        }
    }
    if (c1 == -1 && s * 2 >= n) {
        c1 = v;
        if (s * 2 == n) {
            c2 = p;
        } else {
            c2 = -1;
        }
    }
    return s;
}


void dfs2(int v, int p) {
    for (auto h: g[v]) {
        if (h != p) {
            dfs2(h, v);
        }
    }
    trees.back().vs.push_back({v, p});
}


int main() {
    n = readInt();
    for (int i = 0; i < n - 1; i++) {
        int x = readInt(), y = readInt();
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (n <= 3) {
        writeInt(0, '\n');
        return 0;
    }
    dfs1(0);
    for (auto h: g[c1]) {
        if (h == c2) {
            continue;
        }
        trees.emplace_back();
        trees.back().root = h;
        trees.back().curRoot = h;
        trees.back().parent = c1;
        dfs2(h, c1);
    }
    if (c2 != -1) {
        for (auto h: g[c2]) {
            if (h == c1) {
                continue;
            }
            trees.emplace_back();
            trees.back().root = h;
            trees.back().curRoot = h;
            trees.back().parent = c2;
            dfs2(h, c2);
        }
    }
    for (auto &tree: trees) {
        for (auto pp: tree.vs) {
            int v = pp.first, p = pp.second;
            if (v == tree.root) {
                break;
            }
            ans.push_back({tree.parent, tree.curRoot, v});
            tree.curRoot = v;
            ans.push_back({v, p, tree.root});
        }
        ans.push_back({tree.parent, tree.curRoot, tree.root});
    }
    writeInt(sz(ans), '\n');
    for (auto t: ans) {
        writeInt(t.x + 1, ' ');
        writeInt(t.y + 1, ' ');
        writeInt(t.z + 1, '\n');
    }
    return 0;
}