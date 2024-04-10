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
 
struct flusher {
    ~flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
#define hash hash228 
#define next next228
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 7001;


int n;
int k1;
int s1[MAXN];
int k2;
int s2[MAXN];
vector<int> g[MAXN][2];
bool win[MAXN][2];
bool lose[MAXN][2];
bool used[MAXN][2];
int degree[MAXN][2];


void dfs(int v, int t) {
    used[v][t] = true;
    if (t == 0) {
        for (int i = 0; i < k2; i++) {
            int j = (v - s2[i] + n) % n;
            if (!used[j][t ^ 1]) {
                if (lose[v][t]) {
                    win[j][t ^ 1] = true;
                } else if (--degree[j][t ^ 1] == 0) {
                    lose[j][t ^ 1] = true;
                } else {
                    continue;
                }
                dfs(j, t ^ 1);
            }
        }
    } else {
        for (int i = 0; i < k1; i++) {
            int j = (v - s1[i] + n) % n;
            if (!used[j][t ^ 1]) {
                if (lose[v][t]) {
                    win[j][t ^ 1] = true;
                } else if (--degree[j][t ^ 1] == 0) {
                    lose[j][t ^ 1] = true;
                } else {
                    continue;
                }
                dfs(j, t ^ 1);
            }
        }
    }
}


int main() {    
    n = readInt();
    k1 = readInt();
    for (int i = 0; i < k1; i++) {
        s1[i] = readInt();
    }
    k2 = readInt();
    for (int i = 0; i < k2; i++) {
        s2[i] = readInt();
    }
    for (int i = 0; i < n; i++) {
        degree[i][0] = k1;
        degree[i][1] = k2;
    }
    lose[0][0] = 1;
    lose[0][1] = 1;
    if (!used[0][0]) {
        dfs(0, 0);
    }
    if (!used[0][1]) {
        dfs(0, 1);
    }
    for (int i = 1; i < n; i++) {
        if (win[i][0]) {
            writeWord("Win ");
        } else {
            if (!lose[i][0]) {
                writeWord("Loop ");
            } else {
                writeWord("Lose ");   
            }
        }
    }
    writeChar('\n');
    for (int i = 1; i < n; i++) {
        if (win[i][1]) {
            writeWord("Win ");
        } else {
            if (!lose[i][1]) {
                writeWord("Loop ");
            } else {
                writeWord("Lose ");   
            }
        }
    }
    writeChar('\n');
    return 0;
}