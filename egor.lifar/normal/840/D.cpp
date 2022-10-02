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
const int MAXN = 300001;


int n, q;
int a[MAXN];
vector<pair<pair<int, int>, pair<int, int> > > z[MAXN];
int d[4 * MAXN];
int ans[MAXN];
int who[MAXN];


inline void change(int i, int delta) {
    d[i] += delta;
    while (i >> 1 > 0) {
        i >>= 1;
        d[i] = max(d[i << 1], d[(i << 1) + 1]);    
    }
}


inline int spusk(int v, int l, int r, int x) {
    if (l == r) {
        return who[l - 1];
    }
    int vn = v << 1;
    int vm = (l + r) >> 1;
    if (d[vn] >= x) {
        return spusk(vn, l, vm, x);
    } else {
        return spusk(vn + 1, vm + 1, r, x);
    }
}


int curcnt[MAXN];
int where[MAXN];
int cntr[MAXN];


int main(){
    n = readInt(), q = readInt();
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }
    int block = (int)sqrt(n);
    for (int i = 0; i < q; i++) {
        int l = readInt(), r = readInt(), k = readInt();
        l--, r--;
        int cnt = (r - l + 1) / k + 1;
        if (cnt > r - l + 1) {
            ans[i] = -1;
            continue;
        }
        if (cnt <= block) {
            ans[i] = 1e9;
            for (int j = l; j <= r; j++) {
                curcnt[a[j]]++;
                if (curcnt[a[j]] >= cnt) {
                    chkmin(ans[i], a[j]);
                }
            }
            for (int j = l; j <= r; j++) {
                curcnt[a[j]]--;
            }
            if (ans[i] > n) {
                ans[i] = -1;
            }
            continue;
        }
        z[l / block].push_back(make_pair(make_pair(r, l), make_pair(i, k)));
    }
    for (int i = 0; i < n; i++) {
        cntr[a[i]]++;
    }
    vector<int> g;
    for (int i = 1; i <= n; i++) {
        if (cntr[i] >= block) {
            where[i] = sz(g);
            who[sz(g)] = i;
            g.push_back(i);
        } else {
            where[i] = -1;
        }
    }
    if (sz(g) == 0) {
        for (int i = 0; i < q; i++) {
            if (ans[i] == 0) {
                ans[i] = -1;
            }
        }
    } else {
        int ss = 1;
        while (ss < sz(g)) {
            ss <<= 1;
        }
        for (int i = 1; i <= n; i++) {
            if (where[i] != -1) {
                where[i] += ss;
            }
        }
        //n / block * n * logn + q * block * logn
        //sqrt(n) * n * logn + q * sqrt(n) * logn
        for (int i = 0; i <= (n - 1) / block; i++) {
            bool f = true;
            int lastl, lastr;
            sort(all(z[i]));
            for (auto x: z[i]) {
                if (f) {
                    int l = x.first.second;
                    int r = x.first.first;
                    lastl = l;
                    lastr = r;
                    int id = x.second.first;
                    int k = x.second.second;
                    for (int j = l; j <= r; j++) {
                        if (where[a[j]] == -1) continue;
                        change(where[a[j]], 1);
                    }
                    int cnt = (r - l + 1) / k + 1;
                    if (d[1] < cnt) {
                        ans[id] = -1;
                    } else {
                        ans[id] = spusk(1, 1, ss, cnt);
                    }
                } else {
                    int l = x.first.second;
                    int r = x.first.first;
                    int id = x.second.first;
                    int k = x.second.second;
                    for (int j = lastr + 1; j <= r; j++) {
                        if (where[a[j]] == -1) continue;
                        change(where[a[j]], 1);
                    }
                    if (lastl != l) {
                        if (lastl < l) {
                            for (int j = lastl; j < l; j++) {
                                if (where[a[j]] == -1) continue;
                                change(where[a[j]], -1);
                            } 
                        } else {
                            for (int j = lastl - 1; j >= l; j--) {
                                if (where[a[j]] == -1) continue;
                                change(where[a[j]], 1);
                            } 
                        }
                    }
                    int cnt = (r - l + 1) / k + 1;
                    if (d[1] < cnt) {
                        ans[id] = -1;
                    } else {
                        ans[id] = spusk(1, 1, ss, cnt);
                    }
                    lastl = l;
                    lastr = r;
                }
                f = false;
            }
            for (int ii = 1; ii < ss + sz(g); ii++) {
                d[ii] = 0;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        writeInt(ans[i], '\n');
    }
    return 0;
}