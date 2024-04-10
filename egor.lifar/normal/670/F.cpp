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
#define y1 y1228


string a, b, ans, s;
int n, m, p, cnt[10];


int len(int x){
    int len = 0;
    while (x) {
        x /= 10;
        len++;
    }
    return len;
}


inline void solve1() {
    p = len(n);
    if (len(n - p) != p) {
        p--;
    }
    for (int i = n - p; i; i /= 10) {
        cnt[i % 10]--;
    }
}


inline void solve2() {
    int i;
    for (i = 0; i < 10; i++) {
        s.append(cnt[i], i + '0');
    }
    if (b[0] != '0') {
        chkmin(ans, b + s);
    }
    for (i = 0; s[i] == '0' && i < n - p - m; i++);
    if (i == n - p - m) {
        return;
    }
    swap(s[0], s[i]);
    for (i = 1; s[i] < b[0] && i < n - p - m; i++);
    string t = s;
    chkmin(ans, t.insert(i, b));
    for (;s[i] == b[0] && i < n - p - m; i++);
    chkmin(ans, s.insert(i, b));
}


int main() {
    cin >> a >> b;
    n = sz(a);
    m = sz(b);
    if (a == "01" || a == "10") { 
        puts("0");
        return 0;
    } 
    for (int i = 0; i < n; i++) {
        cnt[a[i] - '0']++;
    }
    for (int i = 0; i < m; i++) {
        cnt[b[i] - '0']--;
    }
    ans = "A";
    solve1();
    solve2();
    cout << ans << '\n';
    return 0;
}