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
const int MAXN = 100002;


struct query
{
    int l, r, id;   
    query(){} 
    query(int _l, int _r, int _id) {
        l = _l;
        r = _r;
        id = _id;
    }
};


bool operator <(query a, query b) {
    return a.r < b.r;
}


int n, k;
int tt[MAXN];
int a[MAXN];
int q;
long long pref[MAXN];
map<long long, int> where;
int pos[MAXN], l[MAXN], r[MAXN];
long long ans[MAXN];
vector<query> g[500];
int cnt[MAXN];
long long res;


inline void add(int i, bool keks = false) {
    if (keks) {
        if (r[i] != -1) {
            res += cnt[r[i]];
        }
    } else {
        if (l[i] != -1) {
            //cout << cnt[l[i]] << ' ' << i + 1 << ' ' << l[i] << endl;
            res += cnt[l[i]];
        }
    }
    //cout << pos[i] << ' ' << i + 1 << endl;
    cnt[pos[i]]++;
}


inline void del(int i) {
    cnt[pos[i]]--;
    if (r[i] != -1) {
        res -= cnt[r[i]];
    }
}


int main() {
    n = readInt(), k = readInt();
    for (int i = 0; i < n; i++) {
        tt[i] = readInt();
    }
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }
    for (int i = 0; i < n; i++) {
        pref[i] = (tt[i] == 1 ? a[i]: -a[i]) + (i ? pref[i - 1]: 0);
    }
    vector<long long> vx;
    vx.push_back(0);
    for (int i = 0; i < n; i++) {
        vx.push_back(pref[i]);
    }
    sort(all(vx));
    vx.resize(distance(vx.begin(), unique(all(vx))));
    for (int i = 0; i < sz(vx); i++) {
        where[vx[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        pos[i] = where[pref[i]];
        l[i] = (where.find(pref[i] - k) != where.end() ? where[pref[i] - k]: -1);
        r[i] = (where.find(pref[i] + k) != where.end() ? where[pref[i] + k]: -1);
    }
    int BLOCK = (int)sqrt(n);
    q = readInt();
    for (int i = 0; i < q; i++) {
        int l1 = readInt(), r1 = readInt();
        l1--, r1--;
        g[l1 / BLOCK].push_back(query(l1, r1, i));
    }
    int r0 = (where.find(+k) != where.end() ? where[+k]: -1);
    int pos0 = where[0];
    for (int i = 0; i <= (n - 1) / BLOCK; i++) {
        if (g[i].empty()) {
            continue;
        }
        sort(all(g[i]));
        memset(cnt, 0, sizeof(cnt));
        res = 0;
        int lastl, lastr;
        for (int j = 0; j < sz(g[i]); j++) {
            int ll = g[i][j].l;
            int rr = g[i][j].r;
            if (j == 0) {
                for (int t = ll; t <= rr; t++) {
                    add(t);
                }
                ans[g[i][j].id] = res + (ll == 0 ? (r0 != -1 ? cnt[r0]: 0): (r[ll - 1] != -1 ? cnt[r[ll - 1]]: 0));
                lastl = ll;
                lastr = rr;
            } else {
                if (lastl > ll) {
                    for (int t = lastl - 1; t >= ll; t--) {
                        add(t, true);
                    }
                } else {
                    for (int t = lastl; t < ll; t++) {
                        del(t);
                    }
                }
                for (int t = lastr + 1; t <= rr; t++) {
                    add(t);
                }
                ans[g[i][j].id] = res + (ll == 0 ? (r0 != -1 ? cnt[r0]: 0): (r[ll - 1] != -1 ? cnt[r[ll - 1]]: 0));
                lastl = ll;
                lastr = rr;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}