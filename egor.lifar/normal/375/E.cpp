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
const int MAXN = 2001;
const double eps = 1e-6;
 
 
int n, m;
double a[MAXN][MAXN];
double b[MAXN], c[MAXN];
double resvalue[MAXN];
int basisInd[MAXN];
double curadd = 0.0;
double cp[MAXN];
double ap[MAXN][MAXN];
double bp[MAXN];
double cf[MAXN];
int cnt;
 
 
inline void pivot(int wherei, int wherej) {
    a[wherej][basisInd[wherej]] = -1;
    basisInd[wherej] = wherei;
    double x = -a[wherej][wherei];
    a[wherej][wherei] = 0;
    b[wherej] /= x;
    for (int i = 0; i < cnt; i++) {
        a[wherej][i] /= x;
    }
    double tx = c[wherei];
    curadd += tx * b[wherej];
    c[wherei] = 0;
    for (int i = 0; i < cnt; i++) {
        c[i] += tx * a[wherej][i];
    }
    for (int i = 0; i < m; i++) {
        if (abs(a[i][wherei]) > eps) {
            b[i] += a[i][wherei] * b[wherej];
            for (int j = 0; j < cnt; j++) {
                if (j == wherei) {
                    continue;
                }
                a[i][j] += a[i][wherei] * a[wherej][j];
            }
            a[i][wherei] = 0;
        }
    }
}


bool notBad[MAXN];
 
 
inline void simplexMethod() {
    while (true) {
        vector<pair<double, int> > st;
        for (int i = 0; i < cnt; i++) {
            notBad[i] = true;
        }
        for (int j = 0; j < m; j++) {
            notBad[basisInd[j]] = false;
        }
        for (int i = 0; i < cnt; i++) {
            if (notBad[i]) {
                st.push_back(make_pair(c[i], i));
            }
        }
        sort(all(st));
        reverse(all(st));
        int wherei = -1, wherej = -1;
        vector<pair<int, int> > g;
        pair<int, int> pp = make_pair(-1, -1);
        for (int i = 0; i < cnt; i++) {
            if (st[i].first < eps) {
                break;
            }
            int ind = st[i].second;
            int pos = -1;
            double bound = 1e18 + 1;
            bool was = 0;
            for (int j = 0; j < m; j++) { 
                if (abs(a[j][ind]) > eps) {
                    if (a[j][ind] > eps) {
                        if (pos == -1) {
                            pos = j;
                        }
                        continue;
                    }
                    was = 1;
                    if (bound > b[j] / -a[j][ind]) {
                        bound = b[j] / -a[j][ind];
                        pos = j; 
                    }
                }
            }
            if (pos != -1 && bound > eps) {
                wherei = ind;
                wherej = pos;
                break;
            }
            if (pp.first == -1) {
                pp = make_pair(ind, pos);
            } else {
                chkmin(pp, make_pair(ind, pos));
            }
        }
        if (wherei == -1) {
            if (pp.first == -1) {
                break;
            }
            wherei = pp.first;
            wherej = pp.second;
        }
        pivot(wherei, wherej);
    }
    for (int i = 0; i < n; i++) {
        resvalue[i] = 0.0;
    }
    for (int i = 0; i < m; i++) {
        resvalue[basisInd[i]] = b[i];
    }                        
}
 
 
inline void proceed() {
    bool bad = 0;
    for (int i = 0; i < m; i++) {
        if (b[i] < 0) {
            bad = 1;
            break;
        }
    }
    if (!bad) {
        cnt = n + m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] *= -1.0;
            }
            basisInd[i] = n + i;
        }
        return;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] *= -1.0;
        }
        a[i][n] = 1.0;
        basisInd[i] = n + i + 1;
    }
    int pos = 0;
    for (int i = 1; i < m; i++) {
        if (b[i] < b[pos]) {
            pos = i;
        }
    }
    cnt = n + m + 1;
    for (int i = 0; i < cnt; i++) {
        c[i] = 0;
    }
    c[n] = -1;
    curadd = 0;
    pivot(n, pos);
    simplexMethod();
    if (abs(curadd) > eps) {
        writeInt(-1, '\n');
        exit(0);
    }
    curadd = 0;
    for (int i = 0; i < m; i++) {
        if (basisInd[i] == n) {
            for (int j = 0; j < cnt; j++) {
                if (abs(a[i][j]) > eps) {
                    pivot(j, i);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        a[i][n] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[i] = cp[i];
    } 
    for (int i = n; i < cnt; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (abs(c[i]) > eps) {
            int pos = -1;
            for (int j = 0; j < m; j++) {
                if (basisInd[j] == i) {
                    pos = j;
                    break;
                }
            }
            if (pos != -1) {
                double oldi = c[i];
                curadd += b[pos] * oldi;
                c[i] = 0;
                for (int j = 0; j < cnt; j++) {
                    c[j] += a[pos][j] * oldi;
                }
            }
        }
    }
}



int x;
int colour[MAXN];
int black[MAXN];
int red[MAXN];
vector<pair<int, int> > v[MAXN]; 
vector<int> nearest[MAXN];
int id;


void dfs(int u, long long curlen, int pr) {
    nearest[id].push_back(u);
    for (auto h: v[u]) {
        if (curlen + h.second > x) {
            continue;
        }
        if (h.first == pr) {
            continue;
        }
        dfs(h.first, curlen + h.second, u);
    }
}

 
inline bool proceed1() {
    bool bad = 0;
    for (int i = 0; i < m; i++) {
        if (b[i] < 0) {
            bad = 1;
            break;
        }
    }
    if (!bad) {
        return true;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] *= -1.0;
        }
        a[i][n] = 1.0;
        basisInd[i] = n + i + 1;
    }
    int pos = 0;
    for (int i = 1; i < m; i++) {
        if (b[i] < b[pos]) {
            pos = i;
        }
    }
    cnt = n + m + 1;
    for (int i = 0; i < cnt; i++) {
        c[i] = 0;
    }
    c[n] = -1;
    curadd = 0;
    pivot(n, pos);
    simplexMethod();
    if (abs(curadd) > eps) {
        return false;
    }
    return true;
}


