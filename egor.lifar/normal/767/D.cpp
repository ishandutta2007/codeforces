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


int n, m, k;
vector<pair<int, int> > s, f;


bool get(int cnt) {
    vector<pair<int, int> > g;
    if (cnt == 0) {
        g = s;
    } else {
        g.resize(sz(s) + cnt);
        merge(all(s), f.end() - cnt, f.end(), g.begin());
    }
    int cur = 0;
    int ost = 0;
    for (int i = 0; i < sz(g); i++) {
        if (cur > g[i].first) {
            return 0;
        }
        ost++;
        if (ost == k) {
            ost = 0;
            cur++;
        }
    }
    return 1;
}

 
int main() {    
    n = readInt(), m = readInt(), k = readInt();
    s.resize(n);
    for (int i = 0; i < n; i++) {
        s[i].first = readInt();
        s[i].second = i + 1;
    }
    sort(all(s));
    f.resize(m);
    for (int i = 0; i < m; i++) {
        f[i].first = readInt();
        f[i].second = i + 1;
    }
    sort(all(f));
    if (!get(0)) {
        writeWord("-1\n");
        return 0;
    }
    int l = 0;
    int r = m;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        if (get(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    writeInt(l, '\n');
    for (int i = m - 1; i >= m - l; i--) {
        writeInt(f[i].second, ' ');
    }
    writeChar('\n');
    return 0;
}