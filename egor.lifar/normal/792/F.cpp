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
#define rank rank228
const int MOD = 1000000;


set<pair<long long, long long> > ss;
int q;
long long m;


int could(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    b.first -= a.first;
    b.second -= a.second;
    c.first -= a.first;
    c.second -= a.second;
    return ((long double)b.first * (long double)c.second - (long double)b.second * (long double)c.first) <= 0;
}


int main() {
    scanf("%d %lld", &q, &m);
    int ij = 0;
    ss.insert(make_pair(0, 0));
    for (int i = 0; i < q; i++) {
        int k = readInt(), t = readInt(), h = readInt();
        if (k == 1) {
            long long x = (t + ij) % MOD + 1;
            long y = (h + ij) % MOD + 1;
            auto it = ss.lower_bound(make_pair(x, 0));
            if (it != ss.end() && it->second <= y) {
                continue;
            }
            auto it2 = prev(it);
            if (it != ss.end() && could(*it2, make_pair(x, y), *it)) {
                continue;
            }
            it = ss.insert(make_pair(x, y)).first;
            while (next(it) != ss.end() && next(it)->first == x) {
                ss.erase(next(it));
            }
            while (prev(it) != ss.begin() && could(*prev(prev(it)), *prev(it), *it)) {
                ss.erase(prev(it));
            }
        } else {
            long long a = (h + ij) % MOD + 1;
            long long b = (t + ij) % MOD + 1;
            auto it = ss.lower_bound(make_pair((a + b - 1) / b, 0));
            bool good = 0;
            if (it != ss.end()) {
                if (it->second * b <= m) {
                    good = 1;
                } else {
                    auto it2 = prev(it);
                    if (could(make_pair(it2->first * b, it2->second * b), make_pair(a, m), make_pair(it->first * b, it->second * b))) {
                        good = 1;
                    }
                }
            }
            if (good) {
                writeWord("YES\n");
                ij = i + 1;
            } else {
                writeWord("NO\n");
            }
        }
    }
    return 0;
}