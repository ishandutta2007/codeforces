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

constexpr const u32 mod = 998244353U;
u32 add(u32 lhs, u32 rhs) {
	return lhs + rhs < mod ? lhs + rhs : lhs + rhs - mod;
}
u32 sub(u32 lhs, u32 rhs) {
	return lhs < rhs ? mod + lhs - rhs : lhs - rhs;
}
u32 mul(u32 lhs, u32 rhs) {
	return u64(lhs) * rhs % mod;
}

constexpr const u32 maxn = 300005U;

u32 inv[maxn], fac[maxn], fiv[maxn];

u32 C(u32 n, u32 k) {
	return n < k ? 0U : mul(fac[n], mul(fiv[k], fiv[n - k]));
}

std::vector<u32> L[maxn << 1], R[maxn << 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	inv[0] = inv[1] = fac[0] = fac[1] = fiv[0] = fiv[1] = 1;
	for (u32 i = 2; i != maxn; ++i) {
		inv[i] = mul(inv[mod % i], mod - mod / i);
		fac[i] = mul(fac[i - 1], i);
		fiv[i] = mul(fiv[i - 1], inv[i]);
	}
	u32 n, k;
	std::cin >> n >> k;
	std::vector<u32> l(n), r(n), num;
	for (u32 i = 0; i != n; ++i) {
		std::cin >> l[i] >> r[i];
		num.push_back(l[i]);
		num.push_back(r[i]);
	}
	std::sort(num.begin(), num.end());
	num.resize(std::unique(num.begin(), num.end()) - num.begin());
	for (u32 i = 0; i != n; ++i) {
		l[i] = std::lower_bound(num.begin(), num.end(), l[i]) - num.begin();
		r[i] = std::lower_bound(num.begin(), num.end(), r[i]) - num.begin();
		L[l[i]].push_back(i);
		R[r[i]].push_back(i);
	}
	u32 ans = 0, cnt = 0;
	for (u32 i = 0; i != num.size(); ++i) {
		for (const auto& j : L[i]) {
			++cnt;
		}
		for (const auto& j : R[i]) {
			--cnt;
			ans = add(ans, C(cnt, k - 1));
		}
	}
	std::cout << ans << std::endl;
}