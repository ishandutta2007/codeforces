// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
#define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
#define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
std::mt19937 rnd(238);
#else
std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int MOD = (int)1e9 + 7;

int add(int a, int b, int mod = MOD) {
  if (a + b >= mod) {
    return a + b - mod;
  }
  return a + b;
}

int sub(int a, int b, int mod = MOD) {
  if (a - b < 0) {
    return a - b + mod;
  }
  return a - b;
}

int mul(int a, int b, int mod = MOD) {
  return (int)(1ll * a * b % mod);
}

int binpow(int a, int n, int mod = MOD) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return binpow(mul(a, a, mod), n / 2, mod);
  } else {
    return mul(binpow(a, n - 1, mod), a, mod);
  }
}

int rev(int a, int mod = MOD) {
  return binpow(a, mod - 2, mod);
}

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 1 << 17;

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

int dp[7];
int pref[8];

int calc(ll m) {
  dp[0] = 1;
  for (int i = 1; i < 8; i++) {
    pref[i] = 1;
  }

  for (int p = 59; p >= 0; p--) {
    int x = (int) ((m >> p) & 1);
    for (int i = 0; i < 7; i++) {
      dp[i] = sub(pref[((i - x + 7) >> 1) + 1], pref[(i - x + 1) >> 1]);
    }
    for (int i = 0; i < 7; i++) {
      pref[i + 1] = add(pref[i], dp[i]);
    }
  }
  return dp[0];
}

void run() {
  int t = readInt<int>();

  while (t--) {
    ll m = readInt<ll>();
    writeInt(calc(m), '\n');
  }
}

int main(void) {
//   freopen("in", "rt", stdin);
//   freopen(NAME".out", "w", stdout);

  auto start = std::chrono::high_resolution_clock::now();
  run();
  auto end = std::chrono::high_resolution_clock::now();

#ifdef PERVEEVM_LOCAL
  std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
#endif

  return 0;
}