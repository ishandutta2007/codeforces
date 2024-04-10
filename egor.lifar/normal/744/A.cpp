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
const int MAXN = 200001;


int n, m, k;
int c[MAXN];
vector<int> v[MAXN];
bool used[MAXN];
vector<int> t;


void dfs(int u) {
    used[u] = 1;
    t.push_back(u);
    for (auto h: v[u]) {
        if (!used[h]) {
            dfs(h);
        }
    }
}

 
int main() {
    n = readInt(), m = readInt(), k = readInt();
    for (int i = 0; i < k; i++) {
        c[i] = readInt();
        c[i]--;
    }
    for (int i = 0; i < m; i++) {
        int a = readInt(), b = readInt();
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    long long ans = 0;
    int cnt = n;
    int f = 0;
    for (int i = 0; i < k; i++) {
        t.clear();
        dfs(c[i]);
        f = max(f, sz(t));
        cnt -= sz(t);
        int sum = sz(t) * (sz(t) - 1);
        for (auto x: t) {
            sum -= sz(v[x]);
        }
        sum /= 2;
        ans += sum;
    }
    ans += 1LL * cnt * f;
    ans += 1LL * (cnt - 1) * cnt / 2LL;
    int vit = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            vit += sz(v[i]);
        }
    }
    ans -= vit / 2;
    cout << ans << endl;
    return 0;   
}