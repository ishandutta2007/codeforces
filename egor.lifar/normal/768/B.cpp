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
const int MAXN = 100001;
const int INF = 1000000001;


struct point
{
    int x, y;
    point(){}
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};


bool operator ==(point a, point b) {
    return (a.x == b.x) && (a.y == b.y);
}


bool operator<(point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}


unordered_map<long long, long long> cnt;


void getcnt(long long n) {
    if (cnt.find(n) != cnt.end()) {
        return;
    }
    if (n <= 1LL) {
        cnt[n] = 1;
    } else {
        getcnt(n >> 1LL);
        cnt[n] = 2LL * cnt[n >> 1LL] + 1LL;
    }
}


long long getans(long long n, long long l, long long r) {
    if (n <= 1LL) {
        if (n == 1LL) {
            return 1LL;
        }
        return 0LL;
    }
    long long ans = 0;
    if (cnt[n >> 1LL] >= l) {
        ans += getans(n >> 1LL, l, min(cnt[n >> 1LL], r));
    }
    if (cnt[n >> 1LL] + 1LL >= l && cnt[n >> 1LL] + 1LL <= r) {
        if (n & 1) {
            ans++;
        }
    }
    if (cnt[n >> 1LL] + 2LL <= r) {
        ans += getans(n >> 1LL, max(l, cnt[n >> 1LL] + 2LL) - cnt[n >> 1LL] - 1LL, r - cnt[n >> 1LL] - 1LL);
    }
    return ans;
}

 
int main() {
    long long n, l, r;
    cin >> n >> l >> r;
    getcnt(n);
    cout << getans(n, l, r) << endl;
    return 0;
}