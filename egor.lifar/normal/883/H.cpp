/*
  !










*/
#pragma GCC optimize "-O3"
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
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const string FILENAME = "input";
typedef pair <int, int> point;



int n;
map<char, int> cnt;


int main() {
    ios::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //read(FILENAME);
    cin >> n;    
    string s;
    cin >> s;
    for (auto c: s) {
        cnt[c]++;
    }
    for (int step = n; step >= 1; step--) {
        if (n % step) {
            continue;
        }
        if (step & 1) {
            int t = n / step;
            vector<char> st;
            for (auto x: cnt) {
                char i = x.first;
                int tst = x.second;
                if (tst & 1) {
                    st.push_back(i);
                }
            }
            if (sz(st) > t || (t - sz(st)) & 1) {
                continue;
            }
            t -= sz(st);
            int f = t / 2;
            vector<char> g;
            for (auto x: cnt) {
                char i = x.first;
                int tst = x.second;
                if (tst & 1) {
                    tst--;
                }
                while (f >= 1 && tst >= 2) {
                    tst -= 2;
                    f--;
                    st.push_back(i);
                    st.push_back(i);
                }
                for (int j = 0; j < tst / 2; j++) {
                    g.push_back(i);
                }
            }
            assert(f == 0);
            cout << n / step << '\n';
            int uk = 0;
            for (int i = 0; i < n / step; i++) {
                for (int f = uk; f < uk + step / 2; f++) {
                    cout << g[f];
                }
                cout << st[i];
                for (int f = uk + step / 2 - 1; f >= uk; f--) {
                    cout << g[f];
                }
                cout << ' ';
                uk += step / 2;
            }
            cout << '\n';
            exit(0);
        } else {
            bool bad = false;
            for (auto x: cnt) {
                if (x.second & 1) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                cout << 1 << '\n';
                string ans;
                for (auto x: cnt) {
                    for (int j = 0; j < x.second / 2; j++) {
                        ans += x.first;
                    }
                }
                string ans1;
                for (auto x: cnt) {
                    for (int j = 0; j < x.second / 2; j++) {
                        ans1 += x.first;
                    }
                }
                reverse(all(ans1));
                cout << ans << ans1 << '\n';
                exit(0);
            }
        }
    }
}