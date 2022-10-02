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
 
 
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define left _left
#define right _right
#define last _last
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 300001;
const int INF = 1000000000;


int n;
int a[MAXN];
vector<int> v[MAXN];


int main() {
    n = readInt();
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        s.insert(a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int g = readInt(), f = readInt();
        g--, f--;
        v[g].push_back(f);
        v[f].push_back(g);
    }
    int ans = 2 * INF;
    for (int i = 0; i < n; i++) {
        int t = -INF;
        for (auto x: v[i]) {
            s.erase(s.find(a[x]));
            t = max(t, a[x] + 1);
        }
        s.erase(s.find(a[i]));
        t = max(t, a[i]);
        if (!s.empty()) {
            t = max(t, *(s.rbegin()) + 2);
        }
        s.insert(a[i]);
        for (auto x: v[i]) {
            s.insert(a[x]);
        }
        ans = min(ans, t);
    }
    writeInt(ans, '\n');
    return 0;
}