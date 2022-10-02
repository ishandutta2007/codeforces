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
const int MAXN = 1000001;


int n, m;
int c[MAXN], w[MAXN];
bool coup[MAXN];


int main() {
    n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
        c[i] = readInt();
    }
    for (int i = 1; i <= n; i++) {
        w[i] = readInt();
    }
    set<pair<long long, int> > st;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] % 100 == 0) {
            continue;
        }
        st.insert(make_pair(1LL * (100 - (c[i] % 100)) * w[i], i));
        m -= (c[i] % 100);
        while (m < 0) {
            pair<long long, int> a = *st.begin();
            st.erase(a);
            m += 100;
            ans += a.first;
            coup[a.second] = true;
        }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) {
        if (coup[i]) {
            writeInt((c[i] + 99) / 100, ' ');
            writeWord("0\n");
        } else {
            writeInt(c[i] / 100, ' ');
            writeInt(c[i] % 100, '\n');
        }
    }
    return 0;
}