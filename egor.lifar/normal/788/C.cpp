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
const int MAXN = 100001;


int n, k;
vector<int> v;
int can[2 * MAXN + 100];


int main() {
	n = readInt(), k = readInt();
	v.resize(k);
	for (int i = 0; i < k; i++) {
		v[i] = readInt();
	}
	sort(all(v));
	v.resize(distance(v.begin(), unique(all(v))));
	k = sz(v);
	queue<int> q;
	for (int i = 0; i < k; i++) {
		v[i] -= n;
		if (v[i] == 0) {
			writeInt(1, '\n');
			return 0;
		}
		q.push(v[i] + MAXN);
		can[v[i] + MAXN] = 1;
	}
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		a -= MAXN;
		for (int i = 0; i < k; i++) {
			if (a + v[i] >= -MAXN && a + v[i] <= MAXN && !can[a + v[i] + MAXN]) {
				q.push(a + v[i] + MAXN);
				can[a + v[i] + MAXN] = can[a + MAXN] + 1;
			}
		}
	}
	if (!can[MAXN]) {
		writeInt(-1, '\n');
		return 0;
	}
	writeInt(can[MAXN], '\n');
	return 0;
}
//ax / 1000 + by / 1000 = (ax + by) / 1000
//(ax + by) / 1000(x + y)
//(ax + by) / (x + y) = n
//ax + by = n * (x + y)
//