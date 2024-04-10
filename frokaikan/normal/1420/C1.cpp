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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	u32 T;
	std::cin >> T;
	while (T--) {
		u32 n, q;
		std::cin >> n >> q;
		std::vector<u32> a(n + 2);
		for (u32 i = 1; i <= n; ++i) {
			std::cin >> a[i];
		}
		u64 ans = 0;
		for (u32 i = 1; i <= n; ++i) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				ans += a[i];
			}
			if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
				ans -= a[i];
			}
		}
		auto sub = [&] (u32 i) -> void {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				ans -= a[i];
			}
			if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
				ans += a[i];
			}
		};
		auto add = [&] (u32 i) -> void {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				ans += a[i];
			}
			if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
				ans -= a[i];
			}
		};
		std::cout << ans << '\n';
		while (q--) {
			u32 l, r;
			std::cin >> l >> r;
			set<u32> p;
			p.insert(l - 1);
			p.insert(l);
			p.insert(l + 1);
			p.insert(r - 1);
			p.insert(r);
			p.insert(r + 1);
			p.erase(0);
			p.erase(n + 1);
			for (const auto& x : p) {
				sub(x);
			}
			std::swap(a[l], a[r]);
			for (const auto& x : p) {
				add(x);
			}
			std::cout << ans << '\n';
		}
	}
}