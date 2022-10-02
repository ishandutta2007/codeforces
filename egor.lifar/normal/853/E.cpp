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
const int MAXN = 100228;
const int MAXK = 10;
const double eps = 1e-7;
#define lower(x) (upper_bound(c + 1, c + cn + 1, x) - c - 1)


struct point {
	int x, y;
};


point v[MAXK];


struct query { 
	double a;
	int x, y, z;
};


query w[MAXN * 2];


bool compv(const point &a, const point &b){
	return atan2(a.y, a.x) < atan2(b.y, b.x);
}


bool compw(const query &a,const query &b) {
	return (fabs(a.a - b.a) < eps ? a.z < b.z: a.a < b.a);
}


int a[MAXN], c[MAXN];
int cn, sx, sy;
int px[MAXN], py[MAXN], t[MAXN];
long long ans[MAXN], s[MAXN];


inline void add(int k, int x) {
	for (; k <= MAXN; k += k & -k) {
		s[k] += x;
	}
}


int x[MAXN], y[MAXN];


long long sum(int k) {
	long long res = 0;
	for(; k; k -= k & -k) {
		res += s[k];
	}
	return res;
}


int main() {
	int k = readInt(), n = readInt(), q=readInt();
	for (int i = 1; i <= k; i++) {
		v[i].x = readInt();v[i].y=readInt();
		if (v[i].x < 0) {
			v[i].x = -v[i].x;
			v[i].y = -v[i].y;
		}
		if (!v[i].x && v[i].y < 0) {
			v[i].y = -v[i].y;
		}
		sx += v[i].x, sy += v[i].y;
	}
	sort(v + 1, v + k + 1, compv);
	for (int i = 1; i <= n; i++) {
		c[i] = x[i] = readInt(), y[i] = readInt(), a[i] = readInt();
	}
	sort(c + 1, c + n + 1);
    cn = unique(c + 1, c + n + 1) - c - 1;
	for (int i = 1; i <= q; i++) {
		px[i] = readInt(), py[i] = readInt(), t[i] = readInt();
		px[i] -= sx * t[i];
		py[i] -= sy * t[i];
		t[i] <<= 1;
	}
	for (int i = 1; i <= k; i++)  {
		if (!v[i].x) {
			for (int j = 1; j <= q; j++) {
				py[j] += v[i].y * t[j];
			}
			continue;
		}
		for (int j = 1; j <= n; j++) {
			w[j] = (query){y[j] - (double)x[j] * v[i].y / v[i].x, x[j], a[j], 0};
		}
		for (int j = 1; j <= q; j++) {
			w[n + j] = (query){py[j] - (double)px[j] * v[i].y / v[i].x, px[j], px[j] + v[i].x * t[j], -j},
			px[j] += v[i].x * t[j];
			py[j] += v[i].y * t[j];
		}
		sort(w + 1, w + n + q + 1, compw);
		memset(s, 0, sizeof(s));
		for (int j = 1; j <= n + q; j++) {
			if (w[j].z) {
				ans[-w[j].z] -= sum(lower(w[j].y)) - sum(lower(w[j].x - (i < 2)));
			} else {
				add(lower(w[j].x), w[j].y);
			}
		}
	}
	for (int i = 1; i <= k; i++) {
		if (!v[i].x) {
			break;
		}
		for (int j = 1; j <= n; j++) {
			w[j] = (query){y[j] - (double)x[j] * v[i].y / v[i].x, x[j], a[j], 0};
		}
		for (int j = 1; j <= q; j++) {
			w[n + j] = (query){py[j] - (double)px[j] * v[i].y / v[i].x, px[j] - v[i].x * t[j], px[j], j},
			px[j] -= v[i].x * t[j], py[j] -= v[i].y * t[j];
		}
		sort(w + 1, w + n + q + 1, compw);
		memset(s, 0, sizeof(s));
		for (int j = 1; j <= n + q; j++) {
			if (w[j].z) {
				ans[w[j].z] += sum(lower(w[j].y - (i > 1))) - sum(lower(w[j].x - 1));
			} else {
				add(lower(w[j].x), w[j].y);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		writeInt(ans[i], '\n');
	}
	return 0;
}