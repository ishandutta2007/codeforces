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


int n, m, k;
int x, s;
const int MAXN = 200001;
int a[MAXN], b[MAXN];
vector<pair<int, int> > c;



int main() {
	n = readInt();
	m = readInt();
	k = readInt();
	x = readInt();
	s = readInt();
	a[0] = x;
	b[0] = 0;
	for (int i = 1; i <= m; i++) {
		a[i] = readInt();
	}
	for (int i = 1; i <= m; i++) {
		b[i] = readInt();
	}
	m++;
	c.resize(k + 1);
	c[0].first = 0;
	c[0].second = 0;
	for (int i = 1; i <= k; i++) {
		c[i].second = readInt();
	}
	for (int i = 1; i <= k; i++) {
		c[i].first = readInt();
	}
	k++;
	long long ans = (long long)4e18;
	for (int i = 0; i < m; i++) {
		if (b[i] > s) {
			continue;
		}
		int ost = s - b[i];
		auto it = upper_bound(all(c), make_pair(ost, 2000000001));
		int cnt = n;
		if (it != c.begin()) {
			it--;
			cnt -= it->second;
		}
		ans = min(ans, 1LL * cnt * a[i]);
	}
	cout << ans << endl;
	return 0;
}