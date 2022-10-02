/*
  !










*/
#pragma GCC optimize "-O3"
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
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const string FILENAME = "input";
typedef pair <int, int> point;


int f, T, t0, a1, t1, p1, a2, t2, p2, R;


inline bool func(int leftt, int leftb, int mid) {
    int ft = 0;
    if (mid == R) {
        ft += (mid - 1) * a2;
        int keks = (leftt - (mid - 1) * a2 * t2) / t2;
        ft += keks;
    } else {
        ft += (leftt - mid * a2 * t2) / t0;
        ft += mid * a2;
    }
    return ft >= leftb;
} 



inline long long keks(int cnt) {
    int ks = cnt * a1;
    if (1LL * ks * t1 >= T) {
        long long g = 1LL * (cnt - 1) * a1 + (T - 1LL * (cnt - 1) * t1 * a1) / t1;
        if (g >= f) {
            return 1LL * cnt * p1;
        }
        return 1e18;
    }
    if (ks >= f) {
        return 1LL * cnt * p1;
    }
    int leftt = T - ks * t1;
    int leftb = f - ks;
    if (t2 < t0) {

        int r = (1LL * leftt) / (1LL * a2 * t2) + 1;
        R = r;
        long double diff = 1LL * leftb * t0 - leftt;
        long long sf = t0 - t2;
        long double keks = (diff * t2) / sf;
        keks /= a2;
        keks /= t2;
        long long keks1 = (long long)ceil(keks - 1e-9);
        long long ans = 1e18;
        for (int i = keks1 - 5; i <= keks1 + 5; i++) {
            int l = i;
            if (l >= 0 && l <= r) {
                if (func(leftt, leftb, l)) {
                    chkmin(ans, 1LL * cnt * p1 + 1LL * l * p2);
                }
            }
        }
        int l = r;
        if (func(leftt, leftb, l)) {
            chkmin(ans, 1LL * cnt * p1 + 1LL * l * p2);
        }
        l = 0;
        if (func(leftt, leftb, l)) {
            chkmin(ans, 1LL * cnt * p1 + 1LL * l * p2);
        }
        return ans;
    } else {
        if (func(leftt, leftb, 0)) {
            return 1LL * cnt * p1;
        }
    }
    return 1e18;
}


int main() {
    ios::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
   // read(FILENAME);
    cin >> f >> T >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;
    long long ans = 1e18;
    if (1LL * t0 * f <= T) {
        ans = 0;
        cout << ans << '\n';
        return 0;
    }
    int ll = 0;
    int rr = 1LL * T / (1LL * t1 * a1) + 1;
    for (int g = ll; g <= rr; g++) {
        chkmin(ans, keks(g));
    }
    swap(a1, a2);
    swap(t1, t2);
    swap(p1, p2);
    ll = 0;
    rr = 1LL * T / (1LL * t1 * a1) + 1;
    for (int g = ll; g <= rr; g++) {
        chkmin(ans, keks(g));
    }
    if (ans > 9e17) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}