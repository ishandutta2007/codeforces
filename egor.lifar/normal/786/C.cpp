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
#include <cassert>

 
 
using namespace std;
 
 
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
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
const int MAXN = 100228;


int n;
int a[MAXN];
int next[MAXN];
int d[MAXN * 4];
int ans[MAXN];


void add(int v, int vl, int vr, int pos, int x) {
    d[v] += x;
    if (vl == vr - 1) {
        return;
    }
    int vn = v << 1;
    int vm = (vl + vr) >> 1;
    if (pos < vm) {
        add(vn, vl, vm, pos, x);
    } else {
        add(vn + 1, vm, vr, pos, x);
    }
}


int get(int v, int vl, int vr, int &k) {
    if (k >= d[v]) {
        k -= d[v];
        return vr - vl;
    }
    if (vl == vr - 1) {
        return 0;
    }
    int vn = v << 1;
    int vm = (vl + vr) >> 1;
    int sum = get(vn, vl, vm, k);
    if (sum == vm - vl) {
        sum += get(vn + 1, vm, vr, k);
    }
    return sum;
}


int main() {
    n = readInt();
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        a[i]--;
    }
    vector<int> last(n, n);
    for (int i = n - 1; i >= 0; i--) {
        next[i] = last[a[i]];
        last[a[i]] = i;
    }
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
        if (last[i] < n) {
            add(1, 0, n, last[i], 1);
        }
    }
    vector<vector<int> > begins(n);
    for (int i = 1; i <= n; i++) {
        begins[0].push_back(i);
    }
    memset(ans, 0, sizeof(ans));
    for (int pos = 0; pos < n; pos++) {
        for (int it = 0; it < sz(begins[pos]); it++) {
            int k = begins[pos][it];
            int nk = k;
            int go = get(1, 0, n, nk);
            if (go < n) {
                begins[go].push_back(k);
            }
            ans[k]++;
        }
        add(1, 0, n, pos, -1);
        if (next[pos] < n) {
            add(1, 0, n, next[pos], 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        writeInt(ans[i], ' ');
    }
    writeChar('\n');
    return 0;
}