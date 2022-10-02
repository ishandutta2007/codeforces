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
#define get get228
#define y1 y1228    
const int MAXN = 101;


int n;
int a[MAXN];
map<int, vector<int> > g;
map<vector<int>, int> f;
int used[MAXN * MAXN * MAXN];
int uk = 0;


int getgr(vector<int> t) {
    if (t.empty()) {
        return 0;
    }
    if (f.find(t) != f.end()) {
        return f[t];
    }
    int fst = 0;
    vector<int> z;
    for (int way = 1; way <= t.back(); way++) {
        vector<int> t1;
        for (auto x: t) {
            if (x > way) {
                t1.push_back(x - way);
            } else {
                if (x < way) {
                    t1.push_back(x);
                }
            }
        }
        sort(all(t1));
        t1.resize(distance(t1.begin(), unique(all(t1))));
        z.push_back(getgr(t1));
    }
    uk++;
    for (auto x: z) {
        used[x] = uk;
    }
    while (used[fst] == uk) {
        fst++;
    }
    f[t] = fst;
    return fst;
}


int main() {
    n = readInt();
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            continue;
        }
        vector<pair<int, int> > v;
        int s = 2;
        while (s * s <= a[i]) {
            if (a[i] % s == 0) {
                int cnt = 0;
                while (a[i] % s == 0) {
                    a[i] /= s;
                    cnt++;
                }
                v.push_back(make_pair(s, cnt));
            }
            s++;
        }
        if (a[i] != 1) {
            v.push_back(make_pair(a[i], 1));
        }
        for (auto x: v) {
            g[x.first].push_back(x.second);
        }
    }
    for (auto z: g) {
        vector<int> t = z.second;
        sort(all(t));
        t.resize(distance(t.begin(), unique(all(t))));
        ans ^= getgr(t);
    }
    if (!ans) {
        writeWord("Arpa\n");
    } else {
        writeWord("Mojtaba\n");
    }
    return 0;
}