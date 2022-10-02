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
#define y1 y1228  
const int MAXN = 100228;
const int MAXK = 10;


int n, k;
int a[MAXN][MAXK];


struct man {
    int minc[MAXK];
    int maxc[MAXK];
    set<int> ids;
    bool operator<(const man& other) const {
        for (int i = 0; i < k; i++) {
            if (maxc[i] > other.minc[i]) {
                return false;
            }
        }
        return true;
    }
};


void merge(man& a, man& b) {
    for (int i = 0; i < k; i++) {
        a.minc[i] = min(a.minc[i], b.minc[i]);
        a.maxc[i] = max(a.maxc[i], b.maxc[i]);
    }
    if (sz(b.ids) > sz(a.ids)) {
        a.ids.swap(b.ids);
    }
    for (auto x: b.ids) {
        a.ids.insert(x);
    }
    b.ids.clear();
}


int main() {
    n = readInt(), k = readInt();
    list<man> mans;
    for (int i = 0; i < n; i++) {
        man p;
        for (int j = 0; j < k; j++) {
            a[i][j] = readInt();
            p.minc[j] = p.maxc[j] = a[i][j];
        }
        p.ids.insert(i);
        if (mans.empty()) {
            mans.push_back(p);
        } else {
            while (!mans.empty()) {
                auto& p1 = mans.front();
                if (!(p < p1) && !(p1 < p)) {
                    merge(p, p1);
                    mans.pop_front();
                    continue;
                }
                auto& p2 = mans.back();
                if (!(p < p2) && !(p2 < p)) {
                    merge(p, p2);
                    mans.pop_back();
                    continue;
                }
                break;
            }
            if (mans.empty() || p < *mans.begin()) {
                mans.push_front(move(p));
            } else {
                mans.push_back(move(p));
            }
        }
        writeInt(sz(mans.back().ids), '\n');
    }
    return 0;
}