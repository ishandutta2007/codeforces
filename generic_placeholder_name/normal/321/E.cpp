#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

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

constexpr int N=4001;
int dp[2][N];
int a[N][N];
int cost[N][N];
constexpr int INF=1e9+7;

void calc_costs(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) a[i][j]+=a[i][j-1];
    }
    for(int i=0; i+2<=n; i++) {
        for(int j=0; j<=i; j++) cost[i][j]=INF;
        for(int j=i+2; j<=n; j++) {
            cost[i][j]=cost[i][j-1]+a[j][j-1]-a[j][i];
        }
    }
    //rep(i, n+1) rep(j, n+1) cout<<cost[i][j]<<" \n"[j==n];
}

void calc(int cur, int l, int r, int optl, int optr) {
    if(l>r) return;
    int prv=cur^1;
    int m=(l+r)/2;
    int mx=INF;
    int opt=-1;
    for(int k=optl; k<=min(m-1, optr); k++) {
        if(mx>dp[prv][k]+cost[k][m]) {
            mx=dp[prv][k]+cost[k][m];
            opt=k;
        }
    }
    assert(~opt);
    dp[cur][m]=mx;
    calc(cur, l, m-1, optl, opt);
    calc(cur, m+1, r, opt, optr);
}

int32_t main() {
    int n=readInt(), k=readInt();
    rep1(i, n) rep1(j, n) a[i][j]=readInt();
    calc_costs(n);
    rep1(i, n) dp[0][i]=INF;
    rep1(i, k) {
        memset(dp[i&1], 0, sizeof(dp[i&1]));
        calc(i&1, i, n, i-1, n);
    }
    writeInt(dp[k&1][n], '\n');
}