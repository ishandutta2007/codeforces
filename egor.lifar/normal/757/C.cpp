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
  

#define rank rank228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 1000001;
const int Mod = 1000000007;

int n, m;
set<int> s[MAXN];
vector<int> gg[MAXN];
map<vector<int>, int> cnt;


bool comp(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.second, a.first) < make_pair(b.second, b.first);
}


int main(){
    n = readInt(), m = readInt();
    int t = 0;
    for (int i = 0; i < n; i++) {
        int k = readInt();
        vector<int> v;
        for (int i = 0; i < k; i++) {
            int a = readInt();
            a--;
            v.push_back(a);
        }
        sort(all(v));
        int cnt = 0;
        vector<pair<int, int> > g;
        for (int i = 0; i < k; i++) {
            cnt++;
            if (i == k - 1 || v[i + 1] != v[i]) {
                g.push_back(make_pair(v[i], cnt));
                cnt = 0;
            }
        }
        sort(all(g), comp);
        k = sz(g);
        vector<int> cur;
        for (int i = 0; i < k; i++) {
            cur.push_back(g[i].first);
            if (i == k - 1 || g[i + 1].second != g[i].second) {
                t++;
                for (auto x: cur) {
                    gg[x].push_back(t);
                }
                cur.clear();
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < m; i++) {
        sort(all(gg[i]));
        cnt[gg[i]]++;
    }
    for (auto g: cnt) {
        for (int i = 2; i <= g.second; i++) {
            ans = (1LL * ans * i) % Mod;
        }
    }
    writeInt(ans, '\n');
    return 0;
}