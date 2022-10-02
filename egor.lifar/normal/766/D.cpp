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
#define rank rank1
const int MAXN = 100001;


int n, m, q;
unordered_map<string, int> kek;
int parent[MAXN];
int par[MAXN];
int rank[MAXN];


int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}


int set_union(int a, int b) {
    a = find_set(a), b = find_set(b);
    if (rank[a] > rank[b]) {
        parent[b] = a;
        chkmax(rank[a], rank[b] + 1);
        return a;
    } else {
        parent[a] = b;
        chkmax(rank[b], rank[a] + 1);
        return b;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        kek[a] = i;
        par[i] = -1;
        parent[i] = i;
        rank[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int t;
        string a, b;
        cin >> t >> a >> b;
        int l = kek[a];
        int r = kek[b];
        bool bad = 0;
        if (t == 1) {
            int s = find_set(l);
            int s1 = find_set(r);
            if (s != s1) {
                if (par[s] == s1) {
                    bad = 1;
                } else {
                    int ns = set_union(s1, s);
                    if (par[s1] != -1) {
                        if (par[s] == -1) {
                            par[ns] = par[s1];
                        } else {
                            par[ns] = set_union(par[s1], par[s]);
                        }
                    } else {
                        par[ns] = par[s];
                    }
                    if (par[ns] != -1) {
                        par[par[ns]] = ns;
                    } 
                }
            }
        } else {
            int s = find_set(l);
            int s1 = find_set(r);
            if (s == s1) {
                bad = 1;
            } else {
                if (par[s] != s1) {
                    if (par[s] == -1 && par[s1] == -1) {
                        par[s] = s1;
                        par[s1] = s;
                    } else {
                        if (par[s] != -1 && par[s1] == -1) {
                            s1 = set_union(s1, par[s]);
                            par[s] = s1;
                            par[s1] = s;
                        } else {
                            if (par[s] == -1 && par[s1] != -1) {
                                s = set_union(s, par[s1]);
                                par[s] = s1;
                                par[s1] = s;
                            } else {
                                int kt = par[s];
                                int kt1 = par[s1];
                                s1 = set_union(s1, kt);
                                s = set_union(s, kt1);
                                par[s] = s1;
                                par[s1] = s;
                            }
                        }
                    }
                }
            }
        }
        if (bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        int l = kek[a];
        int r = kek[b];
        int s = find_set(l);
        int s1 = find_set(r);
        if (s == s1) {
            cout << "1\n";
        } else {
            if (par[s] != -1 && find_set(par[s]) == s1) {
                cout << "2\n";
            } else {
                cout << "3\n";
            }
        }
    }
    return 0;
}