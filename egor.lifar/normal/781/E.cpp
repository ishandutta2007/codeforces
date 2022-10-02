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
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
const int MAXN = 100001;
const int INF = 1000 * 1000 * 1000 + 2;
const int Mod = 1000 * 1000 * 1000 + 7;


struct lane {
    int l, r, s, u;
};


stack<pair<int, int> > sc[MAXN];
int top[MAXN];
lane a[MAXN];
int rid[MAXN];


void er(int id) {
    sc[id].pop();
    top[id] = sc[id].top().first;
}


bool cmp(lane l1, lane l2) {
    return l1.s > l2.s;
}


int t[4 * MAXN];


inline int getBest(int i1, int i2) {
    return (top[i1] < top[i2]) ? i1 : i2;
}


void buildRMQ(int v, int l, int r) {
    if (l == r) {
        rid[l] = v;
        t[v] = l;
        return;
    }
    buildRMQ((v << 1) + 1, l, (l + r) / 2);
    buildRMQ((v << 1) + 2, (l + r) / 2 + 1, r);
    t[v] = getBest(t[(v << 1) + 1], t[(v << 1) + 2]);
}


int rmq(int v, int l, int r, int vl, int vr) {
    if (vl > r || l > vr) {
        return 0;
    }
    if (vl <= l && r <= vr) {
        return t[v];
    }
    return getBest(rmq((v << 1) + 1, l, (l + r) / 2, vl, vr), rmq((v << 1) + 2, (l + r) / 2 + 1, r, vl, vr));
}


void add(int l) {
    int v = rid[l];
    while (v != 0) {
        v = (v - 1) >> 1;
        t[v] = getBest(t[(v << 1) + 1], t[(v << 1) + 2]);
    }
}


void push(int id, int x, int y) {
    sc[id].push(make_pair(x, y));
    top[id] = x;
    add(id);
}


int main() {
    int h = readInt(), w = readInt(), n = readInt();
    top[0] = 2 * INF + 4;
    for (int i = 1; i <= w; i++) {
        push(i, 2 * INF + 3, 0);
        push(i, h + 1, 1);
    }
    buildRMQ(0, 1, w);
    for (int i = 0; i < n; i++) {
        a[i].s = readInt(), a[i].l = readInt(), a[i].r = readInt(), a[i].u = readInt();
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        int vl = a[i].l, vr = a[i].r;
        int y = a[i].s;
        int ly = a[i].s + a[i].u;
        int cur = 0;
        while (true) {
            int v = rmq(0, 1, w, vl, vr);
            if (top[v] > ly) {
                break;
            }
            cur = (cur + sc[v].top().second) % Mod;
            er(v);
            add(v);
        }
        if (vl == 1) {
            push(vr + 1, y, (cur * 2) % Mod);
        } else if (vr == w) {
            push(vl - 1, y, (cur * 2) % Mod);
        } else {
            push(vl - 1, y, cur), push(vr + 1, y, cur);
        }
    }
    int ans = 0;
    for (int i = 1; i <= w; i++) {
        while (!sc[i].empty()) {
            ans += sc[i].top().second;
            ans %= Mod;
            sc[i].pop();
        }
    }
    writeInt(ans, '\n');
    return 0;
}