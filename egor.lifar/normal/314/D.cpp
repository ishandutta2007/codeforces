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
 
struct flusher {
    ~flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define left _left
#define right _right
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 100228;
const long long inf = 10000000000LL;


struct point{
    long long x, y;
};


int pos[MAXN];
long long minPref[MAXN], maxPref[MAXN], minSuff[MAXN], maxSuff[MAXN];
pair <long long, int> lx[MAXN], rx[MAXN];
long long x[2 * MAXN];
point p[MAXN];


int main(){
    int n = readInt();
    for(int i = 0; i < n; i++){
        long long x = readInt(), y = readInt();
        x *= 2LL;
        y *= 2LL;
        p[i].x = x + y;
        p[i].y = x - y;
    }
    for(int i = 0; i < n; i++){
        lx[i] = make_pair(p[i].x, i);
        rx[i] = make_pair(p[i].x, i);
        x[(i << 1)] = p[i].x;
        x[(i << 1) + 1] = p[i].x;
    }
    sort(lx, lx + n);
    sort(rx, rx + n);
    sort(x, x + 2 * n);
    int k = unique(x, x + 2 * n) - x;
    long long ans = inf, l = 0, r = inf;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        bool can = false;
        for (int i = 0; i < n; i++) {
            minPref[i] = min((i > 0 ? minPref[i - 1]: inf), p[lx[i].second].y + mid);
            maxPref[i] = max((i > 0 ? maxPref[i - 1]: -inf), p[lx[i].second].y - mid);
        }
        for (int i = n - 1; i >= 0; i--) {
            minSuff[i] = min((i + 1 < n ? minSuff[i + 1]: inf), p[rx[i].second].y + mid);
            maxSuff[i] = max((i + 1 < n ? maxSuff[i + 1]: -inf), p[rx[i].second].y - mid);
        }
        int i = 0, j = 0, ukl = -1, ukr = 0;
        while (i < k && j < k) {
            if (x[i] - mid < x[j] + mid) {
                long long cx = x[i++] - mid;
                while (ukl + 1 < n && lx[ukl + 1].first + mid < cx) {
                    ukl++;
                }
                while (ukr < n && rx[ukr].first - mid <= cx) {
                    ukr++;
                }
                long long left = -inf, right = inf;
                if (ukl >= 0) {
                    left = max(left, maxPref[ukl]);
                    right = min(right, minPref[ukl]);
                }
                if (ukr < n) {
                    left = max(left, maxSuff[ukr]);
                    right = min(right, minSuff[ukr]);
                }
                if (left <= right) {
                    can = true;
                    break;
                }
            } else {
                long long cx = x[j++] + mid;
                while (ukl + 1 < n && lx[ukl + 1].first + mid < cx) {
                    ukl++;
                }
                while (ukr < n && rx[ukr].first - mid <= cx) {
                    ukr++;
                }
                long long left = -inf, right = inf;
                if (ukl >= 0) {
                    left = max(left, maxPref[ukl]);
                    right = min(right, minPref[ukl]);
                }
                if (ukr < n) {
                    left = max(left, maxSuff[ukr]);
                    right = min(right, minSuff[ukr]);
                }
                if (left <= right) {
                    can = true;
                    break;
                }
            }
        }
        while (i < k && !can) {
            long long cx = x[i++] - mid;
            while (ukl + 1 < n && lx[ukl + 1].first + mid < cx) {
                ukl++;
            }
            while (ukr < n && rx[ukr].first - mid <= cx) {
                ukr++;
            }
            long long left = -inf, right = inf;
            if (ukl >= 0) {
                left = max(left, maxPref[ukl]);
                right = min(right, minPref[ukl]);
            }
            if (ukr < n) {
                left = max(left, maxSuff[ukr]);
                right = min(right, minSuff[ukr]);
            }
            if (left <= right) {
                can = true;
                break;
            }
        }
        while (j < k && !can) {
            long long cx = x[j++] - mid;
            while (ukl + 1 < n && lx[ukl + 1].first + mid < cx) {
                ukl++;
            }
            while (ukr < n && rx[ukr].first - mid <= cx) { 
                ukr++;
            }
            long long left = -inf, right = inf;
            if (ukl >= 0) {
                left = max(left, maxPref[ukl]);
                right = min(right, minPref[ukl]);
            }
            if (ukr < n) {
                left = max(left, maxSuff[ukr]);
                right = min(right, minSuff[ukr]);
            }
            if (left <= right) {
                can = true;
                break;
            }
        }
        if (can) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld.%d\n", ans / 2, (ans % 2 ? 5 : 0));
    return 0;
}