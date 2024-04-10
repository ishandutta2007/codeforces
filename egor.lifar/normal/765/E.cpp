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
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 200228;
set<int> g[MAXN];
vector<int> path[MAXN];
map<int, int> len[MAXN];
bool del[MAXN];
bool used[MAXN];


int getlast(int v) {
    if (sz(path[v]) < 2) {
        return -1;
    } else {
        return path[v][sz(path[v]) - 2];
    }
}


void findpath(int v) {
    int vv = path[v].back();
    while (1) {
        if (sz(g[vv]) > 2) {
            break;
        }
        bool ok = false;
        for (int to : g[vv]) {
            if (to != getlast(v)) {
                ok = true;
                path[v].push_back(to);
                break;
            }
        }
        if (!ok) {
            break;
        }
        vv = path[v].back();
    }
}


void delv(int v) {
    for (int to: g[v]) {
        g[to].erase(v);
    }
}


void deleted(int v) {
    for (int i = 0; i < sz(path[v]) - 1; i++) {
        int vv = path[v][i];
        delv(vv);
        del[vv] = true;
    }
}


int main() {
    int n = readInt();
    for (int i = 1; i < n; i++) {
        int u = readInt(), v = readInt();
        g[u].insert(v);
        g[v].insert(u);
    }
    for (int i = 1; i <= n; i++) {
        path[i].push_back(i);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (sz(g[i]) == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        findpath(v);
        int vv = path[v].back();
        if (len[vv].count(sz(path[v]))) {
            deleted(v);
            q.push(len[vv][sz(path[v])]);
            len[vv].erase(sz(path[v]));
        } else {
            len[vv][sz(path[v])] = v;
        }
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (sz(g[i]) == 1 && !del[i]) {
            root = i;
        }
    }
    if (root == -1) {
        writeWord("-1\n");
        return 0;
    }
    findpath(root);
    for (int i = 0; i < sz(path[root]); i++) {
        used[path[root][i]] = true;
        if (sz(g[path[root][i]]) > 2) {
            writeWord("-1\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!del[i] && !used[i]) {
            writeWord("-1\n");
            return 0;
        }
    }
    int ans = sz(path[root]) - 1;
    while (ans % 2 == 0) {
        ans >>= 1;
    }
    writeInt(ans, '\n');
    return 0;
}