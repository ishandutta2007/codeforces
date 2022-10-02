#include <bits/stdc++.h>
    /** Interface */

inline int readChar();
template <class T = int> inline T getInt(); 

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
inline T getInt() {
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

using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
 
const int mod = int(1e9) + 7, pq = 2, szz = 65536, ma = szz, szz1 = 8;
 
int get_int() {
	int k;
	scanf("%d", &k);
	re k;
}

ll n, ans, col[400000], is[400000];
vector<int> e[400000], nu;

void dfs(int nu, int pr) {
	if (col[nu] == 0) is[nu] = 1;
	for (int v : e[nu]) {
		if (v != pr) {
			dfs(v, nu);
			is[nu] |= is[v];
		}
	}
}
vector<int> numm;

void dfs1(int nu, int pr) {
	numm.push_back(nu + 1);
	if (nu != 0) col[nu] ^= 1;
	for (int v : e[nu])
		if (v != pr && is[v]) {
			dfs1(v, nu);
			numm.push_back(nu + 1);
			col[nu] ^= 1;
		}
	if (col[nu] == 0) {
		if (nu != 0) {
			numm.push_back(pr + 1);
			numm.push_back(nu + 1);
			col[pr] ^= 1;
			col[nu] ^= 1; 
		}
		else
			numm.pop_back();
	}
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	int cnt = 0;
	forn (i, n) {
		cin >> col[i];
		if (col[i] == -1) {
			col[i] = 0;
			cnt++;
		}
	}
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	if (cnt == 1 && col[0] == 0) {
		vector<int> a;
		forn (i, 2)
			cout << 1 << " " << e[0][0] + 1 << " ";
		re 0;
	}
	dfs(0, -1);
	if (!is[0]) {
		cout << 1;
		re 0;
	}
	dfs1(0, -1);
	forn (i, sz(numm))
		cout << numm[i] << " ";
	re 0;
}