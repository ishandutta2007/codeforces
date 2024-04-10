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
  
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
  

#define left left228
#define right right228
#define prev prev228
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 200001;
long long INF = 1e9;


int n;
int a[MAXN], b[MAXN], w[MAXN], p[MAXN];
vector<int> v[MAXN];
vector<int> v1[MAXN];
int used[MAXN];
long long needRemove[MAXN], canRemove[MAXN];
long long sumW[MAXN];


int getEdge(int id, int u) {
    if (a[id] == u) {
        return b[id];
    }
    return a[id];
}


void pred(int u, int pedge) {
    used[u] = 1;
    for (int i = 0; i < sz(v[u]); i++) {
        int id = v[u][i];
        int to = getEdge(id, u);
        if (used[to]) {
            continue;
        }
        v1[u].push_back(id);
        pred(to, id);
        long long rem_w = sumW[to] - needRemove[to];
        long long ohead = max(rem_w - p[id], 0LL);
        needRemove[to] += ohead;
        long long minimum = sumW[to] - canRemove[to];
        long long sumEdge = max(p[id] - minimum, 0LL);
        sumEdge = min(sumEdge, 0LL + w[id] - 1);
        needRemove[u] += needRemove[to];
        canRemove[u] += canRemove[to];
        canRemove[u] += sumEdge;
        sumW[u] += sumW[to];
        sumW[u] += w[id];
    }
}


void solve(int u, long long should) {
    long long realsum = should;
    vector<pair<long long, long long> > sons;
    for (int i = 0; i < sz(v1[u]); i++) {
        int id = v1[u][i];
        int to = getEdge(id, u);
        long long cntRemove = needRemove[to];
        realsum -= cntRemove;
        sons.push_back(make_pair(cntRemove, to));
    }
    for (int i = 0; i < sz(v1[u]); i++) {
        int id = v1[u][i];
        int to = getEdge(id, u);
        long long can_add = canRemove[to] - needRemove[to];
        can_add = min(can_add,realsum);
        sons[i].first += can_add;
        realsum -= can_add;
        long long rem_w_there = sumW[to] - sons[i].first;
        long long sumEdge = max(p[id] - rem_w_there, 0LL);
        sumEdge = min(sumEdge, 0LL + w[id] - 1);
        sumEdge = min(sumEdge, realsum);
        w[id] -= sumEdge;
        p[id] -= sumEdge;
        realsum -= sumEdge;
    }
    for (int i = 0; i < sz(sons); i++) {
        solve(sons[i].second, sons[i].first);
    }
}


int main() {
    n = readInt();
    for (int i = 0; i < n - 1; i++) {
        a[i] = readInt(), b[i]= readInt(), w[i] = readInt(), p[i] = readInt();
        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
    }
    pred(1, -1);
    for (int i = 1; i <= n; i++) {
        if (canRemove[i] < needRemove[i]) {
            writeInt(-1, '\n');
            return 0;
        }
    }
    solve(1, needRemove[1]);
    writeInt(n, '\n');
    for (int i = 0; i < n - 1; i++) {
        writeInt(a[i], ' ');
        writeInt(b[i], ' ');
        writeInt(w[i], ' ');
        writeInt(p[i], '\n');
    }
    return 0;
}