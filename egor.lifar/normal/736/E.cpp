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
 
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

 
int n, m;
int a[3001];
pair<int, int> arr[3001];
char ans[3001][3001];
int s[3001];


int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
   //  n = 2999;
   //  m = 2999;
    int sum = n * (n - 1);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        //a[i] = 2 * (m - i - 1);
        sum -= a[i];
    }
    int cur = 0;
    for (int i = n - 1; i >= m; i--) {
        a[i] = (n - i) * (n - i - 1) - cur;
        cur += a[i];
    }
    sum -= cur;
    for (int i = m; i < n && sum > 0; i++) {
        int c = a[i - 1] - a[i];
        c = min(c, sum);
        sum -= c;
        a[i] += c;
    }
    if (a[m] > a[m - 1] || sum != 0) {
        cout << "no\n";
        return 0;
    }
    cout << "yes\n";
    for (int i = 0; i < n; i++) {
        arr[i].first = a[i];
        arr[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        sort(arr + i, arr + n);
        int j = i + 1;
        while (j < n) {
            if (arr[i].first > 0) {
                arr[i].first--; arr[j].first--;
                ans[arr[i].second][arr[j].second] = 1; 
                ans[arr[j].second][arr[i].second] = 1;
                j++;
            } else {
                arr[j].first -= 2;
                ans[arr[i].second][arr[j].second] = 0; 
                ans[arr[j].second][arr[i].second] = 2;
                j++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << 'X';
            } else {
                if (ans[i][j] == 2) {
                    cout << 'W';
                } else {
                    if (ans[i][j] == 1) {
                        cout << 'D';
                    } else {
                        cout << 'L';
                    }
                }
            }
        }
        cout << '\n';
    }   
    return 0;
}