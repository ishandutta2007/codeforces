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
 
 
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define left _left
#define right _right
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()


int pow(int a, int b, int p) {
    int ans = 1;
    for (; b; b >>= 1, a = (a * 1LL * a) % p) {
        if (b & 1) {
            ans = (ans * 1LL * a) % p;  
        }
    }
    return ans;
}


vector<int> divs;
vector<bool> have;


int getOrd(int a, int p) {
    for (int i = 0; i < sz(divs); i++) {
        if (pow(a, divs[i], p) == 1) {
            return divs[i];
        }
    }
    return -1;
}


int main(){
    int n = readInt(), m = readInt(), p = readInt();
    for (int i = 1; i * i <= p - 1; i++) {
        if ((p - 1) % i == 0){
            divs.push_back(i);
            if (i != (p - 1) / i) {
                divs.push_back((p - 1) / i);
            }
        }
    }
    sort(all(divs));
    have.resize(sz(divs));
    for (int i = 0; i < n; i++) {
        int a = readInt();
        a = getOrd(a, p);
        have[find(all(divs), a) - divs.begin()] = 1;
    }
    vector<int> ords;
    for (int i = 0; i < sz(divs); i++) {
        if (have[i]) {
            ords.push_back((p - 1) / divs[i]);
        }
    }
    int g = p - 1;
    for (int i = 0; i < m; i++) {
        int b = readInt();
        g = __gcd(g, b);
    }
    for (int i = 0; i < sz(ords); i++) {
        ords[i] = ords[i] * __gcd(g, (p - 1) / ords[i]);
    }
    sort(all(ords));
    ords.erase(unique(all(ords)), ords.end());
    have = vector<bool>(n, 0);
    vector<int> cnt(sz(divs));
    int ans = 0;
    for (int i = sz(divs) - 1; i >= 0; i--) {
        cnt[i] = (p - 1) / divs[i];
        for (int j = i + 1; j < sz(divs); j++) {
            if (divs[j] % divs[i] == 0) {
                cnt[i] -= cnt[j];
            }
        }
        for (int j = 0; j < sz(ords); j++) {
            if (divs[i] % ords[j] == 0) {
                ans += cnt[i];
                break;
            }                       
        }
    }
    writeInt(ans, '\n');      
    return 0;
}