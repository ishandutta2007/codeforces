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
#include <cassert>

 
 
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
 
struct flusher {
    ~flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define left _left
#define right _right
#define last _last
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 300001;


int n, k, d;
bool good[MAXN];
vector<pair<int, int> > v[MAXN];
int dist[MAXN];
vector<int> dels;
bool was[MAXN];
int curdeep = 0;


void dfs(int u, int pr = -1) {
    for (auto h: v[u]) {
        if (h.first == pr) {
            continue;
        }
        if (was[h.second]) {
            continue;
        }
        if (curdeep + 1 != dist[h.first] || curdeep + 1 > d) {
            dels.push_back(h.second);
            was[h.second] = 1;
            continue;
        }
        curdeep++;
        dfs(h.first, u);
        curdeep--;
    }
}


int main() {
    n = readInt(), k = readInt(), d = readInt();
    for (int i = 0; i < k; i++) {
        int a = readInt();
        a--;
        good[a] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int a = readInt(), b = readInt();
        a--, b--;
        v[a].push_back(make_pair(b, i + 1));
        v[b].push_back(make_pair(a, i + 1));
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            q.push(i);
            dist[i] = 0;
        } else {
            dist[i] = n + 1;
        }
    }
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto x: v[a]) {
            if (dist[x.first] == n + 1) {
                dist[x.first] = dist[a] + 1;
                q.push(x.first);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            dfs(i);
        }
    }
    sort(all(dels));
    dels.resize(distance(dels.begin(), unique(all(dels))));
    writeInt(sz(dels), '\n');
    for (auto x: dels) {
        writeInt(x, ' ');
    }
    writeChar('\n');
    return 0;
}