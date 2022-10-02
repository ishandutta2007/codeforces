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
const int MAXN = 200001;
int n, m;
int a[MAXN];
bool bad[MAXN];
unordered_map<int, bool> used;
vector<pair<int, int> > a1;
int ans[MAXN];
bool used1[MAXN];


int main() {
    n = readInt(), m = readInt();
    a1.resize(n);
    for (int i = 0; i < n; i++) {
        a1[i].first = readInt();
        a1[i].second = i;
    }
    sort(all(a1));
    int cnt = 0, cnt1 = 0;
    int ob = 0;
    for (int i = 0; i < n; i++) {
        a[i] = a1[i].first;
        if (i && a[i] == a[i - 1]) {
            ob++;
            bad[i] = 1;
            continue;
        }
        if (a[i] & 1) {
            if (cnt1 == n / 2) {
                bad[i] = 1;
                ob++;
            } else {
                cnt1++;
            }
        } else {
            if (cnt == n / 2) {
                bad[i] = 1;
                ob++;
            } else {
                cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!bad[i]) {
            ans[a1[i].second] = a[i];
            used1[a1[i].second] = 1;
            used[a[i]] = 1;
        }
    }
    int uk = 1;
    int cnts = 0;
    int sl = 0;
    while (cnt < n / 2 || cnt1 < n / 2) {
        while (used[uk]) {
            uk++;
        }
        if (uk & 1 && cnt1 < n / 2) {
            cnt1++;
            while (used1[sl]) {
                sl++;
            }
            used1[sl] = 1;
            ans[sl] = uk;
            used[uk] = 1;
            cnts++;
            continue;
        }
        if (!(uk & 1) && cnt < n / 2) {
            cnt++;
            while (used1[sl]) {
                sl++;
            }
            used1[sl] = 1;
            ans[sl] = uk;
            used[uk] = 1;
            cnts++;
            continue;
        }
        used[uk] = 1;
    }   
    if (uk > m) {
        writeWord("-1\n");
        return 0;
    }
    cnts = max(cnts, ob);
    writeInt(cnts, '\n');
    for (int i = 0; i < n; i++) {
        writeInt(ans[i], ' ');
    }
    writeChar('\n');
    return 0;
}