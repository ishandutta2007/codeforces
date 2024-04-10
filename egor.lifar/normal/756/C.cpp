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
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 200001;


int n;
int d[4 * MAXN];
int mod[4 * MAXN];
int ss = 1;
int who[MAXN];


void push(int v) {
    if (mod[v] != 0) {
        d[v] += mod[v];
        if (v < ss) {
            int vn = v << 1;
            mod[vn] += mod[v];
            mod[vn + 1] += mod[v];
        }
        mod[v] = 0;
    }
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
    int vn = v << 1;
    int vm = (vl + vr) >> 1;
    add(vn, vl, vm, l, r, x);
    add(vn + 1, vm + 1, vr, l, r, x);
    d[v] = max(d[vn], d[vn + 1]); 
}


int spusk(int v, int vl, int vr) {
    push(v);
    if (d[v] <= 0) {
        return -1;
    }
    if (vl == vr) {
        return vl;
    }
    int vn = v << 1;
    push(vn);
    push(vn + 1);
    int vm = (vl + vr) >> 1;
    if (d[vn + 1] > 0) {
        return spusk(vn + 1, vm + 1, vr);
    }
    return spusk(vn, vl, vm);
}


int main() {
    n = readInt();
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 0; i < n; i++) {
        int p = readInt(), t = readInt();
        p--;
        if (t == 0) {
            add(1, 1, ss, 1, p + 1, -1);
        } else {
            int x = readInt();
            who[p] = x;
            add(1, 1, ss, 1, p + 1, 1);
        }
        int f = spusk(1, 1, ss);
        if (f == -1) {
            writeInt(-1, '\n');
        } else {
            writeInt(who[f - 1], '\n');
        }
    }
    return 0;   
}