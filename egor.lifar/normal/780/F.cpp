/*
  !










*/
#include <bits/stdc++.h>
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


int n, m;
bool dp[500][500][62][2];
bool v[500][500];
bool v1[500][500];
bitset<500> s[500], s1[500], s2[500], s3[500];
bool can[500], can1[501];


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        if (!t) {
            v[a][b] = 1;
        } else {
            v1[a][b] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0][0] = v[i][j];
            dp[i][j][0][1] = v1[i][j];
        }
    }
    for (int k = 1; k <= 61; k++) {
        for (int i = 0; i < n; i++) {
            s[i] = 0, s1[i] = 0, s2[i] = 0, s3[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j][k - 1][0]) {
                    s[i].set(j, 1);
                }
                if (dp[i][j][k - 1][1]) {
                    s1[j].set(i, 1);
                }
                if (dp[i][j][k - 1][1]) {
                    s2[i].set(j, 1);
                }
                if (dp[i][j][k - 1][0]) {
                    s3[j].set(i, 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((s[i] & s1[j]).count()) {
                    dp[i][j][k][0] = 1;
                }
                if ((s2[i] & s3[j]).count()) {
                    dp[i][j][k][1] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        can[i] = 1;
    }
    long long ans = 0;
    int g = 0;
    for (int k = 61; k >= 0; k--) {
        bool t = 0;
        for (int i = 0; i < n; i++) {
            can1[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (!can[i]) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (dp[i][j][k][g]) {
                    can1[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (can1[i]) {
                t = 1;
                break;
            }
        }
        if (t) {
            ans += (1LL << k);
            for (int i = 0; i < n; i++) {
                can[i] = can1[i];
            }
            g ^= 1;
        }
    }
    if (ans > (long long)1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}