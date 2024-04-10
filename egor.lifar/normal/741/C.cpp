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
const int MAXN = 228228;
const int INF = 2000000000;
const int MOD = 1000000007;
const long long LINF = 1000000000000000000LL;


int n;
int p[MAXN];
int a[MAXN];
int b[MAXN];
int ans[MAXN];


int main() {
    srand(time(NULL));
    n = readInt();
    for (int i = 0; i < n; i++) {
        a[i] = readInt(), b[i] = readInt();
        a[i]--, b[i]--;
        p[a[i]] = b[i];
        p[b[i]] = a[i];
        ans[a[i]] = 1;
        ans[b[i]] = 2;
    }
    n *= 2;
    int i = 0;
    int cnt = 0;
    int iter = 0;
    while (cnt < n) {
        iter++;
        if (iter > 75757575) {
            cout << -1 << endl;
            return 0;
        }
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        if (ans[i] != ans[j] || ans[i] != ans[k]) {
            cnt++;
            i = (i + 1) % n;
            continue;
        }
        cnt = 0;
        if (rand() % 2 == 1) {
            swap(ans[j], ans[p[j]]);
        }  else {
            swap(ans[k], ans[p[k]]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        writeInt(ans[a[i]], ' ');
        writeInt(ans[b[i]], '\n');
    }
    return 0;
}