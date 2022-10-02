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
#define last last228
const int MAXN = 5001;
const long long INF = 72340172838076673LL;


struct hole
{
    int p, c;
    hole(){}
    hole(int _p, int _c) {
        p = _p;
        c = _c;
    }
};


bool operator <(const hole &a, const hole &b) {
    return a.p < b.p;
}   


int n, m;
int x[MAXN];
hole a[MAXN];
long long dp[MAXN][MAXN];
int next[MAXN];
long long prevdp[MAXN];


int main() {    
    n = readInt(), m = readInt();
    for (int i = 0; i < n; i++) {
        x[i] = readInt();
    }
    sort(x, x + n);
    for (int i = 0; i < m; i++) {
        a[i].p = readInt(), a[i].c = readInt();
    }
    sort(a, a + m);
    for (int i = 0; i < m; i++) {
        memset(dp[i], 1, sizeof(dp[i]));
        if (i == 0) {
            for (int j = 0; j < a[0].c; j++) {
                dp[i][j] = abs(x[j] - a[0].p) + (j ? dp[i][j - 1]: 0LL);
            }
            continue;
        }
        long long sums = 0;
        for (int j = 0; j < n; j++) {
            sums += abs(x[j] - a[i].p);
        }
        vector<int> st;
        long long sum = 0;
        int uk = 0;
        for (int j = 0; j < n; j++) {
            if (j < a[i].c) {
                sum += abs(x[j] - a[i].p);
                dp[i][j] = sum;
            }
            sums -= abs(x[j] - a[i].p);
            if (j) {
                if (uk < j - a[i].c) {
                    uk = j - a[i].c;
                }
                while (next[uk] < j) {
                    uk = next[uk];
                }
                chkmin(dp[i][j], prevdp[uk] - sums);
            }
            prevdp[j] = dp[i - 1][j] + sums;
            next[j] = n;
            while (!st.empty() && prevdp[st.back()] >= prevdp[j]) {
                next[st.back()] = j;
                st.pop_back();
            }
            st.push_back(j);
            chkmin(dp[i][j], dp[i - 1][j]);
        }
    }
    long long ans = INF;
    for (int i = 0; i < m; i++) {
        chkmin(ans, dp[i][n - 1]);
    }
    if (ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}