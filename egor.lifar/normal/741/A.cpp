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
 
 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const double eps = 1e-9;
const int MAXN = 2228;
const int INF = 2000000000;
const int MOD = 1000000007;
const long long LINF = 1000000000000000000LL;



int n;
bool used[MAXN];
vector<int> g[MAXN];


int getcnt(int i) {
    used[i] = true;
    int cnt = 1;
    if (!used[g[i][0]]) {
        cnt += getcnt(g[i][0]);
    }
    if (!used[g[i][1]]) {
        cnt += getcnt(g[i][1]);
    }
    return cnt;
} 



inline long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}


int main() {
    n = readInt();
    for (int i = 0; i < n; i++) {
        int a = readInt();
        a--;
        g[a].push_back(i);
        g[i].push_back(a);
        if (sz(g[a]) > 2 || sz(g[i]) > 2) {
            writeWord("-1\n");
            return 0;
        }
    }
    long long NOK = 1;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        int ans = getcnt(i);
        if (ans % 2 == 1) {
            NOK = NOK * ans / gcd(NOK, ans);
        } else {
            ans /= 2;
            NOK = NOK * ans / gcd(NOK, ans);
        }    
    }
    writeInt(NOK, '\n');
    return 0;
}