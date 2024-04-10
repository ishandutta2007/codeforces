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
const int MAXN = 100001;



struct Line {
    long long k, b;
    Line(long long _k, long long _b) {
        k = _k;
        b = _b;
    }
    Line(){}
    long long value(long long x) {
        return k * x + b;
    }
};


struct ConvexHull {
    vector<Line> st;
    ConvexHull(){}
    bool better(Line a, Line b, Line c) {
        if (c.k == b.k) {
            return c.b > b.b;
        }
        return (c.b - a.b) * (a.k - b.k) <= (b.b - a.b) * (a.k - c.k);
    }
    void addLine(Line l) {
        while (!st.empty() && st.back().k == l.k) {
            if (st.back().b > l.b) {
                return;
            }
            st.pop_back();
        }
        while (sz(st) >= 2 && better(st[sz(st) - 2], st[sz(st) - 1], l)) {
            st.pop_back();
        }
        st.push_back(l);
    }
    long long getMax(long long x) {
        if (st.empty()) {
            return -1e18;
        }
        if (sz(st) == 1) {
            return st[0].value(x);
        }
        int l = 0;
        int r = sz(st) - 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if ((st[mid + 1].b - st[mid].b) >= x * (st[mid].k - st[mid + 1].k)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        long long res = -1e18;
        for (int i = l; i <= r; i++) {
            chkmax(res, st[i].value(x));
        }
        return res;
    }
};



ConvexHull kek[101];
int n, m, p;
int d[MAXN];
long long dist[MAXN];
long long dp[MAXN][101];


int main() {
	n = readInt(), m = readInt(), p = readInt();
    for (int i = 1; i < n; i++) {
        d[i] = readInt();
    }
    for (int i = 1; i < n; i++) {
        dist[i] = dist[i - 1] + d[i];
    }
    vector<int> cats;
    long long add = 0;
    for (int i = 0; i < m; i++) {
        int h = readInt(), t = readInt();
        int time = t - dist[h - 1];
        // if (time < 0) {
        //     add += abs(time);
        //     time = 0;
        // }
        cats.push_back(time);
    }
    sort(all(cats));
    n = sz(cats);
    long long sum = 0;
    long long ans = 1e18;
    for (int i = 0; i < n; i++) {
        sum += cats[i];
        for (int j = 0; j < p; j++) {
            if (i) {
                kek[j].addLine(Line(i, -dp[i - 1][j] - sum + cats[i])) ;
            }
            if (j == 0) {
                dp[i][j] = 1LL * cats[i] * (i + 1) - sum;
            } else {
                dp[i][j] = 1LL * cats[i] * (i + 1) - kek[j - 1].getMax(cats[i]) - sum; 
            }
        }
    }
   // cout << dp[2][0] << endl;
    for (int i = 0; i < p; i++) {
        chkmin(ans, dp[n - 1][i]);
    }
    cout << ans + add << '\n';
	return 0;
}