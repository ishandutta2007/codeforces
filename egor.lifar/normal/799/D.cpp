/*






  










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
const int MAXN = 100228;
const int INF = 1000 * 1000 * 1000;


int a, b, h, w, n;
int e[MAXN];
int ans = INF;
bool can[37][MAXN];


inline void solve(int k1, int k2) {
    if (k1 == 1 && k2 == 1) {
        ans = 0;
        return;
    }
    int l = 1;
    int r = min(35, n);
    while (l != r) {
        int mid = (l + r) >> 1;
        vector<int> t;
        for (int i = n - mid; i < n; i++) {
            t.push_back(e[i]);
        }
        for (int i = 0; i <= sz(t); i++) {
            for (int j = 1; j <= 100000; j++) {
                can[i][j] = 0;
            }
        }
        can[0][1] = 1;
        for (int i = 0; i < sz(t); i++) {
            for (int j = 1; j <= 100000; j++) {
                if (can[i][j]) {
                    can[i + 1][j] = 1;
                    if (1LL * j * t[i] <= 100000) {
                        can[i + 1][j * t[i]] = 1;
                    }
                }
            }
        }
        long long len = 100LL * INF;
        set<int> kek;
        for (int i = sz(t); i >= 0; i--) {
            if (i < sz(t)) {
                kek.insert(t[i]);
            }
            for (int j = 1; j <= 100000; j++) {
                if (can[i][j]) {
                    if (j >= k1) {
                        len = min(len, 1LL * j);
                    } else {
                        int kr = (k1 + j - 1) / j;
                        auto it = kek.lower_bound(kr);
                        if (it != kek.end()) {
                            len = min(len, 1LL * j * (*it));
                        }
                    }
                }
            }
        }
        if (len == 100LL * INF) {
            l = mid + 1;
            continue;
        }
        long long tp = len * k2;
        long long s = 1;
        bool good = 0;
        for (int i = 0; i < sz(t); i++) {
            s *= t[i];
            if (s >= tp) {
                good = 1;
                break;
            }
        }
        if (!good) {
            l = mid + 1;
            continue;
        }
        r = mid;
    }
    vector<int> t;
    for (int i = n - l; i < n; i++) {
        t.push_back(e[i]);
    }
    for (int i = 0; i <= sz(t); i++) {
        for (int j = 1; j <= 100000; j++) {
            can[i][j] = 0;
        }
    }
    can[0][1] = 1;
    for (int i = 0; i < sz(t); i++) {
        for (int j = 1; j <= 100000; j++) {
            if (can[i][j]) {
                can[i + 1][j] = 1;
                if (1LL * j * t[i] <= 100000) {
                    can[i + 1][j * t[i]] = 1;
                }
            }
        }
    }
    long long len = 100LL * INF;
    set<int> kek;
    for (int i = sz(t); i >= 0; i--) {
        if (i < sz(t)) {
            kek.insert(t[i]);
        }
        for (int j = 1; j <= 100000; j++) {
            if (can[i][j]) {
                if (j >= k1) {
                    len = min(len, 1LL * j);
                } else {
                    int kr = (k1 + j - 1) / j;
                    auto it = kek.lower_bound(kr);
                    if (it != kek.end()) {
                        len = min(len, 1LL * j * (*it));
                    }
                }
            }
        }
    }
    if (len == 100LL * INF) {
        return;
    }
    long long tp = len * k2;
    long long s = 1;
    bool good = 0;
    for (int i = 0; i < sz(t); i++) {
        s *= t[i];
        if (s >= tp) {
            good = 1;
            break;
        }
    }
    if (!good) {
        return;
    }
    ans = min(ans, l);
}

 
int main() {
    a = readInt(), b = readInt(), h = readInt(), w = readInt(), n = readInt();
    int s = (a + h - 1) / h;
    int s1 = (b + w - 1) / w;
    for (int i = 0; i < n; i++) {
        e[i] = readInt();
    }
    sort(e, e + n);
    solve(s, s1);
    swap(h, w);
    s = (a + h - 1) / h;
    s1 = (b + w - 1) / w;
    solve(s, s1);
    if (ans == INF) {
        writeInt(-1, '\n');
        return 0;
    }
    writeInt(ans, '\n');
    return 0;
}