#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

template<typename T>
struct FenwickTree {
    int n;
	vector<T> s;

	FenwickTree(int n): n(n), s(n) {}

	void update(int pos, const T& df) {
        for(; pos < n; pos |= pos + 1) s[pos] += df;
	}

	T query(int pos) const { //inclusive
        T res = T();
        for(++pos; pos > 0; pos &= pos - 1) res += s[pos - 1];
        return res;
	}

	T query(int l, int r) const { //inclusive
	    if(l > r) return T();
        return query(r) - query(l - 1);
	}

	int lower_bound(T sum) const {
        int pos = 0;
        for(int p = 1 << __lg(n); p; p >>= 1) {
            if (pos + p <= n && s[pos + p - 1] < sum) {
                pos += p;
                sum -= s[pos - 1];
            }
        }
        return pos;
	}
};

using FT = FenwickTree<int>;

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        int n = s.size();
        vi a(n), even, odd;
        rep(i, n) {
            char c = s[i];
            a[i] = (c == '(' || c == ')');
        }
        for(int i = 0; i + 1 < n; i += 2) even.pb(a[i] - a[i + 1]);
        for(int i = 1; i + 1 < n; i += 2) odd.pb(a[i] - a[i + 1]);
        FT f0(even.size()), f1(odd.size());
        rep(i, even.size()) f0.update(i, even[i]);
        rep(i, odd.size()) f1.update(i, odd[i]);
        int q; cin >> q;
        while(q--) {
            int l, r; cin >> l >> r;
            cout << abs((--l & 1 ? f1 : f0).query(l / 2, r / 2 - 1)) << endl;
        }
    }
}