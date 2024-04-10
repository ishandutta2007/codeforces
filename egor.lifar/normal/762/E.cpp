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
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()


int n, k;
int ss[10001];
vector<pair<int, int> > z[10001];
vector<vector<int> > d[10001];


int rmq(int ind, int v, int vl, int vr, int l, int r, int a, int b) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        if (d[ind][v].empty()) {
            return 0;
        }
        return upper_bound(all(d[ind][v]), b) - lower_bound(all(d[ind][v]), a);
    }
    int vm = (vl + vr) >> 1;
    return rmq(ind, v * 2, vl, vm, l, r, a, b) + rmq(ind, v * 2 + 1, vm + 1, vr, l, r, a, b);
}

int main() {    
    n = readInt(), k = readInt();
    for (int i = 0; i < n; i++) {
        int x = readInt(), r = readInt(), f = readInt();
        z[f].push_back(make_pair(x + r, x));
    }
    for (int ind = 0; ind <= 10000; ind++) {
        if (!z[ind].empty()) {
            sort(all(z[ind]));
            ss[ind] = 1;
            while (sz(z[ind]) > ss[ind]) {
                ss[ind] <<= 1;
            }
            d[ind].resize(2 * ss[ind] + 1);
            for (int i = 0; i < sz(z[ind]); i++) {
                d[ind][ss[ind] + i].push_back(z[ind][i].second);
            }
            for (int i = ss[ind] - 1; i >= 1; i--) {
                if (d[ind][(i << 1)].empty() && d[ind][(i << 1) + 1].empty()) {
                    continue;
                }
                if (d[ind][(i << 1)].empty()) {
                    d[ind][i] = d[ind][(i << 1) + 1];
                    continue;
                }
                if (d[ind][(i << 1) + 1].empty()) {
                    d[ind][i] = d[ind][(i << 1)];
                    continue;
                }
                d[ind][i].resize(sz(d[ind][(i << 1)]) + sz(d[ind][(i << 1) + 1]));
                merge(all(d[ind][(i << 1)]), all(d[ind][(i << 1) + 1]), d[ind][i].begin());
            }
        }
    }
    long long ans = 0;
    for (int ind = 1; ind <= 10000; ind++) {
        if (!z[ind].empty()) {
           // cout << ind << ' ';
            for (auto x: z[ind]) {
                int pos = x.second;
                for (int ind1 = ind - k; ind1 <= ind + k; ind1++) {
                    if (ind1 < 1 || ind1 > 10000) {
                        continue;
                    }
                    if (!z[ind1].empty()) {
                       // cout << ind1 << ' ';
                        auto it = lower_bound(all(z[ind1]), make_pair(pos, -1));
                        if (it != z[ind1].end()) {
                            int l = it - z[ind1].begin() + 1;
                            int r = sz(z[ind1]);
                            //cout << pos - 1 << ' ' << ind << ' ' << ind1 << endl;
                            ans += rmq(ind1, 1, 1, ss[ind1], l, r, 2 * pos - x.first, pos - 1);
                        }
                    }
                }
            }
            cout << endl;
        }
    }
    cout << ans << endl;
    return 0;   
}