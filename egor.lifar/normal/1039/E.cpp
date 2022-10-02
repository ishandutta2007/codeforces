#pragma GCC optimize("O3","unroll-loops")
#include <iostream>
#include <complex>
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
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];//
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
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
const string FILENAME = "input";
const int MAXN = 100228;
const int BLOCK = 30;
const int BLOCK1 = 1200;
int n, w, q;
int x[MAXN];
int ans[MAXN];
int mx[18][MAXN];
int mx1[18][MAXN];
int gr[MAXN];
 
 
inline int getmax(const int l, const int r) {
    int grs = 31 - __builtin_clz(r - l + 1);
    return max(mx1[grs][l], mx1[grs][r - (1 << grs) + 1]);
}
 //////
 
inline int getmin(const int l, const int r) {
    int grs = 31 - __builtin_clz(r - l + 1);
    return min(mx[grs][l], mx[grs][r - (1 << grs) + 1]);
}
 
 
inline bool check(const int l, const int r, int k) {
    if (l > r || r >= n) {
        return false;
    }
    int f = getmin(l, r);
    int f1 = getmax(l, r);
    return f + w - f1 >= k;
}
 
 
inline int findGroupEnd(const int i, const int k) {
    int l = i;
    int r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(i, mid, k)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l + 1;
}
 
 
int curs[MAXN];
int jump[MAXN];
int target[MAXN];
 
int val;
 
void calc(int i) { 
    if (curs[i] - i  == BLOCK) {
        jump[i] = 0;
        target[i] = i;
    } else {
        if (curs[i] >= n) {
            jump[i] = 1;
            target[i] = curs[i];
        } else {
            if (target[curs[i]] >= i + BLOCK) {
                int t = curs[i];
                int cnt = 1;
                int val = i + BLOCK;
                while (curs[t] < val) {
                    cnt++;
                    t = curs[t];
                }
                target[i] = curs[t];
                jump[i] = cnt + 1;
            } else {
                jump[i] = 1 + jump[curs[i]];
                target[i] = target[curs[i]];
            }
        }
    }
}
 
 ////
void calc1(int i) { 
    if (curs[i] - i == BLOCK) {
        jump[i] = 0;
        target[i] = i;
    } else {
        if (curs[i] >= n) {
            jump[i] = 1;
            target[i] = curs[i];
        }
    }
}
 
 
int gt[MAXN];
int ls[MAXN];
int ft[MAXN];
int ukr;
int nxt[MAXN];
bool used[MAXN];
int st[MAXN];
int uks;
int grs;
int stacker[MAXN];
int ukt = 0;
int curuk[MAXN];
int curval[MAXN];
 
 
void dfs(int start) { 
    ukt = 0;  
    stacker[ukt] = start;
    curuk[start] = gt[start];
    ukt++;
    uks = 0;
    curval[start] = 0;
    while (ukt) {
        int u = stacker[ukt - 1];
        if (curuk[u] == gt[u]) {
            used[u] = true;
            if (u <= grs) {
                 if (target[curs[u]] >= u + BLOCK) {
                    while (curval[u] < uks && st[curval[u]] >= u + BLOCK) {
                        curval[u]++;
                    }
                    int l = curval[u];
                    jump[u] = uks - l;
                    if (curs[st[l]] - st[l] == BLOCK) {
                        target[u] = st[l];
                    } else {
                        jump[u]++;
                        target[u] = curs[st[l]];
                    }
                } else {
                    jump[u] = 1 + jump[curs[u]];
                    target[u] = target[curs[u]];
                }
            }   
            st[uks] = u;
            uks++;
        } 
        if (curuk[u] == -1) {
            uks--;
            ukt--;
            continue;
        } 
        int h = ft[curuk[u]];
        curuk[u] = nxt[curuk[u]];
        if (!used[h]) {
            stacker[ukt] = h;
            curval[h] = curval[u];
            curuk[h] = gt[h];
            ukt++;
        }
    }
}
 
 
void add(int a, int b) {
    if (gt[a] == -1) {
        gt[a] = ukr;
        ls[a] = ukr;
        ft[ukr] = b;
        nxt[ukr] = -1;
        ukr++;
    } else {
        nxt[ls[a]] = ukr;
        ft[ukr] = b;
        nxt[ukr] = -1;
        ls[a] = ukr;
        ukr++;
    }
}
 
