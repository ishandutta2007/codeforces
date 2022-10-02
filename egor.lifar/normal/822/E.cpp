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
const int MAXN = 100228;


int k, n, m;
string a, b;
int xx;
int ss = 1;
int dp[MAXN][31];
string s;
int c[2 * MAXN];
int p[2 * MAXN];
int where[2 * MAXN];
int who[2 * MAXN];
int lcp[5 * MAXN];
vector<int> x[2 * MAXN];
int where1[MAXN], where2[MAXN];


void change(int i, int xt) {
    lcp[i] = xt;
    while (i >> 1 > 0) {
        i >>= 1;
        lcp[i] = min(lcp[i * 2], lcp[i * 2 + 1]);
    }
}


int rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return MAXN;
    }
    if (l <= vl && vr <= r) {
        return lcp[v];
    }
    return min(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


int getLCP(int i, int j) {
    int l = where[where1[i]] + 1;
    int r = where[where2[j]] + 1;
    if (l > r) {
        swap(l, r);
    }
    int as = rmq(1, 1, ss, l, r - 1);
    chkmin(as, k - i);
    chkmin(as, m - j);
    return as;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> k;
    cin >> a;
    cin >> m;
    cin >> b;
    cin >> xx;
    s = a;
    for (int i = 0; i < k; i++) {
        where1[i] = i;
    }
    s += 'z' + 1;
    s += b;
    for (int i = 0; i < m; i++) {
        where2[i] = sz(a) + 1 + i;
    }
    s += 'z' + 2;
    n = sz(s);
    vector<pair<char, int> > v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(s[i], i));
    }
    sort(v.begin(), v.end());
    int classes = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i].first != v[i - 1].first) {
            classes++;
        }
        c[v[i].second] = classes - 1;
        p[i] = v[i].second;
    }
    for (int h = 0; (1 << h) < n; h++) {
        int kr = (1 << h);
        vector<pair<pair<int, int>, int> > v1;
        for (int i = 0; i <= classes; i++) {
            x[i].clear();
        }
        for (int i = 0; i < n; i++) {
            x[c[(p[i] + kr) % n]].push_back(p[i]);
        }
        vector<int> pn;
        for (int i = 0; i < classes; i++) {
            for (int j = 0; j < (int)x[i].size(); j++) {
                pn.push_back(x[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            p[i] = pn[i];
        }
        for (int i = 0; i <= classes; i++) {
            x[i].clear();
        }
        for (int i = 0; i < n; i++) {
            x[c[p[i]]].push_back(p[i]);
        }
        pn.clear();
        for (int i = 0; i < classes; i++) {
            for (int j = 0; j < (int)x[i].size(); j++) {
                pn.push_back(x[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            p[i] = pn[i];
        }
        vector<int> cn;
        classes = 0;
        cn.resize(n);
        for (int i = 0; i < n; i++) { 
            if (i == 0 || (c[p[i]] != c[p[i - 1]] || (c[(p[i] + kr) % n] != c[(p[i - 1] + kr) % n]))) {
                classes++;
            } 
            cn[p[i]] = classes - 1;
        }   
        for (int i = 0; i < n; i++) {
            c[i] = cn[i];
        }
    }
    for (int i = 0; i < n; i++) {
        where[p[i]] = i;
        who[i] = p[i];
    }
    while (ss <= n) {
        ss <<= 1;
    }
    int xxx = 0;
    for (int i = 0; i < n; i++) {
        xxx = max(0, xxx - 1);
        if (where[i] != n - 1) {
            int j = who[where[i] + 1];
            for (int g = i + xxx; g < n; g++) {
                if ((g - i + 1 > n - j)) {
                    break;
                }
                if (s[g] != s[j + (g -  i)]) {
                    break;
                }
                xxx++;
            }
            change(ss + where[i], xxx);
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < xx; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < k; i++) {
        int kek = getLCP(i, 0);
        //cout << kek << endl;
        chkmax(dp[i + kek - 1][0], kek - 1);
        for (int j = 0; j < xx; j++) {
            if (dp[i][j] != -1) {
                chkmax(dp[i + 1][j], dp[i][j]);
                if (i != k - 1 && j != xx - 1) {
                    int t = getLCP(i + 1, dp[i][j] + 1);
                    if (t) {
                        chkmax(dp[i + t][j + 1], dp[i][j] + t);
                    }
                }
            }
            if (dp[i][j] >= m - 1) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;               
}