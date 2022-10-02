/*
 






































 
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
const int MAXN = 300001;

int n;
int p[MAXN];
pair<int, int> d[4 * MAXN];
int ss = 1;
int f[4 * MAXN];
int mod[4 * MAXN];


void change(int i, int x) {
    d[i] = make_pair(x, i - ss);
    while (i >> 1 > 0) {
        i >>= 1;
        d[i] = min(d[i * 2], d[i * 2 + 1]);
    }
}


void push(int v) {
    if (mod[v]) {
        f[v] += mod[v];
        if (v < ss) {
            mod[v * 2] += mod[v];
            mod[v * 2 + 1] += mod[v];
        }
        mod[v] = 0;
    }
}

int rmqs(int v, int vl, int vr, int l, int r) {
    push(v);
    if (vl > r || vr < l) {
        return 1e9;
    }
    if (l <= vl && vr <= r) {
        return f[v];
    }
    return min(rmqs(v * 2, vl, (vl + vr) / 2, l, r), rmqs(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


void add(int v, int vl, int vr, int l, int r, int x) {
    if (vl > r || vr < l) {
        push(v);
        return;
    }
    if (l <= vl && vr <= r) {
        mod[v] += x;
        push(v);
        return;
    }
    push(v);
    add(v * 2, vl, (vl + vr) / 2, l, r, x); 
    add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
    f[v] = min(f[v * 2], f[v * 2 + 1]);
}


pair<int, int> rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return make_pair((int)1e9, -1);
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    return min(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


int main() {
    n = readInt();
    vector<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        p[i] = readInt();
        st.push_back(make_pair(p[i], i));
    }
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 0; i < 2 * ss; i++) {
        d[i] = make_pair((int)1e9, -1);
    }
    for (int i = 0; i < n; i++) {
        change(ss + i, p[i]);
    }
    sort(all(st));
    reverse(all(st));
    long long sum = 0;
    for (auto x: st) {
        if (d[ss + x.second].first >= 1e9) {
            continue;
        }
        if (rmqs(1, 1, ss, x.second + 1, x.second + 1) == 0) {
            pair<int, int> kek = rmq(1, 1, ss, 1, x.second);
            if (kek.first < x.first) {
                change(ss + kek.second, 1e9);
                change(ss + x.second, 1e9);
                add(1, 1, ss, kek.second + 1, n, 1);
                add(1, 1, ss, x.second + 1, n, -1);
                sum += p[x.second] - p[kek.second];
            }
        } else {
            int l = x.second;
            int r = n - 1;
            while (l != r) {
                int mid = (l + r + 1) >> 1;
                if (rmqs(1, 1, ss, x.second + 1, mid + 1) == 0) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            pair<int, int> kek = rmq(1, 1, ss, 1, x.second);
            kek = min(kek, rmq(1, 1, ss, x.second + 2, l + 1));
            if (kek.first < x.first) {
                change(ss + kek.second, 1e9);
                change(ss + x.second, 1e9);
                add(1, 1, ss, kek.second + 1, n, 1);
                add(1, 1, ss, x.second + 1, n, -1);
                sum += p[x.second] - p[kek.second];
            }
        }
    }
    cout << sum << endl;
    return 0;
}