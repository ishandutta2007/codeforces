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
const int MAXN = 1000;
const int INF = (int)1e9;

int n;
int ans[MAXN];
bool good[MAXN];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ans[i] = INF;
    }
    vector<pair<int, int> > cur;
    cur.push_back(make_pair(0, n - 1));
    bool t = 1;
    while (t) {
        vector<int> pos;
        t = 0;
        memset(good, 0, sizeof(good));
        vector<pair<int, int> > cur1;
        for (int i = 0; i < sz(cur); i++) {
            int l = cur[i].first;
            int r = cur[i].second;
            if (l == r) {
                continue;
            }
            int len = r - l + 1;
            cur1.push_back(make_pair(l, l + len / 2 - 1));
            for (int j = l; j < l + len / 2; j++) {
                good[j] = 1;
            }
            for (int j = l + len / 2; j <= r; j++) {
                pos.push_back(j);
            }
        }
        if (sz(pos)) {
            t = 1;
            cout << sz(pos) << endl;
            for (auto x: pos) {
                cout << x + 1 << ' ';
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                int a;
                cin >> a;
                if (good[i]) {
                    chkmin(ans[i], a);
                }
            }
        }
        pos.clear();
        memset(good, 0, sizeof(good));
        for (int i = 0; i < sz(cur); i++) {
            int l = cur[i].first;
            int r = cur[i].second;
            if (l == r) {
                continue;
            }
            int len = r - l + 1;
            cur1.push_back(make_pair(l + len / 2, r));
            for (int j = l; j < l + len / 2; j++) {
                pos.push_back(j);
            }
            for (int j = l + len / 2; j <= r; j++) {
                good[j] = 1;
            }
        }
        if (sz(pos)) {
            t = 1;
            cout << sz(pos) << endl;
            for (auto x: pos) {
                cout << x + 1 << ' ';
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                int a;
                cin >> a;
                if (good[i]) {
                    chkmin(ans[i], a);
                }
            }
        }
        cur = cur1;
    }
    cout << -1 << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;   
}