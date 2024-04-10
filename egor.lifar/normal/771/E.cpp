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
#define next next228
#define rank rank228
#define prev prev228
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define eb emplace_back
const int MAXN = 300300;


int n;
int a[MAXN];
int b[MAXN];
long long sumsa[MAXN];
long long sumsb[MAXN];
int dp[MAXN];
int ul[MAXN];
int dl[MAXN];
map<long long, int> mf, fa, fb;
map<int, int> dm[MAXN];


int solve(int l, int r) {
    if (l == r) {
        return dp[l];
    }
    if (dm[l].count(r)) {
        return dm[l][r];
    }
    dm[l][r] = dp[min(l, r)];
    if (l < r) {
        if (dl[r] != -1) {
            chkmax(dm[l][r], solve(l, dl[r]) + 1);
        }
    } else {
        if (ul[l] != -1) {
            chkmax(dm[l][r], solve(ul[l], r) + 1);
        }
    }
    return dm[l][r];
}


int main() {
    n = readInt();
    for (int i = 1; i <= n; i++) {
        a[i] = readInt();
        sumsa[i] = sumsa[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = readInt();
        sumsb[i] = sumsb[i - 1] + b[i];
    }
    mf[0] = 0;
    fa[0] = 0;
    fb[0] = 0;
    ul[0] = -1;
    dl[0] = -1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        long long cf = sumsa[i] + sumsb[i];
        if (mf.count(cf)) {
            chkmax(dp[i], 1 + dp[mf[cf]]);
        }
        mf[cf] = i;
        ul[i] = ul[i - 1];
        dl[i] = dl[i - 1];
        if (fa.count(sumsa[i])) {
            if (ul[i] < fa[sumsa[i]]) {
                ul[i] = fa[sumsa[i]];
            }
        }
        if (fb.count(sumsb[i])) {
            if (dl[i] < fb[sumsb[i]]) {
                dl[i] = fb[sumsb[i]];
            }
        }
        if (ul[i] != -1) {
            chkmax(dp[i], solve(ul[i], i) + 1);
        }
        if (dl[i] != -1) {
            chkmax(dp[i], solve(i, dl[i]) + 1);
        }
        fa[sumsa[i]] = i;
        fb[sumsb[i]] = i;
    }
    writeInt(dp[n], '\n');
    return 0;
}