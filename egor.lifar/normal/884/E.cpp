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
#define rank rank228
#define prev prev228
#define y1 y1228  
const int MAXN = 4096;
const int MAXN1 = 16384;
const int MAXN2 = 8192;


int n, m;
bitset<MAXN> kek[MAXN1];
bitset<MAXN2> used;
int parent2[MAXN2];
int parent1[MAXN2];
int parent[MAXN2];
int sz[MAXN2];


int find_set(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}


bool set_union(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) {
        return false;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}


int main() {
    n = readInt(), m = readInt();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 4; j++) {
            char c = readChar();
            int t = 0;
            if (c >= '0' && c <= '9') {
                t = c - '0';
            } else {
                t = 10 + c - 'A';
            }
            kek[(j << 2) + 3][i] = t & 1;
            kek[(j << 2) + 2][i] = (t >> 1) & 1;
            kek[(j << 2) + 1][i] = (t >> 2) & 1;
            kek[(j << 2)][i] = (t >> 3) & 1;
        }
    }
    for (int i = 0; i < n; i++) {
        parent1[i] = -1;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        used.reset();
        for (int j = 0; j < MAXN2; j++) {
            parent[j] = j; 
            sz[j] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (parent1[j] != -1) {
                used[parent1[j]] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            parent2[j] = -1;
        }
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (!kek[i][j]) {
                continue;
            }
            if (j && kek[i][j - 1]) {
                parent2[j] = parent2[j - 1];
            } else {
                while (used[cur]) {
                    cur++;
                }
                parent2[j] = cur;
                used[cur] = 1;
                ans++;
            }
        }
        for (int j = 0; j < n; j++) {
            if (parent1[j] != -1 && parent2[j] != -1) {
                ans -= set_union(parent1[j], parent2[j]);
            }
        }
        for (int j = 0; j < n; j++) {
            if (parent2[j] != -1) {
                parent1[j] = find_set(parent2[j]);
            } else {
                parent1[j] = -1;
            }
        }
    }
    writeInt(ans, '\n');
    return 0;
}