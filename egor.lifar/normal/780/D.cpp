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
const int MAXN = 1001;


int n;
string a[MAXN], b[MAXN];
map<string, vector<int> > name;
string ans[MAXN];
int tt[MAXN];
map<string, bool> used;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        string t;
        for (int j = 0; j < 3; j++) {
            t += a[i][j];
        }
        name[t].push_back(i);
    }
    for (auto x: name) {
        vector<int> v = x.second;
        if (sz(v) > 1) {
            for (auto i: v) {
                ans[i] += a[i][0];
                ans[i] += a[i][1];
                ans[i] += b[i][0];
                if (used[ans[i]]) {
                    cout << "NO\n";
                    return 0;
                }
                used[ans[i]] = 1;
                tt[i] = 2;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (!tt[i]) {
                string t;
                for (int j = 0; j < 3; j++) {
                    t += a[i][j];
                }
                string t1;
                t1 += a[i][0];
                t1 += a[i][1];
                t1 += b[i][0];
                if (used[t]) {
                    if (used[t1]) {
                        cout << "NO\n";
                        return 0;
                    }
                    ans[i] = t1;
                    tt[i] = 2;
                    used[t1] = 1;
                } else {
                    if (used[t1]) {
                        ans[i] = t;
                        tt[i] = 1;
                        used[t] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!tt[i]) {
            string t;
            for (int j = 0; j < 3; j++) {
                t += a[i][j];
            }
            ans[i] = t;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}