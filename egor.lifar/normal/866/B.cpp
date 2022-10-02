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
#define y1 y1228   
const int MAXN = 200001;


int n, s;
int cnt[MAXN], a[MAXN], b[MAXN];
vector<pair<int, int> > g[2];
long long cntp, sl;


inline long long get(long long x) {
    long long y = sl - x;
    long long add = 0;
    for (int i = 0; i < sz(g[0]); i++) {
        if (g[0][i].second <= x) {
            x -= g[0][i].second;
            add += 1LL * g[0][i].first * g[0][i].second;
        } else {
            add += 1LL * g[0][i].first * x;
            break;
        }
    }
    for (int i = 0; i < sz(g[1]); i++) {
        if (g[1][i].second <= y) {
            y -= g[1][i].second;
            add += 1LL * g[1][i].first * g[1][i].second;
        } else {
            add += 1LL * g[1][i].first * y;
            break;
        }
    }
    return add;
}


int main() {
    n = readInt(), s = readInt();
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cnt[i] = readInt(), a[i] = readInt(), b[i] = readInt();
        sum += cnt[i];
        ans += 1LL * cnt[i] * min(a[i], b[i]);
    }
    cntp = (sum + s - 1) / s;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i] > b[i]) {
                g[0].push_back(make_pair(a[i] - b[i], cnt[i]));
            } else {
                g[1].push_back(make_pair(b[i] - a[i], cnt[i]));
            }
        }
    }
    sl = cntp * s;
    for (int it = 0; it < 2; it++) {
        sort(all(g[it]));
        reverse(all(g[it]));
    }
    long long l = 0;
    long long r = cntp;
    while (l + 2 < r) {
        long long mid = l + (r - l) / 3;
        long long mid1 = l + (r - l) / 3 * 2;
        if (get(mid * s) < get(mid1 * s)) {
            l = mid; 
        } else {
            r = mid1;
        }
    }
   // cout << l << ' ' << r << endl;
    long long add = 0;
    for (long long i = l; i <= r; i++) {
        chkmax(add, get(i * s));
    }
    cout << add + ans << '\n';
    return 0;
}