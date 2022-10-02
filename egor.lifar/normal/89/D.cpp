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
  

#define prev prev228
#define left left228
#define right right228  
const double eps = 1e-10;
#define equal(a, b) (abs(b) < eps ? abs(a - b) < eps: abs(a / b - 1.0) < eps)
const double INF = 9999999999.0;


double ax, ay, az, vx, vy, vz, R;


double getAns(double p1x, double p1y, double p1z, double p2x, double p2y, double p2z, double vx, double vy, double vz, double res) {
    res *= res;
    double A = p1x - p2x;
    double B = p1y - p2y;
    double C = p1z - p2z;
    double a = vx * vx + vy * vy + vz * vz;
    double b = -2.0 * (A * vx + B * vy + C * vz);
    double c = A * A + B * B + C * C - res;
    double d = b * b - 4.0 * a * c;
    if (!equal(0.0, d) && d < 0.0) {
        return -1.0;
    }
    if (equal(0.0, d)) {
        d = 0.0;
    }
    double ret = (-b - sqrt(d)) / (2.0 * a);
    if (equal(0.0, ret)) {
        ret = 0.0;
    }
    if (ret < 0.0) {
        ret = (-b + sqrt(d)) / (2.0 * a);
    }
    return ret;
}


int n;


int main() {
    cin >> ax >> ay >> az >> vx >> vy >> vz >> R >> n;
    double ans = INF;
    for (int i = 0; i < n; i++) {
        double ox, oy, oz, r;
        int m;
        cin >> ox >> oy >> oz >> r >> m;
        double nans = getAns(ox, oy, oz, ax, ay, az, vx, vy, vz, R + r);
        if (nans >= 0.0 && nans < ans) {
            ans = nans;
        }
        for (int j = 0; j < m; j++) {
            double px, py, pz;
            cin >> px >> py >> pz;
            nans = getAns(px + ox, py + oy, pz + oz, ax, ay, az, vx, vy, vz, R);
            if (equal(0.0, nans)) {
                nans = 0.0;
            }
            if (nans >= 0.0 && nans < ans) {
                ans = nans;
            }
        }
    }
    if (ans == INF) {
        ans = -1.0;
    }
    printf("%.10lf\n", ans);        
    return 0;
}