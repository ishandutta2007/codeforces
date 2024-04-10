#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define int ll

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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

template<typename T, typename Comparator>
struct rmq {
    static const Comparator comparator;
	vector<T> v; int n;
	static constexpr int b = 30; // block size
	vector<int> mask, t; // mask and sparse table

	__attribute__((always_inline)) int lsb(int x) const {
		return x & -x;
	}

	__attribute__((always_inline)) int msb_index(int x) const {
		return __builtin_clz(1)-__builtin_clz(x);
	}

	__attribute__((always_inline)) int op(int i, int j) const {
        return comparator(v[i], v[j]) ? i : j;
	}

	int small(int r, int sz = b) const {
		int dist_from_r = msb_index(mask[r] & ((1<<sz)-1));
		return r - dist_from_r;
	}

	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		int curr_mask = 0;
		for (int i = 0; i < n; i++) {
			curr_mask = (curr_mask<<1) & ((1<<b)-1);
			while (curr_mask > 0 && op(i, i - msb_index(lsb(curr_mask))) == i) {
				curr_mask ^= lsb(curr_mask);
			}
			curr_mask |= 1;
			mask[i] = curr_mask;
		}
		for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}

	T query_index(int l, int r) const {
	    assert(l <= r);
		// query too small
		if (r-l+1 <= b) return small(r, r-l+1);
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb_index(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return ans;
	}

	T query(int l, int r) const {
		return v[query_index(l, r)];
	}
};

template<typename T>
using min_rmq = rmq<T, less<T>>;

template<typename T>
using max_rmq = rmq<T, greater<T>>;

int32_t main() {
    fastio;
    int n, q, k; cin >> n >> q >> k;
    vi a(n); rep(i, n) cin >> a[i];
    min_rmq<int> rmq(a);
    vvi t(k);
    rep(i, k) {
        for(int j = i + k; j < n; j += k) {
            t[i].pb(rmq.query(j - k, j));
        }
    }
    vvi dp(k);
    auto calc_dp = [](const vi& a, vi& dp) {
        int n = a.size(); dp.resize(n);
        stack<int> st;
        for(int i = n - 1; ~i; i--) {
            while(!st.empty() && a[st.top()] >= a[i]) st.pop();
            int nxt = (st.empty() ? n : st.top());
            st.push(i);
            dp[i] = a[i] * (nxt - i) + (nxt == n ? 0 : dp[nxt]);
        }
    };
    rep(i, k) calc_dp(t[i], dp[i]);
    vector<min_rmq<int>> rmq_t;
    rep(i, k) rmq_t.eb(t[i]);
    while(q--) {
        int l, r; cin >> l >> r; --l, --r;
        int ans = a[l];
        int id = l % k, lf = l / k, rg = (r - id) / k - 1;
        if(lf <= rg) {
            int i = rmq_t[id].query_index(lf, rg);
            ans += dp[id][lf] - dp[id][i] + (rg - i + 1) * t[id][i];
        }
        cout << ans << endl;
    }
}