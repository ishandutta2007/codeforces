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
  

#define next next228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 1000001;

int n, k;
int d[MAXN * 4];

void change(int i, int x) {
    d[i] += x;
    while (i >> 1 > 0) {
        i >>= 1;
        d[i] = d[(i << 1)] + d[(i << 1) + 1];
    }
}


int rmq(int v, int vl, int vr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    int vm = (vl + vr) >> 1;
    int vn = v << 1;
    return rmq(vn, vl, vm, l, r) + rmq(vn + 1, vm + 1, vr, l, r);
}



int main() {
    n = readInt(), k = readInt();
    if (k > n / 2) {
        k = n - k;
    }
    int ss = 1;
    while (ss < n) {
        ss <<= 1;
    }
    long long cnt = 1;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        change(ss + cur - 1, 1);
        int next = cur + k;
        cnt++;
        if (next > n) {
            next -= n;
            cnt += rmq(1, 1, ss, cur + 1, n) + rmq(1, 1, ss, 1, next - 1);
        } else {
            cnt += rmq(1, 1, ss, cur + 1, next - 1);
        }
        cur = next;
        change(ss + cur - 1, 1);
        writeInt(cnt, ' ');
    }
    writeChar('\n');
    return 0;
}