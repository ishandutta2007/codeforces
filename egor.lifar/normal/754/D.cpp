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
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 303228;


int n, k;
int l[MAXN], r[MAXN];
unordered_map<int, int> who;
vector<int> zp[2 * MAXN];
vector<int> zm[2 * MAXN];
int d[MAXN * 4];
int where[MAXN];


void change(int i, int x) {
    d[i] = x;
    while ((i >> 1) > 0) {
        i >>= 1;
        d[i] = d[(i << 1)] + d[(i << 1) + 1];
    }
}


int rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    int vm = (vl + vr) >> 1;
    return rmq((v << 1), vl, vm, l, r) + rmq((v << 1) + 1, vm + 1, vr, l, r);
}


int binl[2 * MAXN];
bool on[2 * MAXN];


int main() {
    n = readInt(), k = readInt();
    vector<int> v;
    vector<pair<int, int> > rr;
    for (int i = 0; i < n; i++) {
        l[i] = readInt(), r[i] = readInt();
        rr.push_back(make_pair(r[i], i));
        v.push_back(l[i]);
        v.push_back(r[i] + 1);
    }
    sort(all(rr));
    reverse(all(rr));
    for (int i = 0; i < n; i++) {
        where[rr[i].second] = i;
    }
    sort(all(v));
    v.resize(distance(v.begin(), unique(all(v))));
    for (int i = 0; i < sz(v); i++) {
        who[v[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        zp[who[l[i]]].push_back(i);
        zm[who[r[i] + 1]].push_back(i);
    }
    int ss = 1;
    while (ss < n) {
        ss <<= 1;
    }
    int ans = 0;
    for (int i = 0; i < sz(v); i++) {
        for (auto p: zp[i]) {
            change(ss + where[p], 1);
        }
        for (auto p: zm[i]) {
            change(ss + where[p], 0);
        }
        if (d[1] >= k) {
            int l = 0;
            int r = n - 1;
            while (l != r) {
                int m = (l + r) >> 1;
                if (rmq(1, 1, ss, 1, m + 1) >= k) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            binl[i] = l;
            ans = max(ans, rr[l].first - v[i] + 1);
        } else {
            binl[i] = -1;
        }
    }   
    writeInt(ans, '\n');
    for (int i = 0; i < sz(v); i++) {
        for (auto p: zp[i]) {
            on[where[p]] = 1;
        }
        for (auto p: zm[i]) {
            on[where[p]] = 0;
        }
        int l = binl[i];
        if (l == -1) {
            continue;
        }
        if (ans == rr[l].first - v[i] + 1) {
            for (int i = 0; i <= l; i++) {
                if (on[i]) {
                    writeInt(rr[i].second + 1, ' ');
                }
            }
            writeChar('\n');
            return 0;
        }
    }
    for (int i = 1; i <= k; i++) {
        writeInt(i, ' ');
    }
    writeWord("\n");
    return 0;
}