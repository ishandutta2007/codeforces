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
const int MAXN = 510;
const long long INF = 1000000000;


vector<pair<pair<long long, long long>, pair<long long, long long> > > events;
multiset<pair<long long, long long> > ms;


bool good(int l, int r) {
    long long next = l;
    for (auto i: ms) {
        if (i.first <= next && next <= i.second) {
            next = i.second + 1;
        }
    }
    return next <= r;
}


pair<long long, long long> solve(long long n, long long m) {
    events.push_back({{m + 1, -1}, {1, n}});
    sort(all(events));
    long long l = m + 1, r = 0, last_y = 1;
    ms.clear();
    for (auto i: events) {
        long long y = i.first.first;
        int type = i.first.second;
        if (last_y < y && good(1, n))  {
            chkmin(l, last_y);
            chkmax(r, y - 1);
        }
        if (type == -1) {
            ms.insert(i.second);
        } else {
            ms.erase(ms.find(i.second));
        }
        last_y = y;
    }
    return make_pair(l, r);
}


long long n, m;
int k;
long long x[MAXN], y[MAXN];


int main() {
    n = readInt(), m = readInt(), k = readInt();
    for (int i = 0; i < k; i++) {
        x[i] = readInt(), y[i] = readInt();
    }
    long long l = 0, r = INF;
    while (l <= r) {
        long long t = (l + r) >> 1ll;
        events.clear();
        for (int i = 0; i < k; i++) {
            events.push_back({{max(1ll, y[i] - t), -1ll}, {x[i] - t, x[i] + t}});
            events.push_back({{min(y[i] + t + 1, m + 1), 1ll}, {x[i] - t, x[i] + t}});
        }
        pair<long long, long long> p = solve(n, m);
        if (p.second - p.first > 2 * t) {
            l = t + 1;
            continue;
        }
        events.clear();
        for (int i = 0; i < k; i++) {
            events.push_back({{max(1ll, x[i] - t), -1ll}, {y[i] - t, y[i] + t}});
            events.push_back({{min(x[i] + t + 1, n + 1), 1ll}, {y[i] - t, y[i] + t}});
        }
        p = solve(m, n);
        if (p.second - p.first > 2 * t) {
            l = t + 1;
        } else {
            r = t - 1;
        }
    }
    writeInt(r + 1, '\n');
    return 0;
}