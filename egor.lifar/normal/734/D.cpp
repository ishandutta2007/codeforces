#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <fstream>
#include <math.h>
#include <numeric>


using namespace std;
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

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()



struct point
{
	long long x, y;
	point(){}
	point(long long _x, long long _y) {
		x = _x;
		y = _y;
	}
};


point operator -(point a, point b) {
	return point(a.x - b.x, a.y - b.y);
}


long long vec(point a, point b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

int n;
const int MAXN = 500001;
point st;
map<pair<int, int>, vector<int> > m;
map<pair<int, int>, vector<int> > z;


int main() {
	n = readInt();
	st.x = readInt();
	st.y = readInt();
	for (int i = 0; i < n; i++) {
		char t = readChar();
		point k;
		k.x = readInt();
		k.y = readInt();
		k.x -= st.x;
		k.y -= st.y;
		if (abs(k.x) != 0 && abs(k.y) != 0 && abs(k.x) != abs(k.y)) {
			continue;
		}
		int fx = k.x;
		int fy = k.y;
		if (fx != 0) {
			fx /= abs(fx);
		}
		if (fy != 0) {
			fy /= abs(fy);
		}
		//cout << fx << ' ' << fy << endl;
		m[make_pair(fx, fy)].push_back(max(abs(k.x), abs(k.y)));
		if (fx == 0 || fy == 0) {
			if (t == 'R' || t == 'Q') {
				z[make_pair(fx, fy)].push_back(max(abs(k.x), abs(k.y)));
			}
		} else {
			if (t == 'B' || t == 'Q') {
				z[make_pair(fx, fy)].push_back(max(abs(k.x), abs(k.y)));
			}
		}
	}
	int c[3] = {1, 0, -1};
	int c1[3] = {1, 0, -1};
	for (auto x: c) {
		for (auto x1: c1) {
			sort(all(m[make_pair(x, x1)]));
			sort(all(z[make_pair(x, x1)]));
			if (!z[make_pair(x, x1)].empty()) {
				if (z[make_pair(x, x1)][0] == m[make_pair(x, x1)][0]) {
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}