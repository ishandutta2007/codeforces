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
const long long INF = 1e18;
const int MAXN = 1000228;


int pos, qnext[MAXN], qhead[MAXN], qv[MAXN];


int main() {
    int n = readInt(), m = readInt(), q = readInt();
    int head[n], next[m], to[m], w[m];
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        int a = readInt();
        int b = readInt();
        int c = readInt();
        a--, b--;
        w[i] = c; 
        to[i] = b; 
        next[i] = head[a]; 
        head[a] = i;
    }
    long long d[n];
    set<pair<int, int> > s;
    fill(d, d + n, INF);
    s.insert(make_pair(d[0] = 0, 0));
    while (sz(s)) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for (int i = head[v]; i != -1; i = next[i]) {
            if (d[to[i]] > d[v] + w[i]) {
                s.erase(make_pair(d[to[i]], to[i]));
                s.insert(make_pair(d[to[i]] = d[v] + w[i], to[i]));
            }
        }
    }
    int k = 0, res[n];
    for (int it = 0; it < q; it++) {
        int type = readInt();
        if (type == 1) {
            int v = readInt();
            if (d[v - 1] == INF) {
                puts("-1");
            } else {
                if (k > 0) {
                    memset(qhead, -1, sizeof(qhead[0]) * (k + 1));
                    pos = 0;
                    fill(res, res + n, 1e9);
                    res[0] = 0;
                    auto addq = [&](int i, int v) {
                        qnext[pos] = qhead[i], qv[pos] = v, qhead[i] = pos++;
                    };
                    addq(0, 0);
                    for (int dist = 0; dist <= k; dist++) {
                        while (qhead[dist] != -1) {
                            int p = qhead[dist];
                            int v = qv[p];
                            qhead[dist] = qnext[p];
                            if (res[v] != dist) {
                                continue;
                            }
                            for (int i = head[v]; i != -1; i = next[i]) {
                                long long ndist = d[v] + res[v] + w[i] - d[to[i]];
                                if (res[to[i]] > ndist) {
                                    if (ndist > k) {
                                        continue;
                                    }
                                    res[to[i]] = ndist, addq(ndist, to[i]);
                                }
                            }
                        }
                    }//
                    for (int i = 0; i < n; i++) {
                        if (d[i] != INF) {
                            d[i] += res[i];
                        }
                    }
                    k = 0;
                }
                printf("%lld\n", d[v - 1]);
            }
        } else {
            int cnt = readInt();
            for (int it = 0; it < cnt; it++) {
                int i = readInt() - 1;
                w[i]++;
            }
            k += cnt;
        }
    }
    return 0;
}