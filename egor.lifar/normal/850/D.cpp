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
#define get get228
#define y1 y1228    
const int MAXN = 1001;


pair<int, int> arr[3001];
char ans[3001][3001];
int A[MAXN];
int n;


bool get() {
    for (int i = 0; i < n; i++) {
        arr[i].first = A[i];
        arr[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        sort(arr + i, arr + n);
        int j = i + 1;
        while (j < n) {
            if (arr[i].first > 0) {
                arr[i].first -= 1;
                ans[arr[i].second][arr[j].second] = 1; 
                ans[arr[j].second][arr[i].second] = 0;
                j++;
            } else {
                if (arr[j].first > 0) {
                    arr[j].first -= 1;
                    ans[arr[i].second][arr[j].second] = 0; 
                    ans[arr[j].second][arr[i].second] = 1;
                    j++;
                } else {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i].first) {
            assert(false);
            return false;
        }
    }
    return true;
}


int m;
int a[MAXN];
bool dp[32][12000][151];
int pr[32][12000][151];


int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        a[i] = readInt();
    }
    sort(a, a + m);
    dp[0][0][0] = true;
    for (int i = 0; i < m; i++) {
        for (int sum = 0; sum < 12000; sum++) {
            for (int cnt = i; cnt <= 150; cnt++) {
                if (dp[i][sum][cnt]) {
                    int cursum = sum;
                    int curcnt = cnt;
                    for (int j = 1; j <= 150; j++) {
                        cursum += a[i];
                        curcnt++;
                        if (cursum < 12000 && cursum >= (curcnt * (curcnt - 1)) / 2) {
                            dp[i + 1][cursum][curcnt] = true;
                            pr[i + 1][cursum][curcnt] = j;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    vector<int> f;
    bool ff = true;
    for (int cnt = m; cnt <= 150; cnt++) {
        int sum = (cnt * (cnt - 1) / 2);
        if (dp[m][sum][cnt]) {
            int curm = m;
            int cursum = sum;
            int curf = cnt;
            while (curm) {
                int g = pr[curm][cursum][curf];
                for (int i = 0; i < g; i++) {
                    f.push_back(a[curm - 1]);
                }
                curm--;
                cursum -= g * a[curm];
                curf -= g;
            }
            ff = false;
            break;
        }
    }
    assert(!ff);
    reverse(all(f));
    n = sz(f);
    for (int i = 0; i < n; i++) {
        A[i] = f[i];
    }
    if (get()) {
        writeInt(n, '\n');
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                writeInt(ans[i][j]);
            }
            writeChar('\n');
        }
        return 0;
    }
    return 0;
}