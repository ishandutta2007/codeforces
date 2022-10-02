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
#define al(c) (c).begin(), (c).end()
const int MAXN = 300005;


int n;
vector<pair<int, char> > g[MAXN];
int t[MAXN * 2][26], cnt[MAXN];
int lev[MAXN], ans[MAXN], sz;
vector<pair<int, int> > l;


int add(int x, int y) {
    int c = 0;
    for(int i = 0; i < 26; i++) {
        if (!t[y][i]) {
            continue;
        }
        if (t[x][i] && t[y][i]) {
            c += add(t[x][i], t[y][i]) + 1;
        } else {
            t[x][i] = ++sz; 
            l.emplace_back(x, i);
            add(t[x][i], t[y][i]);
        }
    }
    return c;
}


void solve(int x) {
    for (int i = 0; i < 26; i++) {
        if (t[x][i]) {
            solve(t[x][i]);
        }
    }
    int f = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[t[x][i]] > cnt[t[x][f]]) {
            f = i;
        }
    }
    if (cnt[t[x][f]] == 0) {
        return;
    }
    sz = n;
    ans[lev[x]]++;
    for (int i = 0; i < 26; i++) {
        if (!t[x][i] || f == i) {
            continue;
        }
        ans[lev[x]]++;
        ans[lev[x]] += add(t[x][f], t[x][i]);
    }
    for (auto c: l) {
        t[c.first][c.second] = 0;
    }
    l.clear();
}



int dfs(int x, int p) {
    lev[x] = lev[p] + 1;
    cnt[x] = 1;
    for (auto c: g[x]) {
        if (c.first == p) {
            continue;
        }
        cnt[x] += dfs(c.first, x);
        t[x][c.second - 'a'] = c.first;
    }
    return cnt[x];
}


int main() {
    n = readInt();
    for (int i = 0; i < n - 1; i++) {
        int a = readInt(), b = readInt();
        char c = readChar();
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dfs(1, 0);
    solve(1);
    int f = 0;
    for(int i = 1; i <= n; i++){
        if (ans[f] < ans[i]) {
            f = i;
        }
    }
    cout << n - ans[f] << endl;
    cout << f << endl;
    return 0;
}