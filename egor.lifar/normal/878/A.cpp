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
const int MAXN = 500001;


int n;
char c[MAXN];
int t[MAXN];
vector<int> need[3];


int main() {
    n = readInt();
    for (int i = 0; i < n; i++) {
        c[i] = readChar();
        t[i] = readInt();
    }
    for (int pos = 0; pos < 10; pos++) {
        int keks = 0;
        for (int k = 0; k < 2; k++) {
            int cur = k;
            for (int i = 0; i < n; i++) {
                int bit = (t[i] >> pos) & 1;
                if (c[i] == '^') {
                    cur ^= bit;
                } else if (c[i] == '|') {
                    cur |= bit;
                } else {
                    cur &= bit;
                }
            }
            keks <<= 1;
            keks += cur;
        }
        if (keks == 0) {
            need[0].push_back(pos);//and
        } else {
            if (keks == 2) {
                need[1].push_back(pos);//xor
            } else {
                if (keks == 3) {
                    need[2].push_back(pos);//or
                }
            }
        }
    }
    cout << 3 << endl;
    for (int it = 0; it < 3; it++) {
        int f = 0;
        if (it == 0) {
            f = 1023;
        }
        for (auto x: need[it]) {
            if (it == 0) {
                f ^= 1 << x;
            } else {
                f |= (1 << x);
            }
        }
        if (it == 0) {
            cout << "&" << ' ' << f << endl; 
        } else if (it == 1) {
            cout << "^" << ' ' << f << endl;
        } else {
            cout << "|" << ' ' << f << endl;
        }
    }
    return 0;
}