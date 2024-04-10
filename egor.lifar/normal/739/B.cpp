#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


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


const int MAXN = 228228;
const int INF = (int)1e9;


int n;
int a[MAXN];
vector<pair<int, int> > v[MAXN];
int cnt[MAXN];


void dfs(int u, multiset<long long> &s, long long &mod) {
	for (auto h: v[u]) {
		multiset<long long> s1;
		long long mod1 = 0;
		dfs(h.first, s1, mod1);
		mod1 += h.second;
		if (sz(s) < sz(s1)) {
			swap(s, s1);
			swap(mod, mod1);
		}
		for (auto x: s1) {
			s.insert(x + mod1 - mod);
		}
	}
	while (!s.empty()) {
		auto it = s.rbegin();
		long long x = *it;
		if (x + mod > 0) {
			s.erase(x);
		} else {
			break;
		}
	}
	cnt[u] = sz(s);
	s.insert(-a[u] - mod);
}


int main() {
	n = readInt();
	for (int i = 0; i < n; i++) {
		a[i] = readInt();
	}
	for (int i = 1; i < n; i++) {
		int p = readInt(), s = readInt();
		p--;
		v[p].push_back(make_pair(i, s));
	}
	long long mod = 0;
	multiset<long long> s;
	dfs(0, s, mod);
	for (int i = 0; i < n; i++) {
		writeInt(cnt[i], ' ');
	}
	writeChar('\n');
	return 0;
}