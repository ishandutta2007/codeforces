#pragma GCC optimize "-oFast"
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
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
const int MAXN = 300228;
const int INF = 1000000228;


int n;
vector<pair<long long, int> > st;
vector<pair<int, int> > go[MAXN];
long long a[MAXN];
long long ans[MAXN];
int mx[MAXN * 4];
long long mn[MAXN * 4];
long long dd[MAXN * 4];


void build(int v, int tl, int tr) {
    mn[v] = INF;
    mx[v] = -1;
    dd[v] = INF;
    if (tl + 1 == tr) {
        return;
    }
    int m = (tl + tr) >> 1;
    build((v << 1) + 1, tl, m);
    build((v << 1) + 2, m, tr);
}


int getMax(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l) {
        return -1;
    }
    if (l <= tl && tr <= r) {
        return mx[v];
    }
    int m = (tl + tr) >> 1;
    return max(getMax((v << 1) + 1, tl, m, l, r), getMax((v << 1) + 2, m, tr, l, r));
}


long long get(int v, int tl, int tr, int x) {
    if (tl + 1 == tr) {
        return mn[v];
    }
    int m = (tl + tr) >> 1;
    if (x < m) {
        return min(get((v << 1) + 1, tl, m, x), dd[v]);
    } else {
        return min(get((v << 1) + 2, m, tr, x), dd[v]);
    }
}


void updateMin(int v, int tl, int tr, int l, int r, long long x) {
    if (r <= tl || tr <= l) {
        return;
    }
    if (l <= tl && tr <= r) {
        dd[v] = min(dd[v], x);
        mn[v] = min(mn[v], x);
        return;
    }
    int m = (tl + tr) >> 1;
    updateMin((v << 1) + 1, tl, m, l, r, x);
    updateMin((v << 1) + 2, m, tr, l, r, x);
    mn[v] = min(mn[(v << 1) + 1], mn[(v << 1) + 2]);
    mn[v] = min(mn[v], dd[v]);
}


void updateMax(int v, int tl, int tr, int x, int y) {
    mx[v] = max(mx[v], y);
    if (tl + 1 == tr) {
        return;
    }
    int m = (tl + tr) >> 1;
    if (x < m) {
        updateMax((v << 1) + 1, tl, m, x, y);
    } else {
        updateMax((v << 1) + 2, m, tr, x, y);
    }
}


int main() {
    n = readInt();
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        st.push_back(make_pair(a[i], i));
    }
    sort(all(st));
    int m = readInt();
    for (int i = 0; i < m; ++i) {
        int l = readInt(), r = readInt();
        l--, r--;
        go[r].push_back(make_pair(l, i));
    }
    build(0, 0, n);
    for (int i = 0; i < n; i++) {
        int pl = lower_bound(all(st), make_pair(a[i], i)) - st.begin();
        long long now = INF;
        while (true) {
            int x = lower_bound(all(st), make_pair(a[i] + now + 1, 0)) - st.begin();
            if (pl + 1 >= x) {
                break;
            }
            x = getMax(0, 0, n, pl + 1, x);
            if (x == -1) {
                break;
            }
            long long d = a[x] - a[i];
            updateMin(0, 0, n, 0, x + 1, d);
            if (d == 0) {
                break;
            }
            now = d / 2;
        }
        now = INF;
        while (true) {
            int x = lower_bound(all(st), make_pair(a[i] - now, 0)) - st.begin();
            if (x >= pl) {
                break;
            }
            x = getMax(0, 0, n, x, pl);
            if (x == -1) {
                break;
            }
            long long d = a[i] - a[x];
            updateMin(0, 0, n, 0, x + 1, d);
            if (d == 0) {
                break;
            }
            now = d / 2;
        }
        updateMax(0, 0, n, pl, i);
        for (auto q: go[i]) {
            ans[q.second] = get(0, 0, n, q.first);
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}