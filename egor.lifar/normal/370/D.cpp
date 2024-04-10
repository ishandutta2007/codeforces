/*
  !










*/
#pragma GCC optimize "-O3"
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
const int MAXN = 2001;


int n, m;
char c[MAXN][MAXN];


int main () {  
    n = readInt(), m = readInt();
    int minx = n, maxx = -1, miny = m, maxy = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = readChar();
            if (c[i][j] == 'w') {
                cnt++;
                chkmin(minx, i);
                chkmin(miny, j);
                chkmax(maxx, i);
                chkmax(maxy, j);
            }
        }
    }
    int d = max(maxx - minx + 1, maxy - miny + 1);
    vector<int> vx;
    vx.push_back(minx);
    vx.push_back(maxx - d + 1);
    vx.push_back(0);
    vector<int> vy;
    vy.push_back(miny);
    vy.push_back(maxy - d + 1);
    vy.push_back(0);
    for (auto x: vx) {
        for (auto y: vy) {
            vector<pair<int, int> > v;
            for (int i = 0; i < d; i++) {
                v.push_back(make_pair(x + i, y));
            }
            for (int i = 1; i < d; i++) {
                v.push_back(make_pair(x, y + i));
            }
            for (int i = 1; i < d; i++) {
                v.push_back(make_pair(x + d - 1, y + i));
            }
            for (int i = 1; i < d - 1; i++) {
                v.push_back(make_pair(x + i, y + d - 1));
            }
            int res = 0;
            bool bad = false;
            for (auto p: v) {
                if (p.first < 0 || p.second < 0 || p.first >= n || p.second >= m) {
                    bad = true;
                    break;
                }
                if (c[p.first][p.second] == 'w') {
                    res++;
                }
            }
            if (res == cnt && !bad) {
                for (auto p: v) {
                    if (c[p.first][p.second] != 'w') {
                        c[p.first][p.second] = '+';
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        writeChar(c[i][j]);
                    }
                    writeChar('\n');
                }
                exit(0);
            }
        }
    }
    writeInt(-1, '\n');
    return 0;           
}