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


inline long long readLong() {
    int s = 1, c = readChar();
    long long x = 0;
    if (c == '-') {
        s = -1, c = getChar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + c - '0', c = getChar();
    }
    return s == 1 ? x : -x;
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
const int MAXN = 100228;


int n, par[MAXN], type[MAXN], depth[MAXN], numObject[MAXN];
int timer, timeIn[MAXN], timeOut[MAXN];
int minpart[MAXN], minpar[MAXN];
vector<int> a[MAXN];


void dfs(int x) {
    timeIn[x] = timer++;
    for (auto y: a[x]) {
        depth[y] = depth[x] + 1;
        numObject[y] = numObject[x] + 1 - type[y];
        dfs(y);
    }
    timeOut[x] = timer++;
}


int get(int x, int d[]) {
    return d[x] == x ? x: d[x] = get(d[x], d);
}


int isChildren(int x, int y) {
    return timeIn[y] <= timeIn[x] && timeOut[x] <= timeOut[y];
}


int isSubObject(int x, int y) {
    return isChildren(x, y) && depth[x] - depth[y] == numObject[x] - numObject[y];
}


int isSubPart(int x, int y) {
    return isChildren(x, y) && numObject[x] == numObject[y];
}


int main() {
    n = readInt();
    for (int i = 1; i <= n; i++) {
        par[i] = readInt(), type[i] = readInt();
        a[max(0, par[i])].push_back(i);
        minpar[i] = !type[i] ? par[i] : i;
        minpart[i] = type[i] == 1 ? par[i] : i;
    }
    dfs(0);
    int q = readInt();
    for (int it = 0; it < q; it++) {
        int t = readInt(), x = readInt(), y = readInt();
        string ans = "NO";
        if (t == 1) {
            if (isSubObject(y, x) && x != y) {
                ans = "YES";
            }
        } else {
            int parobj = get(x, minpar);
            int parpart = get(y, minpart);
            if (isSubObject(x, parpart) && parpart != y || isSubPart(y, parobj) && parobj != y) {
                ans = "YES";
            }
        }
        if (ans == "NO") {
            writeWord("NO\n");
        } else {
            writeWord("YES\n");
        }
    }
    return 0;
}