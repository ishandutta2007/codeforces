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
  
  
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define y2 y2228


struct Treap {
    int x, y, sz, add;
    Treap *l, *r;
    Treap(int x) : x(x), y(rand()), sz(1), add(0), l(NULL), r(NULL) {}
} *t = NULL;



void push(Treap *&v) {
    if (!v || v -> add == 0) {
        return;
    }
    v -> x += v -> add;
    if (v -> l) {
        v -> l -> add += v -> add;
    }
    if (v -> r) {
        v -> r -> add += v -> add;
    }
    v -> add = 0;
}


inline void calc(Treap *&v) {
    if (!v) {
        return;
    }
    v -> sz = 1;
    if (v -> l) {
        v -> sz += v -> l -> sz;
    }
    if (v -> r) {
        v -> sz += v -> r -> sz;
    }
}


Treap *merge(Treap *l, Treap *r) {
    push(l), push(r);
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    if (l -> y > r -> y) {
        l -> r = merge(l -> r, r);
        calc(l);
        return l;
    } else {
        r -> l = merge(l, r -> l);
        calc(r);
        return r;
    }
}


inline void split(Treap *v, Treap *&l, Treap *&r, int x) {
    push(v);
    if (!v) {
        l = r = NULL;
        return;
    }
    if (v -> x < x) {
        l = v;
        split(l -> r, l -> r, r, x);
        calc(l);
    } else {
        r = v;
        split(r -> l, l, r -> l, x);
        calc(r);
    }
}


inline int getMini(Treap *v) {
    push(v);
    if (!v) {
        return 0;
    }
    if (v -> l) {
        return getMini(v -> l);
    }
    return v -> x;
}


inline void deleteFirstElement(Treap *&v) {
    int x = getMini(v);
    Treap *L, *R;
    L = R = NULL;
    split(v, L, R, x + 1);
    v = R;
}


inline void apply(int x, int y) {
    Treap *L, *Mid, *R;
    L = Mid = R = NULL;
    split(t, Mid, R, y);
    split(Mid, L, Mid, x);
    deleteFirstElement(R);
    if (Mid) {
        Mid -> add++;
        push(Mid);
    }
    Mid = merge(new Treap(x), Mid);
    t = merge(L, merge(Mid, R));
}


int main() {
    int n = readInt();
    t = new Treap(0);
    for (int i = 1; i <= n; i++) {
        int l = readInt(), r = readInt();
        apply(l, r);
    }
    int ans = 0;
    if (t) {
        ans = t -> sz - 1;
    }
    writeInt(ans, '\n');
    return 0;
}