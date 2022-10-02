// ,   !!!
//  !!!!!!!
//     !!!!
//    ,   !!!!!
//ICM ACPC
//  Y!!   !!!
#pragma GCC optimize "-oFast"
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
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MOD = 95542721;
const int MAGIC = 48;
const int MAXN = 100000;


struct tree{
    int add, l, r;
    int num[MAGIC];
};  


int ss;
int a[MAXN + 228], tmp[MAGIC + 100];
tree rmq[3 * MAXN];


inline int calc(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (1LL * ans * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return ans;
}


inline void norm(int &a) {
    if (a >= MOD) {
        a -= MOD;
    }
}


inline void push(int v) {
    if (rmq[v].add == 0) {
        return;
    }
    for (int i = 0; i < MAGIC; i++) {
        int ni = (i - rmq[v].add) % MAGIC;
        if (ni < 0) {
            ni += MAGIC;
        }
        tmp[ni] = rmq[v].num[i];
    }
    for(int i = 0; i < MAGIC; i++){
        rmq[v].num[i] = tmp[i];
    }
    if (v < ss) {
        rmq[(v << 1)].add += rmq[v].add;
        rmq[(v << 1) + 1].add += rmq[v].add;
    }
    rmq[v].add = 0;
}


inline void calc(int v){
    for (int i = 0; i < MAGIC; i++) {
        rmq[v].num[i] = rmq[(v << 1)].num[i] + rmq[(v << 1) + 1].num[i];
        norm(rmq[v].num[i]);
    }
}


void update(int v, int l, int r) {
    push(v);
    if( rmq[v].l > r || rmq[v].r < l || l > r) {
        return;
    }
    if (rmq[v].l >= l && rmq[v].r <= r) {
        rmq[v].add++;
        push(v);
        return;
    }
    update((v << 1), l, r);
    update((v << 1) + 1, l, r);
    calc(v);
}


int get(int v, int l, int r) {
    push(v);
    if (rmq[v].l > r || rmq[v].r < l || l > r){ 
        return 0;
    }
    if (rmq[v].l >= l && rmq[v].r <= r) {
        return rmq[v].num[0];
    }
    int ans = get((v << 1), l, r) + get((v << 1) + 1, l, r);
    norm(ans);
    return ans;
}


int main(){
    int n = readInt();
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        a[i] %= MOD;
    }
    ss = 1;
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 0; i < ss; i++) {
        rmq[i + ss].l = rmq[i + ss].r = i;
    }
    for (int i = 0; i < n; i++) {
        int uk = a[i];
        for (int j = 0; j < MAGIC; j++) {
            rmq[i + ss].num[j] = uk;
            uk = calc(uk, 3);
        }
    }
    for (int i = ss - 1; i > 0; i--) {
        rmq[i].l = rmq[(i << 1)].l;
        rmq[i].r = rmq[(i << 1) + 1].r;
        calc(i);
    }
    int m = readInt();
    for (int i = 0; i < m; i++) {
        int t = readInt(), l = readInt(), r = readInt();
        l--, r--;
        if (t == 1) {
            writeInt(get(1, l, r), '\n');
            continue;
        }
        update(1, l, r);
    }
    return 0;
}