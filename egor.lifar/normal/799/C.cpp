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


int n, c, d;

 
int main() {
    n = readInt(), c = readInt(), d = readInt();
    vector<pair<int, int> > v, v1;
    for (int i = 0; i < n; i++) {
        int b = readInt(), p = readInt();
        char t = readChar();
        if (t == 'C') {
            v.push_back(make_pair(p, b));
        } else {
            v1.push_back(make_pair(p, b));
        }
    }
    sort(all(v));
    sort(all(v1));
    int t = 0;
    for (int i = 0; i < sz(v); i++) {
        if (v[i].first <= c) {
            t = max(t, v[i].second);
        }
    }
    int t1 = 0;
    for (int i = 0; i < sz(v1); i++) {
        if (v1[i].first <= d) {
            t1 = max(t1, v1[i].second);
        }
    }
    multiset<int> s;
    for (auto x: v) {
        s.insert(x.second);
    }
    int ans = (t && t1 ? t + t1: 0);
    int uk = sz(v) - 1;
    for (int i = 0; i < sz(v); i++) {
        if (v[i].first > c) {
            break;
        }
        while (uk >= 0 && v[uk].first > c - v[i].first) {
            s.erase(s.find(v[uk].second));
            uk--;
        }
        if (uk >= i) {
            s.erase(s.find(v[i].second));
        }
        if (!s.empty()) {
            ans = max(ans, v[i].second + *s.rbegin());
        }
        if (uk >= i) {
            s.insert(v[i].second);
        }
    }
    multiset<int> s1;
    for (auto x: v1) {
        s1.insert(x.second);
    }
    uk = sz(v1) - 1;
    for (int i = 0; i < sz(v1); i++) {
        if (v1[i].first > d) {
            break;
        }
        while (uk >= 0 && v1[uk].first > d - v1[i].first) {
            s1.erase(s1.find(v1[uk].second));
            uk--;
        }
        if (uk >= i) {
            s1.erase(s1.find(v1[i].second));
        }
        if (!s1.empty()) {
            ans = max(ans, v1[i].second + *s1.rbegin());
        }
        if (uk >= i) {
            s1.insert(v1[i].second);
        }
    }
    writeInt(ans, '\n');
    return 0;
}