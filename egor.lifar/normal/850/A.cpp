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
#define get get228
#define y1 y1228    
const int MAXN = 1001;


int n;


long long vec(long long a, long long b, long long c, long long d, long long e, long long a1, long long b1, long long c1, long long d1, long long e1) {
    return a * a1 + b * b1 + c * c1 + d * d1 + e * e1;
} 


long long a[MAXN], b[MAXN], c[MAXN], d[MAXN], e[MAXN];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool bad = 0;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            for (int k = j + 1; k < n; k++) {
                if (k == i) {
                    continue;
                }
                long long f = vec(a[j] - a[i], b[j] - b[i], c[j] - c[i], d[j] - d[i], e[j] - e[i], a[k] - a[i], b[k] - b[i], c[k] - c[i], d[k] - d[i], e[k] - e[i]);
                if (f > 0) {
                    bad = true;
                    break;
                } 
            }
            if (bad) {
                break;
            }
        }
        if (!bad) {
            ans.push_back(i + 1);
        }
    }
    writeInt(sz(ans), '\n');
    for (auto x: ans) {
        writeInt(x, ' ');
    }
    writeChar('\n');
    return 0;
}