void update(int tt) {
    // ukr = 0;
    // for (int j = min(i + BLOCK, n); j >= max(0, i - BLOCK - 5); j--) {
    //     gt[j] = -1;
    // }
    // for (int j = min(i + BLOCK, n); j >= max(0, i - BLOCK - 5); j--) {
    //     used[j] = false;
    // }
    // for (int j = max(0, i - BLOCK - 5); j <= i; j++) {
    //     if (curs[j] == BLOCK || j + curs[j] >= n) {
    //         calc1(j);
    //         used[j] = true;
    //         continue;
    //     }
    //     add(j + curs[j], j);
    // }
    // grs = i;
    // for (int j = min(i + BLOCK, n); j >= max(0, i - BLOCK - 1); j--) {
    //     if (!used[j]) {
    //         dfs(j);
    //     }
    // }
    for (int i = tt; i >= max(0, tt - BLOCK - 1); --i) {
        int val = i + BLOCK;
        if (curs[i] == val) {
            jump[i] = 0;
            target[i] = i;
        } else {///
            if (curs[i] >= n) {
                jump[i] = 1;
                target[i] = curs[i];
            } else {
                if (target[curs[i]] >= val) {
                    int t = curs[i];
                    int cnt = 1;
                    while (curs[t] < val) {
                        cnt++;
                        t = curs[t];
                    }
                    target[i] = curs[t];
                    jump[i] = cnt + 1;
                } else {
                    jump[i] = 1 + jump[curs[i]];
                    target[i] = target[curs[i]];
                }
            }
        }
    }
}
 
 
bool bad[MAXN];
int curs2[MAXN];
 
 
 
inline bool comp(const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > & b) {
    return a.first < b.first;
}
 
int useded[MAXN];
int ukted;
int ptr[MAXN];
int mink[MAXN];
int maxk[MAXN];

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);  ///   
    n = readInt(), w = readInt(), q = readInt();
    for (int i = 0; i < n; i++) {
        x[i] = readInt();
        mx[0][i] = x[i];
        mx1[0][i] = x[i];
    }
    for (int k = 1; k < 18; k++) {
        for (int i = 0; i < n; i++) {
            int t = min(i + (1 << (k - 1)), n - 1);
            mx[k][i] = min(mx[k - 1][i], mx[k - 1][t]);
            mx1[k][i] = max(mx1[k - 1][i], mx1[k - 1][t]);
        }
    }
    int cur = 1;
    int step = 0;
    for (int i = 1; i <= n; i++) {
        if (cur + cur <= i) {
            cur += cur;
            step++;
        }
        gr[i] = step;
    }
    vector<pair<int, int> > st;
    for (int it = 0; it < q; it++) {
        int k;
       k = readInt();
        st.pb({w - k, it});
    }
    sort(all(st));
    vector<pair<int, pair<int, int> > > g;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= BLOCK; j++) {
            int maxk = 0;
            if (i + j - 1 >= n) {
                maxk = 0;
            } else {
                int s = getmin(i, i + j - 1);
                int s1 = getmax(i, i + j - 1);
                maxk = max(0, s + w - s1);
            }
            if (maxk) {
                g.pb({maxk, {i, j}});
            }
        }
        curs[i] = i + 1;
        mink[i] = x[i];
        maxk[i] = x[i];
        ptr[i] = i + 1;
    }
    sort(all(g), comp);
    reverse(all(g));
    val = 1;
    int uk = 0;
    for (int i = n - 1; i >= 0; i--) {
        calc(i);
    }
    int uk1 = 0;
    for (int it = 0; it < q; it++) {
        val = w - st[it].first; 
        ukted++;
        vector<int> h;
        while (uk < sz(g) && g[uk].first >= val) {
            int gh = curs[g[uk].second.first];
            chkmax(curs[g[uk].second.first], g[uk].second.first + g[uk].second.second);
            if (curs[g[uk].second.first] != gh) {
                h.pb(g[uk].second.first);
            }
            uk++;
        }
        for (auto x: h) {
            if (useded[x] != ukted) {
                useded[x] = ukted;
                update(x);
            }
        }
        int cur = 0;
        int cnt = 0;
        while (cur < n) {
            if (curs[cur] - cur == BLOCK) {
                cnt++;
                if (cur) {
                    chkmax(ptr[cur], ptr[cur - 1]);
                    if (ptr[cur] < n) {
                        mink[cur] = getmin(cur, ptr[cur]);
                        maxk[cur] = getmax(cur, ptr[cur]);
                    }//
                }
                while (ptr[cur] < n && ptr[cur] < cur + BLOCK1 && mink[cur] + w - maxk[cur] >= val) {
                    ptr[cur]++;
                    chkmin(mink[cur], x[ptr[cur]]);
                    chkmax(maxk[cur], x[ptr[cur]]);
                }
                if (ptr[cur] < cur + BLOCK1) {
                    cur = ptr[cur];
                } else {
                    cur = findGroupEnd(cur, val);
                }
            } else {
                cnt+= jump[cur];
                cur = target[cur];
            }
        }
        ans[st[it].second] = cnt - 1;
    }
    for (int it = 0; it < q; it++) {
        writeInt(ans[it], '\n');
    }
    return 0;
}   ////