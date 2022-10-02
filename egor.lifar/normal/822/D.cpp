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
#define y1 y1228
const int MAXN = 5000001;
const int Mod = 1000000007;


int t, l, r;
vector<int> pr;
int lp[MAXN];
int divizor = 1;
vector<pair<int, int> > st;
long long dp[MAXN];
//int curs;
//int opt;


// void getDivs(int i) {
//     if (i == sz(st)) {
//         chkmin(dp[curs], 1LL * curs * (divizor - 1) / 2LL + dp[curs / divizor]);
//         if (dp[curs] ==  1LL * curs * (divizor - 1) / 2LL + dp[curs / divizor]) {
//             opt = divizor;
//         }
//         return;
//     }
//     int cur = 1;
//     for (int j = 0; j <= st[i].second; j++) {
//         divizor *= cur;
//         getDivs(i + 1);
//         divizor /= cur;
//         if (j == st[i].second) {
//             break;
//         }
//         cur *= st[i].first;
//     }
// }


int main() {
    t = readInt(), l = readInt(), r = readInt();
    for (int i = 2; i <= r; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < sz(pr) && pr[j] <= lp[i] && 1LL * i * pr[j] <= r; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
    dp[1] = 0;
    int tp = 1;
    int ans = 0;
    for (int i = 2; i <= r; i++) {
       // st.clear();
        // int f = i;
        // while (f > 1) {
        //     int s = lp[f];
        //     int cnt = 0;
        //     while (f % s == 0) { 
        //         cnt++;
        //         f /= s;
        //     }
        //     st.push_back(make_pair(s, cnt));
        // }
       // curs = i;
        dp[i] = 2e18;
        chkmin(dp[i], 1LL * i * (lp[i] - 1) / 2LL + dp[i / lp[i]]);
      //  getDivs(0);
        if (i >= l) {
            int dps = dp[i] % Mod;
            ans += (1LL * tp * dps) % Mod;
            if (ans >= Mod) {
                ans -= Mod;
            }
           // writeInt(dp[i], '\n');
            tp = (1LL * tp * t) % Mod;
        }
    }
    writeInt(ans, '\n');
    return 0;               
}