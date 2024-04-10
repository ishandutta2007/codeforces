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
 
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
int n;
int t[16];
int c[16][2];
int dp[65537][257][2];
vector<int> pos;


int main() {
    cin >> n;
    int sumb = 0, sumc = 0;
    for (int i = 0; i < n; i++) {
        char s; 
        cin >> s;
        if (s == 'B') {
            t[i] = 1;
        } else {
            t[i] = 0;
        }
        cin >> c[i][0] >> c[i][1];
        if (c[i][0] > n) {
            sumb += c[i][0] - n;
            c[i][0] = n;
        }
        if (c[i][1] > n) {
            sumc += c[i][1] - n;
            c[i][1] = n;
        }
    }
    int maxP = n * n;
    int maxMask = (1 << n);
    for (int i = 0; i < maxMask; i++) {
        for (int j = 0; j <= maxP; j++) {
            dp[i][j][0] = dp[i][j][1] = maxP;
        }
    }
    if (sumc >= sumb) {
        dp[0][min(maxP, sumc - sumb)][0] = 0;
    } else {
        dp[0][min(maxP, sumb - sumc)][1] = 0;
    }
    for (int i = 0; i < maxMask - 1; i++) {
        int cntb = 0, cntc = 0;
        int i1 = i;
        pos.clear();
        for (int j = 0; j < n; j++) {
            if (i1 & 1) {
                if (!t[j]) {
                    cntb++;
                } else {
                    cntc++;
                }
            } else {
                pos.push_back(j);
            }
            i1 >>= 1;
        }
        for (auto j: pos) {
            int costb = max(c[j][0] - cntb, 0), costc = max(c[j][1] - cntc, 0);
            int newMask = i ^ (1 << j);
            for (int p = 0; p < 2; p++) {
                for (int k = 0; k <= maxP; k++) {
                    int prevb = k, prevc = 0;
                    int newCost = max(0, max(costb - prevb, costc - prevc));
                    prevb += newCost - costb;
                    prevc += newCost - costc;
                    if (dp[i][k][p] + newCost > maxP) {
                        continue;
                    }
                    if (prevb == 0) {
                        chkmin(dp[newMask][min(maxP, prevc)][p ^ 1], dp[i][k][p] + newCost);
                    } else {
                        chkmin(dp[newMask][min(maxP, prevb)][p], dp[i][k][p] + newCost);
                    }
                }
                swap(costb, costc);
            }
        }
    }
    int ans = maxP;
    for (int p = 0; p < 2; p++) {
        for (int k = 0; k <= maxP; k++) {
            chkmin(ans, dp[maxMask - 1][k][p]);
        }
    }
    cout << max(sumb, sumc) + ans + n << endl;
    return 0;
}