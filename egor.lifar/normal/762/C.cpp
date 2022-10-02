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
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 100000;


string a, b;
int n, m;
int left[MAXN];
int right[MAXN];


bool get(int x) {
    if (x == n) {
        return 1;
    }
    int uk = 0;
    for (int i = 0; i < n; i++) {
        while (uk < m && b[uk] != a[i]) {
            uk++;
        }
        left[i] = uk; 
        uk = min(m, uk + 1);
    }
    uk = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (uk >= 0 && b[uk] != a[i]) {
            uk--;
        }
        right[i] = uk;
        uk = max(-1, uk - 1);
    }
    for (int i = 0; i < n; i++) {
        int j = min(n, i + x + 1);
        if (left[i] < m && (j == n || right[j] > left[i])) {
            return 1;
        }
        if (i <= x && right[i] >= 0) {
            return 1;
        }
    }
    return 0;
}


void get1(int x) {
    if (x == n) {
        return;
    }
    int uk = 0;
    for (int i = 0; i < n; i++) {
        while (uk < m && b[uk] != a[i]) {
            uk++;
        }
        left[i] = uk;
        uk = min(m, uk + 1);
    }
    uk = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (uk >= 0 && b[uk] != a[i]) {
            uk--;
        }
        right[i] = uk;
        uk = max(-1, uk - 1);
    }
    for (int i = 0; i < n; i++) {
        int j = min(n, i + x + 1);
        if (left[i] < m && (j == n || right[j] > left[i])) {
            for (int k = 0; k <= i; k++) {
                cout << a[k];
            }
            for (int k = j; k < n; k++) {
                cout << a[k];
            }
            cout << endl;
            return;
        }
        if (i <= x && right[i] >= 0) {
            for (int k = i; k < n; k++) {
                cout << a[k];
            }
            cout << endl;
            return;
        }
    }
}


int main() {    
    ios_base::sync_with_stdio(false);
    cin >> b >> a;
    n = sz(a), m = sz(b);
    int l = 0;
    int r = n;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (get(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l == n) {
        cout << "-" << endl;
    } else {
        get1(l);
    }
    return 0;   
}