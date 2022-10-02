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
#define al(c) (c).begin(), (c).end()
#define ral(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
const int MAXN = 300001;


int m;
int pr[21][MAXN], deep[MAXN];
set<int> l;


int dist(int a, int b) {
    int aa = a, bb = b;
    if (deep[aa] > deep[bb]) {
        swap(aa, bb);
    }
    for (int i = 19; i >= 0; i--) { 
        if (deep[bb] - deep[aa] >= 1 << i) {
            bb = pr[i][bb];
        }
    }
    for (int i = 19; i >= 0; i--) { 
        if (pr[i][aa] != pr[i][bb]) {
            aa = pr[i][aa], bb = pr[i][bb];
        }
    }
    return deep[a] + deep[b] - 2 * deep[(aa == bb) ? aa: pr[0][aa]];
}


int main () {  
    m = readInt();
    for (int i = 0; i < m; i++) {
        pr[0][i + 1] = readInt();
        pr[0][i + 1]--;
        deep[i + 1] = deep[pr[0][i + 1]] + 1;
    }
    m++;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < m; j++) {
            pr[i + 1][j] = pr[i][pr[i][j]];
        }
    }
    writeInt(2, '\n');
    int x = 0, y = 1;
    int diam = 1;
    l.insert(0);
    l.insert(1);
    for (int i = 2; i < m; i++) {
        l.erase(pr[0][i]);
        int dx = dist(x, i);
        int dy = dist(y, i);
        if (dx <= diam && dy <= diam) {
            if (dx == diam || dy == diam) {
                l.insert(i);
            }
        } else {
            if (dy > diam) {
                swap(x, y); 
                swap(dx, dy);
            }
            diam = dx;
            y = i;
            set<int> l2 = l;
            l.clear();
            for (auto r: l2) {
                if (dist(r, y) == diam) {
                    l.insert(r);
                }
            }
            l.insert(x);
            l.insert(y);
        }
        writeInt(sz(l), '\n');
    }
    return 0;           
}