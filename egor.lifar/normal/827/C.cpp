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


string s;
int n;
int ss = 1;
int cnt[270000][11][10][4];


inline int getInd(char c) {
	if (c == 'A') {
		return 0;
	}
	if (c == 'T') {
		return 1;
	}
	if (c == 'G') {
		return 2;
	}
	return 3;
}


inline void change(int i, int id, int ts) {
	memset(cnt[i], 0, sizeof(cnt[i]));
	for (int j = 1; j <= 10; j++) {
		cnt[i][j][id % j][ts] = 1;
	}
	//cout << id % 4 << ' ' << ts << endl;
	while (i / 2 > 0) {
		i = i / 2;
		for (int j = 1; j <= 10; j++) {
			for (int k = 0; k < j; k++) {
				for (int t = 0; t < 4; t++) {
					cnt[i][j][k][t] = cnt[(i << 1)][j][k][t] + cnt[(i << 1) + 1][j][k][t];
				}
			}
		}
	}
}


int cnts[11][4];


void rmq(int v, int vl, int vr, int l, int r, int mod) {
	if (vl > r || vr < l) {
		return;
	}
	if (l <= vl && vr <= r) {
		for (int k = 0; k < mod; k++) {
			for (int t = 0; t < 4; t++) {
				cnts[k][t] += cnt[v][mod][k][t];
			}
		}
		return;
	}
	int vn = v << 1;
	int vm = (vl + vr) >> 1;
	rmq(vn, vl, vm, l, r, mod);
	rmq(vn + 1, vm + 1, vr, l, r, mod);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	n = sz(s);
	while (ss <= n) {
		ss <<= 1;
	}
	for (int i = 0; i < n; i++) {
		change(ss + i, i, getInd(s[i]));
	}
	//cout << cnt[1][4][3][3] << endl;
	int q;
	cin >> q;
	for (int it = 0; it < q; it++) {
		int type;
		cin >> type;
		if (type == 1) {
			int i;
			char c;
			cin >> i >> c;
			i--;
			change(ss + i, i, getInd(c));
		} else {
			int l, r;
			string e;
			cin >> l >> r >> e;
			for (int i = 0; i < sz(e); i++) {
				for (int t = 0; t < 4; t++) {
					cnts[i][t] = 0;
				}
			}
			rmq(1, 1, ss, l, r, sz(e));
			int ans = 0;
			for (int i = 0; i < sz(e); i++) {
				ans += cnts[(i + l - 1) % sz(e)][getInd(e[i])];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}