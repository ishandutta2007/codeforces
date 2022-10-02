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
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 100001;

 
long long powm(long long x, int n, long long m) {
    if (n == 0) {
        return 1LL;
    } else if (n & 1) {
        return (x * powm(x, n ^ 1, m)) % m;
    }  else {
        long long t = powm(x, n >> 1, m);
        return (t * t) % m;
    }
}

 
long long div(long long a, long long b, long long m) {
    return (a * powm(b, m - 2LL, m)) % m;
}
 
int n;
long long m;
vector<int> a;

 
inline bool good(int d, int& start) {
    int cur = a[0];
    int cnt = 0;
    auto it = lower_bound(all(a), cur);
    while (it != a.end() && *it == cur) {
        cur += d;
        if (cur >= m) {
            cur -= m;
        }
        cnt++;
        it = lower_bound(all(a), cur);
    }
    cur = a[0];
    it = lower_bound(all(a), cur);
    while (it != a.end() && *it == cur) {
        start = cur;
        cur -= d;
        if (cur < 0) {
            cur += m;
        }
        cnt++;
        it = lower_bound(all(a), cur);
    }
    return cnt == n + 1;
}
 

inline int countDiff(int d) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int y = a[i] - d;
        if (y >= m) {
            y -= m;
        }
        if (y < 0) {
            y += m;
        }
        if (a[i] <= y) {
            auto it = lower_bound(all(a), y);
            if (it != a.end() && *it == y) {
                cnt++;
            }
        }
        y = a[i] + d;
        if (y >= m) {
            y -= m;
        }
        if (y < 0) {
            y += m;
        }
        if (a[i] <= y) {
            auto it = lower_bound(all(a), y);
            if (it != a.end() && *it == y) {
                cnt++;
            }
        }
    }
    return cnt;
}
 

inline pair<int, int> solve() {
    if (n == 0) {
        return make_pair(1, 1);
    }
    if (n == 1) {
        return make_pair(a[0], 1);
    }
    sort(all(a));
    int start;
    int difference = a[1] - a[0];
    int k = n - countDiff(difference);
    int d = div(difference, k, m);
    if (good(d, start)) {
        return make_pair(start, d);
    } else {
        return make_pair(-1, -1);
    }
}
 

vector<int> c;


int main() {
    m = readInt(), n = readInt();
    c.resize(n);
    for (int i = 0; i < n; i++) {
        c[i] = readInt();
    }
    if (n == 1) {
        writeInt(c[0], ' ');
        writeInt(1, '\n');
        return 0;
    }
    pair<int, int> ans = make_pair(-1, -1); 
    if (2 * n >= m) {
        sort(all(c));
        vector<int> b;
        for (int i = 0; i < m; i++) {
            auto it = lower_bound(all(c), i);
            if (it == c.end() || *it != i) {
                b.push_back(i);
            }
        }
        n = m - n;
        a = b;
        pair<int, int> nans = solve();
        if (nans.first > -1) {
            ans.second = nans.second;
            ans.first = (nans.first + 1LL * n * nans.second) % m;
        }
    } else {
        a = c;
        ans = solve();
    }
    if (ans.first == -1) {
        writeInt(-1, '\n');
    } else {
        writeInt(ans.first, ' ');
        writeInt(ans.second, '\n');
    }
    return 0;
}