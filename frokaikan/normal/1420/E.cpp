#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <decimal/decimal>
using namespace std;
using namespace __gnu_pbds;

#define rep(i, s, t) for (int i = s; i < int(t); ++i)

#define sc	scanf
#define pr	printf
#define ff	first
#define ss	second
#define mp	make_pair
#define pb	push_back
#define eb	emplace_back
#define range(c)	c.begin(), c.end()
#define lowbit(x)	((x) & -(x))
#define pop_count	__builtin_popcount
#define pop_count_64	__builtin_popcountll
#define tail_count	__builtin_ctz
#define tail_count_64	__builtin_ctzll
#define lead_count	__builtin_clz
#define lead_count_64	__builtin_clzll

#define TEMP template<typename
#define CONST(type) constexpr type const

TEMP... Ts> struct is_con { static CONST(bool) value = false; };
TEMP... Ts> struct is_con<vector<Ts...>> { static CONST(bool) value = true; };
TEMP... Ts> struct is_con<list<Ts...>> { static CONST(bool) value = true; };
TEMP... Ts> struct is_con<deque<Ts...>> { static CONST(bool) value = true; };
TEMP... Ts> struct is_con<set<Ts...>> { static CONST(bool) value = true; };
TEMP... Ts> struct is_con<unordered_set<Ts...>> { static CONST(bool) value = true; };
TEMP... Ts> struct is_con<map<Ts...>> { static CONST(bool) value = true; };
TEMP... Ts> struct is_con<unordered_map<Ts...>> { static CONST(bool) value = true; };

TEMP T1, typename T2> ostream& operator<<(ostream& os, pair<T1, T2> const& p) { return os << "<" << p.ff << "," << p.ss << ">"; }
TEMP T> typename enable_if<is_con<T>::value, ostream>::type& operator<<(ostream& os, T const& c) {
	os << "{";
	bool first = true;
	for (auto const& x : c) {
		if (first) first = false;
		else os << ",";
		os << " " << x;
	}
	return os << " }";
}

TEMP T, typename... Ts> void dbg(T h, Ts... t) { cerr << " " << h; dbg<Ts...>(t...); }
template<> void dbg<int>(int x) { cerr << endl; }

#ifdef LOCAL
#define debug(...) cerr << "[ "#__VA_ARGS__" ] :", dbg(__VA_ARGS__, 0)
#else
#define debug(...) 0
#endif

TEMP T, typename U> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
TEMP T> using ordered_set = ordered_map<T, null_type>;

typedef long long i64;
typedef decimal::decimal128 i99;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef long double f80;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<i64> vl;

TEMP T> T& minn(T& lhs, T const& rhs) { return lhs = min(lhs, rhs); }
TEMP T> T& maxx(T& lhs, T const& rhs) { return lhs = max(lhs, rhs); }

u32 C2(u32 x) {
	return x * (x - 1) / 2;
}

u32 dis(u32 x, u32 y) {
	return x < y ? y - x : x - y;
}

int dp[81][81][3200], a[82], ans[3200];
u32 p[81];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	u32 n;
	std::cin >> n;
	u32 m = C2(n);
	for (u32 i = 0; i <= n; ++i) {
		for (u32 j = 0; j <= n; ++j) {
			for (u32 k = 0; k <= m; ++k) {
				dp[i][j][k] = -(1 << 30);
			}
		}
	}
	u32 cnt[2] = { 0 };
	for (u32 i = 1; i <= n; ++i) {
		std::cin >> a[i];
		++cnt[a[i]];
		if (a[i]) {
			p[cnt[1]] = i;
		}
	}
	for (u32 j = 1; j + cnt[1] <= n + 1U; ++j) {
		dp[1][j][u32(dis(j, p[1]))] = (j - 1) * (n - j - cnt[1] + 1);
	}
	for (u32 i = 2; i <= cnt[1]; ++i) {
		for (u32 j = i; j + cnt[1] <= n + i; ++j) {
			u32 move = dis(j, p[i]);
			for (u32 jj = i - 1; jj != j; ++jj) {
				for (u32 k = 0; k <= m; ++k) {
					if (dp[i - 1][jj][k] < 0) {
						continue;
					}
					maxx(dp[i][j][k + move], dp[i - 1][jj][k] + int(j - jj - 1) * int(n - j - cnt[1] + i));
				}
			}
		}
	}
	for (u32 j = 1; j <= n; ++j) {
		for (u32 k = 0; k <= m; ++k) {
			maxx(ans[k], dp[cnt[1]][j][k]);
		}
	}
	for (u32 i = 1; i <= m; ++i) {
		maxx(ans[i], ans[i - 1]);
	}
	for (u32 i = 0; i <= m; ++i) {
		std::cout << ans[i] << " \n"[i == m];
	}
}