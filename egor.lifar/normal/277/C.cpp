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
#include <cassert>

 
 
using namespace std;
 
 
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
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
 
 
#define hash hash228 
#define next next228
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int CLOSE = -1;
const int OPEN = 1;
const int MAXN = 100228;


struct event {
    int x, t;
    event(int x, int t): x(x), t(t) {}
    event(){}
};


inline bool operator <(const event &a, const event &b) {
    return a.x < b.x;
}


struct segment {
    int level, x1, x2;
    segment(int level, int x1, int x2): level(level), x1(x1), x2(x2) {}
    segment(){}
};


inline bool operator <(const segment &a, const segment &b) {
    return a.level < b.level;
}


int n, m, k;
vector<segment> xs, ys;
vector<event> evx[MAXN], evy[MAXN];
int rx[MAXN], ry[MAXN], lenx[MAXN], leny[MAXN];


int main() {
    n = readInt(), m = readInt(), k = readInt();
    for (int i = 0; i < k; i++) {
        int x1 = readInt(), y1 = readInt(), x2 = readInt(), y2 = readInt();
        if (x1 > x2) {
            swap(x1, x2);
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        if (x1 == x2) {
            ys.push_back(segment(x1, y1, y2));
        } else {
            xs.push_back(segment(y1, x1, x2));
        }
    }
    sort(all(xs));
    sort(all(ys));
    int kx = 0;
    for (int i = 0; i < sz(xs); i++) {
        if (i == 0 || xs[i].level != xs[i - 1].level) {
            evx[kx].resize(0);
            evx[kx].push_back(event(xs[i].x1, OPEN));
            evx[kx].push_back(event(xs[i].x2, CLOSE));
            ry[kx] = xs[i].level;
            kx++;
        } else {
            evx[kx - 1].push_back(event(xs[i].x1, OPEN));
            evx[kx - 1].push_back(event(xs[i].x2, CLOSE));
        }
    }
    int ky = 0;
    for (int i = 0; i < sz(ys); i++) {
        if (i == 0 || ys[i].level != ys[i - 1].level) {
            evy[ky].resize(0);
            evy[ky].push_back(event(ys[i].x1, OPEN));
            evy[ky].push_back(event(ys[i].x2, CLOSE));
            rx[ky] = ys[i].level;
            ky++;
        } else {
            evy[ky - 1].push_back(event(ys[i].x1, OPEN));
            evy[ky - 1].push_back(event(ys[i].x2, CLOSE));
        }
    }
    int answer = 0;
    if ((m - 1 - kx) % 2 == 1) {
        answer ^= n;
    }
    if ((n - 1 - ky) % 2 == 1) {
        answer ^= m;
    }
    for (int i = 0; i < kx; i++) {
        sort(all(evx[i]));
        int curk = 0;
        int lastx = 0;
        lenx[i] = 0;
        for (int j = 0; j < sz(evx[i]); j++) {
            if (curk == 0) {
                lenx[i] += evx[i][j].x - lastx;
            }
            curk += evx[i][j].t;
            lastx = evx[i][j].x;
        }
        lenx[i] += n - lastx;
        answer ^= lenx[i];
    }
    for (int i = 0; i < ky; i++) {
        sort(all(evy[i]));
        int curk = 0;
        int lastx = 0;
        leny[i] = 0;
        for (int j = 0; j < sz(evy[i]); j++) {
            if (curk == 0) {
                leny[i] += evy[i][j].x - lastx;
            }
            curk += evy[i][j].t;
            lastx = evy[i][j].x;
        }
        leny[i] += m - lastx;
        answer ^= leny[i];
    }
    if (answer == 0){
        writeWord("SECOND\n");
        return 0;
    }
    writeWord("FIRST\n");
    for (int i = 0; i < kx; i++) {
        int need = (answer ^ lenx[i]);
        if (need <= lenx[i]) {
            need = lenx[i] - need;
            int curk = 0;
            int lastx = 0;
            int curlen = 0;
            for (int j = 0; j < sz(evx[i]); j++) {
                if (curk == 0) {
                    curlen += evx[i][j].x - lastx;
                }
                if (curlen >= need) {
                    writeInt(0, ' ');
                    writeInt(ry[i], ' ');
                    writeInt(evx[i][j].x - (curlen - need), ' ');
                    writeInt(ry[i], '\n');
                    return 0;
                }
                curk += evx[i][j].t;
                lastx = evx[i][j].x;
            }
            curlen += n - lastx;
            writeInt(0, ' ');
            writeInt(ry[i], ' ');
            writeInt(n - (curlen - need), ' ');
            writeInt(ry[i], '\n');
            return 0;
        }
    }
    for (int i = 0; i < ky; i++) {
        int need = (answer ^ leny[i]);
        if (need <= leny[i]) {
            need = leny[i] - need;
            int curk = 0;
            int lastx = 0;
            int curlen = 0;
            for (int j = 0; j < sz(evy[i]); j++) {
                if (curk == 0) {
                    curlen += evy[i][j].x - lastx;
                }
                if (curlen >= need) {
                    writeInt(rx[i], ' ');
                    writeInt(0, ' ');
                    writeInt(rx[i], ' ');
                    writeInt(evy[i][j].x - (curlen - need), '\n');
                    return 0;
                }
                curk += evy[i][j].t;
                lastx = evy[i][j].x;
            }
            curlen += m - lastx;
            writeInt(rx[i], ' ');
            writeInt(0, ' ');
            writeInt(rx[i], ' ');
            writeInt(m - (curlen - need), '\n');
            return 0;
        }
    }
    int emptyx = -1;
    if (n > 1 && ky == 0) {
        emptyx = 1;
    }
    if (ky > 0 && rx[0] != 1) {
        emptyx = 1;
    }
    for (int i = 0; i < ky; i++) {
        if (rx[i] + 1 != rx[i + 1] && rx[i] + 1 != n) {
            emptyx = rx[i] + 1;
        }
    }
    int need = (answer ^ m);
    if (need <= m && emptyx != -1) {
        writeInt(emptyx, ' ');
        writeInt(0, ' ');
        writeInt(emptyx, ' ');
        writeInt(m - need, '\n');
        return 0;
    }
    int emptyy = -1;
    if (m > 1 && kx == 0) {
        emptyy = 1;
    }
    if (kx > 0 && ry[0] != 1) {
        emptyy = 1;
    }
    for (int i = 0; i < kx; i++) {
        if (ry[i] + 1 != ry[i + 1] && ry[i] + 1 != m) {
            emptyy = ry[i] + 1;
        }
    }
    need = (answer ^ n);
    if (need <= n && emptyy != -1) {
        writeInt(0, ' ');
        writeInt(emptyy, ' ');
        writeInt(n - need, ' ');
        writeInt(emptyy, '\n');
        return 0;
    }
    return 0;
}