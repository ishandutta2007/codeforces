/*
  !










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
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
const int MAXN = 5228;


int sz[MAXN];
vector<int> edges[MAXN], st;
int dp[2 * MAXN];
int n;
int a, b, c, d;


int dfs(int v) {
    sz[v] = 0;
    if (edges[v].empty()) {
        sz[v] = 1;
    }
    int ans = 0;
    if (v == a) {
        ans = 1;
    }
    if (v == b) {
        ans = 2;
    }
    if (v == c) { 
        ans = 3;
    }
    if (v == d) {
        ans = 4;
    }
    for (auto u: edges[v]) {
        int k = dfs(u);
        chkmax(ans, k);
        sz[v] += sz[u];
    }
    return ans;
}


int sza, szb, szc, szd;


int main() {
 	n = readInt();
    a = readInt(), b = readInt(), c = readInt(), d = readInt();
    a--, b--, c--, d--;
    for (int i = 1; i < n; i++) {
        int p = readInt();
       	p--;
        edges[p].push_back(i);
    }
    for (int u: edges[0]) {
        int x = dfs(u);
        sz[0] += sz[u];
        if (x == 0) {
            st.push_back(sz[u]);
        } else if (x == 1) {
            sza = sz[u];
        } else if (x == 2) {
            szb = sz[u];
        } else if (x == 3) {
            szc = sz[u];
        } else if (x == 4) {
            szd = sz[u];
        }
    }
    if (sz[0] % 2 != 0) {
        writeWord("NO\n");
        return 0;
    }
    int sum = 0;
    for (auto i: st) {
        sum += i;
    }
    dp[0] = 1;
    for (auto i: st) {
        for (int j = n - i; j >= 0; j--) {
            dp[j + i] |= dp[j];
        }
    }
    bool good = 0, good1 = 0;
    for (int i = 0; i <= n; i++) {
        if (!dp[i]) {
            continue;
        }
        int x = i + szc - (sum - i + szd);
        int gg = sza + szb - 2;
        if (abs(x) <= gg) {
            good = 1;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (!dp[i]) {
            continue;
        }
        int x = i + sza - (sum - i + szb);
        int gg = szc + szd - 2;
        if (abs(x) <= gg) {
            good1 = 1;
        }
    }
    if (good && good1) {
        writeWord("YES\n");
    } else {
        writeWord("NO\n");
    }
	return 0;
}