/*






  










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
const int INF = 1000 * 1000 * 1000;
const long long LINF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int MAXN = 228228;


int n, m, k;
int c[MAXN];
int f1[MAXN], f2[MAXN];


int main(){
    n = readInt(), m = readInt(), k = readInt();
    for (int i = 0; i < n; i++) {
        c[i] = readInt();
    }
    int q = readInt();
    for (int i = 0; i < q; i++) {
        int x = readInt();
        f1[x - 1] = 1;
    }
    q = readInt();
    for (int i = 0; i < q; i++) {
        int x = readInt();
        f2[x - 1] = 1;
    }
    vector<int> w, a, b;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        if (f1[i] && f2[i]) {
            w.push_back(c[i]); 
        } else if (f1[i]) {
            a.push_back(c[i]);
        } else if (f2[i]) {
            b.push_back(c[i]);
        } else {
            d.push_back(c[i]);
        }
    }
    sort(all(w));
    sort(all(a));
    sort(all(b));
    sort(all(d));
    vector<long long> ww, aa, bb, dd;
    ww.push_back(0);
    aa.push_back(0);
    bb.push_back(0);
    dd.push_back(0);
    for (int i = 0; i < sz(w); i++) {
        ww.push_back(ww.back() + w[i]);
    }
    for (int i = 0; i < sz(a); i++) {
        aa.push_back(aa.back() + a[i]);
    }
    for (int i = 0; i < sz(b); i++) {
        bb.push_back(bb.back() + b[i]);
    }
    for (int i = 0; i < sz(d); i++) {
        dd.push_back(dd.back() + d[i]);
    }
    long long ans = LINF;
    for (int i = 0; i <= sz(w); i++) {
        long long cost = ww[i];
        int need = max(0, k - i);
        if (need > sz(a) || need > sz(b) || i + need * 2 > m) {
            continue;
        }
        cost += aa[need];
        cost += bb[need];
        int re = m - i - 2 * need;
        if (sz(a) - need + sz(b) - need + sz(d) < re) {
            continue;
        }
        if (re > 0) {
            int l = 0;
            int r = INF;
            while (l < r) {
                int mid = (l + r) >> 1;
                int cnt = 0;
                int h = upper_bound(all(a), mid) - a.begin();
                cnt += max(0, h - need);
                h = upper_bound(all(b), mid) - b.begin();
                cnt += max(0, h - need);
                h = upper_bound(all(d), mid) - d.begin();
                cnt += max(0, h);
                if (cnt >= re) {
                    r = mid; 
                } else {
                    l = mid + 1;
                }
            }
            int mid = l;
            int cnt = 0;
            int h = upper_bound(all(a), mid) - a.begin();
            cnt += max(0, h - need);
            if (h > need) {
                cost += aa[h] - aa[need];
            }
            h = upper_bound(all(b), mid) - b.begin();
            cnt += max(0, h - need);
            if (h > need) {
                cost += bb[h] - bb[need];
            }
            h = upper_bound(all(d), mid) - d.begin();
            cnt += max(0, h);
            cost += dd[h];
            if (cnt > re) {
                cost -= mid * 1LL * (cnt - re);
            }
        }
        ans = min(ans, cost);
    }
    if (ans > 1e17) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}