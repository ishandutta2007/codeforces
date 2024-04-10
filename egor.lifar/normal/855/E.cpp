/*
 






































 
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
#define y1 y1228   


int q;
bool was[65][1025][11];
long long res[65][1025][11];
long long cnts[11][65];
long long c[65][65];


long long gets(int len, int mask, int pos) {
    if (was[len][mask][pos]) {
        return res[len][mask][pos];
    }
    if (len == 0) {
        if (mask == 0) {
            return 1;
        } 
        return 0;
    }
    was[len][mask][pos] = true;
    for (int ns = 0; ns <= pos; ns++) {
        for (int i = 0; i <= len; i++) {
            cnts[ns][i] = 0;
        }
    }
    cnts[0][0] = 1;
    for (int ns = 0; ns < pos; ns++) {
        bool need = mask & (1 << ns);
        for (int i = 0; i <= len; i++) {
            if (!cnts[ns][i]) {
                continue;
            }
            for (int cnt = 0; cnt <= len - i; cnt++) {
                if (cnt % 2 != need) {
                    continue;
                }
                cnts[ns + 1][i + cnt] += cnts[ns][i] * c[len - i][cnt];
            }
        }
    }
    res[len][mask][pos] = cnts[pos][len];
    return cnts[pos][len];
}   


long long get(long long num, int b) {
    if (num == 0) {
        return 0;
    }
    string s;
  //  cout << num << endl;
    while (num > 0) {
        s += char('0' + num % b);
        num /= b;
    }
    reverse(all(s));
    //cout << s << endl;
    int cnt = 0;
    long long ans = 0;
    for (int len = 1; len <= sz(s) - 1; len++) {
        ans += gets(len, 0, b) - gets(len - 1, 1, b);
      //  cout << gets(len, 0, b) - gets(len - 1, 1, b) << endl;
    }
   // cout << ans << endl;
    for (int i = 0; i < sz(s); i++) {
        for (char a = '0'; a < s[i]; a++) {
            if (a == '0' && i == 0) {
                continue;
            }
            cnt ^= 1 << (a - '0');
            ans += gets(sz(s) - i - 1, cnt, b);
            cnt ^= 1 << (a - '0');
        }
        cnt ^= 1 << (s[i] - '0');
    }
   // cout << ans << endl;
   // cout << cnt << endl;
    if (cnt == 0) {
        ans++;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i <= 64; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                c[i][j] = 1;
            } else {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int b;
        long long l, r;
        cin >> b >> l >> r;
        cout << get(r, b) - get(l - 1, b) << '\n';
    }  
    return 0;
}