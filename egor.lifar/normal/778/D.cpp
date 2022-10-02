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
const int MAXN = 51;


int n, m;
char stuff[MAXN][MAXN];
char stuff2[MAXN][MAXN];
int n1, m1;
vector<pair<int, int> > ans[2];
int flip = 0;


void solve(int i, int j, int dir, int f) {
    if (dir == 0 && stuff[i][j] == 'L') {
        solve(i + 1, j, 1, f);
        ans[f].push_back(make_pair(i, j));
        stuff[i][j] = 'U';
        stuff[i + 1][j] = 'D';
        stuff[i][j + 1] = 'U';
        stuff[i + 1][j + 1] = 'D';
        return;
    }
    if(dir == 1 && stuff[i][j] == 'U') {
        solve(i, j + 1, 0, f);
        ans[f].push_back(make_pair(i, j));
        stuff[i][j] = 'L'; 
        stuff[i + 1][j] = 'L';
        stuff[i][j + 1] = 'R';
        stuff[i + 1][j + 1] = 'R';
        return;
    }
    return;
}


int main(){
    n = readInt(), m = readInt();
    for (int f = 0; f < 2; f++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                stuff[i][j] = readChar();
            }
        }
        if (n & 1) {
            flip = 1;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (stuff[j][i] == 'L') {
                        stuff2[i][j] = 'U';
                    }
                    if (stuff[j][i] == 'U') {
                        stuff2[i][j] = 'L';
                    }
                    if (stuff[j][i] == 'R') {
                        stuff2[i][j] = 'D';
                    }
                    if (stuff[j][i] == 'D') {
                        stuff2[i][j] = 'R';
                    }
                }
            }
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++) {
                    stuff[i][j] = stuff2[i][j];
                }
            }
            swap(m, n);
        }
        for (int i = 0; i < n; i+= 2) {
            for(int j = 0; j < m; j++) {
                solve(i,j, 0,f);
            }
        }
        if (flip) {
            swap(n,m);
        }           
    }
    writeInt(sz(ans[0]) + sz(ans[1]), '\n');
    reverse(all(ans[1]));
    for (int f = 0; f < 2; f++) {
        for (int i = 0; i < sz(ans[f]); i++) {
            if (flip) {
                swap(ans[f][i].first, ans[f][i].second);
            }
            writeInt(ans[f][i].first + 1, ' ');
            writeInt(ans[f][i].second + 1, '\n');
        }
    }
    return 0;
}