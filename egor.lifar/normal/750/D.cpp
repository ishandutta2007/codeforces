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
 
struct flusher {
    ~flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
#define hash hash228 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define next next1
const int MAXN = 31;


int n;
int t[MAXN];
bool used[301][301][MAXN][8];
bool can[301][301][MAXN][8];
bool g[301][301];
int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};


bool dp(int i, int j, int k, int c) {
    if (i > 300 || j > 300 || i < 0 || j < 0) {
        return 0;
    }
    if (used[i][j][k][c]) {
        return can[i][j][k][c];
    }
    used[i][j][k][c] = 1;
    if (k == 1) {
        if (c == 1) {
            if (j == 150 + t[1] - 1 && i == 150) {
                can[i][j][k][c] = 1;
            }  
        }
        return can[i][j][k][c];
    }
    vector<int> prevc;
    if (c == 0) {
        prevc.push_back(5);
        prevc.push_back(7);
    }
    if (c == 1) {
        prevc.push_back(4);
        prevc.push_back(6);
    }
    if (c == 2) {
        prevc.push_back(7);
        prevc.push_back(4);
    }
    if (c == 3) {
        prevc.push_back(5);
        prevc.push_back(6);
    }
    if (c == 4) {
        prevc.push_back(2);
        prevc.push_back(1);
    }
    if (c == 5) {
        prevc.push_back(0);
        prevc.push_back(3);
    }
    if (c == 6) {
        prevc.push_back(1);
        prevc.push_back(3);
    }
    if (c == 7) {
        prevc.push_back(0);
        prevc.push_back(2);
    }
    int prevk = k - 1;
    int previ = i - dx[c] * t[k];
    int prevj = j - dy[c] * t[k];
    if (previ < 0 || prevj < 0 || previ > 300 || prevj > 300) {
        can[i][j][k][c] = 0;
        return 0;
    }
    for (auto c1: prevc) {
        can[i][j][k][c] |= dp(previ, prevj, prevk, c1);
    }
    return can[i][j][k][c];  
}


int main() {    
    n = readInt();
    for (int i = 1; i <= n; i++) {
        t[i] = readInt();
    }
    int cnt = 0;
    vector<int> prevc[8];
    prevc[0].push_back(5);
    prevc[0].push_back(7);
    prevc[1].push_back(4);
    prevc[1].push_back(6);
    prevc[2].push_back(7);
    prevc[2].push_back(4);
    prevc[3].push_back(5);
    prevc[3].push_back(6);
    prevc[4].push_back(2);
    prevc[4].push_back(1);
    prevc[5].push_back(0);
    prevc[5].push_back(3);
    prevc[6].push_back(1);
    prevc[6].push_back(3);
    prevc[7].push_back(0);
    prevc[7].push_back(2);
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= 300; i++) {
            for (int j = 0; j <= 300; j++) {
                for (int c = 0; c < 8; c++) {
                    if (k == 1) {
                        if (c == 1) {
                            if (j == 150 + t[1] - 1 && i == 150) {
                                can[i][j][k][c] = 1;
                            }  
                        }
                        continue;
                    }
                    int previ = i - dx[c] * t[k];
                    int prevj = j - dy[c] * t[k];
                    if (previ < 0 || prevj < 0 || previ > 300 || prevj > 300) {
                        continue;
                    }
                    for (auto c1: prevc[c]) {
                        can[i][j][k][c] |= can[previ][prevj][k - 1][c1];
                    }
                }
                for (int c = 0; c < 8; c++) {
                    if (can[i][j][k][c]) {
                        g[i][j] = 1;
                        for (int t1 = 1; t1 < t[k]; t1++) {
                            int ni = i - dx[c] * t1;
                            int nj = j - dy[c] * t1;
                            g[ni][nj] = 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j <= 300; j++) {
            if (g[i][j]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}