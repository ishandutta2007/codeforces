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

typedef std::pair<u32, u32> puu;

std::vector<puu> f;

std::vector<u32> ff;

void dfs(u32 i, u32 x) {
	if (i == f.size()) {
		ff.push_back(x);
		return;
	}
	dfs(i + 1, x);
	for (u32 j = 0; j != f[i].ss; ++j) {
		dfs(i + 1, x *= f[i].ff);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	constexpr const u32 maxn = 32768U;
	std::vector<bool> np(maxn);
	std::vector<u32> prime;
	for (u32 i = 2; i != maxn; ++i) {
		if (!np[i]) {
			prime.push_back(i);
		}
		for (const auto& p : prime) {
			if (i * p >> 15) {
				break;
			}
			np[i * p] = true;
			if (i % p == 0U) {
				break;
			}
		}
	}
	u32 T;
	std::cin >> T;
	while (T--) {
		u32 n;
		std::cin >> n;
		f.resize(0);
		for (const auto& p : prime) {
			if (n % p == 0U) {
				f.emplace_back(p, 1);
				for (n /= p; n % p == 0U; n /= p) {
					++f.back().ss;
				}
			}
			if (p * p > n) {
				break;
			}
		}
		if (n != 1U) {
			f.emplace_back(n, 1);
		}
		debug(f);
		std::vector<u32> circle;
		u32 ans = 0;
		if (f.size() == 1U) {
			circle.push_back(f[0].ff);
			for (u32 i = 1; i != f[0].ss; ++i) {
				circle.push_back(circle.back() * f[0].ff);
			}
		}
		else if (f.size() == 2U) {
			if (f[0].ss == 1U && f[1].ss == 1U) {
				ans = 1;
				circle.push_back(f[0].ff);
				circle.push_back(f[1].ff);
				circle.push_back(f[0].ff * f[1].ff);
			}
			else {
				u32 x = 1;
				for (u32 i = 0; i != f[0].ss; ++i) {
					circle.push_back(x *= f[0].ff);
				}
				circle.push_back(f[0].ff * f[1].ff);
				x = 1;
				for (u32 i = 0; i != f[1].ss; ++i) {
					circle.push_back(x *= f[1].ff);
				}
				x = 1;
				for (u32 i = 0; i != f[0].ss; ++i) {
					x *= f[0].ff;
					u32 y = x;
					for (u32 j = 0; j != f[1].ss; ++j) {
						y *= f[1].ff;
						if (i || j) {
							circle.push_back(y);
						}
					}
				}
			}
		}
		else {
			ff.resize(0);
			dfs(0, 1);
			std::vector<std::vector<u32>> wait(f.size());
			for (const auto& x : ff) {
				for (u32 i = 0; i != f.size(); ++i) {
					if (x % f[i].ff == 0U) {
						if (x != f[i].ff && (i + 1U == f.size() || x != f[i].ff * f[i + 1].ff) && (i || x != f[0].ff * f.back().ff)) {
							wait[i].push_back(x);
						}
						break;
					}
				}
			}
			for (u32 i = 0; i != f.size(); ++i) {
				circle.push_back(f[i].ff);
				for (const auto& x : wait[i]) {
					circle.push_back(x);
				}
				circle.push_back(f[i].ff * f[(i + 1U) % f.size()].ff);
			}
		}
		for (u32 i = 0; i != circle.size(); ++i) {
			std::cout << circle[i] << " \n"[i + 1U == circle.size()];
		}
		std::cout << ans << std::endl;
	}
}