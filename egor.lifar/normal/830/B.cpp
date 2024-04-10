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
const int MAXN = 100003;


int n;
int a[MAXN];
set<int> where[MAXN];
multiset<int> all;
set<int> posa;
int tr[3 * MAXN];
int ss = 1;


void change(int i, int x) {
    tr[i] = x;
    while (i >> 1 > 0) {
        i >>= 1;
        tr[i] = tr[i << 1] + tr[(i << 1) + 1];
    }
}


int rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l || l > r) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return tr[v];
    }
    int vn = v << 1;
    int vm = (vl + vr) >> 1;
    return rmq(vn, vl, vm, l, r) + rmq(vn + 1, vm + 1, vr, l, r);
}


inline int getcnt(int l, int r) {
    return rmq(1, 1, ss, l + 1, r + 1);
}



int main() {
    n = readInt();
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        all.insert(a[i]);
        where[a[i]].insert(i);
        posa.insert(i);
        change(ss + i, 1);
    }
    int pos = 0;
    long long sum = 0;
    for (int its = 0; its < n; its++) {
        int p = *all.begin();
        all.erase(all.find(p));
        auto it = where[p].lower_bound(pos);
        if (it == where[p].end()) {
            sum += getcnt(pos, n - 1);
            pos = *posa.begin();
            it = where[p].lower_bound(pos);
            int t = *it;
            where[p].erase(t);
            sum += getcnt(pos, t);
            posa.erase(t);
            change(ss + t, 0);
            pos = t + 1;
        } else {
            int t = *it;
            where[p].erase(t);
            sum += getcnt(pos, t);
            posa.erase(t);
            change(ss + t, 0);
            pos = t + 1;
        }
    }
    cout << sum << '\n';
    return 0;
}