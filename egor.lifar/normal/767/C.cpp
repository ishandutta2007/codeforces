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
const int MAXN = 1000001;


int n, m, k;
vector<int> v[MAXN];
int t[MAXN];
int need;
int sum[MAXN];
int was[MAXN];
int root;


void dfs(int u) {
    sum[u] = t[u];
    int cnt = 0;
    vector<int> vt;
    for (auto h: v[u]) {
        dfs(h);
        if (sum[h] == need) {
            was[u] = h + 1;
            cnt++;
            vt.push_back(h + 1);
        } else {
            if (was[h]) {
                vt.push_back(was[h]);
                cnt++;
                was[u] = was[h];
            }
        }
        sum[u] += sum[h];
    }
    if (cnt >= 2) {
        writeInt(vt[0], ' ');
        writeInt(vt[1], '\n');
        exit(0);
    }
    if (u != root && sum[u] == need * 2 && was[u]) {
        writeInt(was[u], ' ');
        writeInt(u + 1, '\n');
        exit(0);
    }
}


int main() {    
    n = readInt();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x = readInt();
        t[i] = readInt();
        if (x == 0) {
            root = i;
        } else {
            x--;
            v[x].push_back(i);
        }
        sum += t[i];
    }   
    if (sum % 3 != 0) {
        writeInt(-1, '\n');
        return 0;
    }
    need = sum / 3;
    dfs(root); 
    writeInt(-1, '\n');
    return 0;
}