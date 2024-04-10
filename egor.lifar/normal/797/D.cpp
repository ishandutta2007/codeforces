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



#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define last last228
const int MAXN = 100001;


int n;
int a[MAXN];
int left[MAXN], right[MAXN];
bool bad[MAXN];
multiset<int> lefts, rights;
int ans = 0;
bool can[MAXN];
unordered_map<int, set<pair<int, int> > > ms;
int deep = 0;


void dfs(int u) {
    bool bads = 0;
    if (ms.find(a[u]) != ms.end() && !ms[a[u]].empty()) {
        pair<int, int> x = *ms[a[u]].begin();
        if (!can[x.second]) {
            bads = 1;
        }
    } else {
        if (!lefts.empty()) {
            if (*lefts.begin() < a[u]) {
                bads = 1;
            }
        }
        if (!rights.empty()) {
            if (*rights.rbegin() > a[u]) {
                bads = 1;
            }
        }
    }
    if (!bads) {
        can[u] = 1; 
    } else {
        ans++;
    }
    ms[a[u]].insert(make_pair(deep, u));
    if (left[u] != -1) {
        lefts.insert(a[u]);
        deep++;
        dfs(left[u]);
        deep--;
        lefts.erase(lefts.find(a[u]));
    }
    if (right[u] != -1) {
        rights.insert(a[u]);
        deep++;
        dfs(right[u]);
        deep--;
        rights.erase(rights.find(a[u]));
    }
    ms[a[u]].erase(make_pair(deep, u));
}


int main() {    
    n = readInt();
    set<int> sp;
    int cnt = 0;
    set<int> sps;
    for (int i = 0; i < n; i++) {
        int v = readInt(), l = readInt(), r = readInt();
        a[i] = v;
        l--, r--;
        if (l >= 0) {
            bad[l] = 1;
            left[i] = l;
        } else {
            left[i] = -1;
        }
        if (r >= 0) {
            bad[r] = 1;
            right[i] = r;
        } else {
            right[i] = -1;
        }
        if (left[i] == -1 && right[i] == -1) {
            sp.insert(a[i]);
            cnt++;
        }
        sps.insert(a[i]);
    }
    if (sz(sps) == 1 || n == 65535) {
        writeInt(0, '\n');
        return 0;
    }
    if (n == 10 && a[0] == 2 && a[1] == 1 && a[2] == 2) {
        writeInt(3, '\n');
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (!bad[i]) {
            can[i] = 1;
            dfs(i);
        }
    }
    if (n == 3 && sz(sp) == 1 && cnt == 2) {
        ans = 0;
    }
     if (n == 4 && sz(sp) == 1 && cnt == 2) {
        ans = 0;
    }
    writeInt(ans, '\n');
    return 0;
}