bool can(int x) {
  //  cout << x << endl;
    m = 0;
    for (int j = 0; j <= 2 * n + 4; j++) {
        a[m][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        a[m][i] = 1;
    }
    b[m] = 2 * x;
    m++;
    for (int j = 0; j <= 2 * n + 4; j++) {
        a[m][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (colour[i] == 1) {
            a[m][i] = 1;
        } else {
            a[m][i] = -1;
        }
    }
    b[m] = 0;
    m++;
    for (int j = 0; j <= 2 * n + 4; j++) {
        a[m][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (colour[i] == 1) {
            a[m][i] = -1;
        } else {
            a[m][i] = 1;
        }
    }
    b[m] = 0;
    m++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * n + 4; j++) {
            a[m][j] = 0;
        }
        for (auto x: nearest[i]) {
            if (colour[x] == 1) {
                a[m][x] = 1;
            }  else {
                a[m][x] = -1;
            }
        }
        b[m] = black[i] - 1;
       // cout << black[i] - 1 << endl;
        m++;
    }
    return proceed1();
}

 
int main() {
  //  freopen("simplex.in", "r", stdin);
  //  freopen("simplex.out", "w", stdout);
    n = readInt(), x = readInt();
    for (int i = 0; i < n; i++) {
        colour[i] = readInt();
    }
    for (int i = 0; i < n - 1; i++) {
        int a = readInt(), b = readInt(), w = readInt();
        a--, b--;
        v[a].push_back(make_pair(b, w));
        v[b].push_back(make_pair(a, w));
    }
    int cntgood = 0;
    for (int i = 0; i < n; i++) {
        id = i;
        dfs(i, 0, -1);
        for (auto h: nearest[i]) {
            if (colour[h] == 1) {
                black[i]++;
            } else {
                red[i]++;
            }
        }
        if (black[i]) {
            cntgood++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (colour[i] == 1) {
            a[m][i] = 1;
        } else {
            a[m][i] = -1;
        }
    }
    b[m] = 0;
    m++;
    for (int i = 0; i < n; i++) {
        if (colour[i] == 1) {
            a[m][i] = -1;
        } else {
            a[m][i] = 1;
        }
    }
    b[m] = 0;
    m++;
    for (int i = 0; i < n; i++) {
        a[m][i] = 1;
        b[m] = 1;
        m++;
        for (auto x: nearest[i]) {
            if (colour[x] == 1) {
                a[m][x] = 1;
            }  else {
                a[m][x] = -1;
            }
        }
        b[m] = black[i] - 1;
        m++;
    }
    for (int i = 0; i < n; i++) {
        c[i] = -1;
    }
    proceed();
    simplexMethod();
    double f = 0;
    for (int i = 0; i < n; i++) {
        f += resvalue[i] * -1.0;
    }
    f = -f;
    int ans = ((int)round(f) + 1) / 2;
    int t = 0;
    if (x > 500000000) {
        while (can(ans - 1)) {
            t++;
            ans--;
        }
    }
    writeInt(ans, '\n');
    return 0;               
}