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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

//O(n) rmq
template<typename T, typename Comparator>
struct rmq {
	vector<T> v; int n;
	static constexpr int b = 30; // block size
	vector<int> mask, t; // mask and sparse table

	__attribute__((always_inline)) int lsb(int x) {
		return x & -x;
	}

	__attribute__((always_inline)) int msb_index(int x) {
		return __builtin_clz(1)-__builtin_clz(x);
	}

	__attribute__((always_inline)) int op(int i, int j) {
        return Comparator{}(v[i], v[j]) ? i : j;
	}

	int small(int r, int sz = b) {
		int dist_from_r = msb_index(mask[r] & ((1<<sz)-1));
		return r - dist_from_r;
	}
	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		int curr_mask = 0;
		for (int i = 0; i < n; i++) {
			curr_mask = (curr_mask<<1) & ((1<<b)-1);
			while (curr_mask > 0 and op(i, i - msb_index(lsb(curr_mask))) == i) {
				curr_mask ^= lsb(curr_mask);
			}
			curr_mask |= 1;
			mask[i] = curr_mask;
		}
		for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}

	T query(int l, int r) {
		// query too small
		if (r-l+1 <= b) return v[small(r, r-l+1)];
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb_index(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return v[ans];
	}
};

using min_rmq = rmq<int, less<int>>;
using max_rmq = rmq<int, greater<int>>;

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        vi p(n+1); rep1(i, n) cin>>p[i];
        vi r(n+1); rep1(i, n) r[i]=i+p[i];
        max_rmq rmq(r);
        vi dp(n+1, 0);
        vi lf(n+1);
        vb is_left(n+1, 0);
        for(int i=2; i<=n; i++) {
            dp[i]=max(dp[i-1], dp[i-1]>=i?i+p[i]:0);
            int tg=max(0, i-p[i]-1);
            if(dp[i-1]>=tg) {
                int l=0, r=i-1;
                while(l<r) {
                    int m=(l+r)/2;
                    if(dp[m]>=tg) r=m;
                    else l=m+1;
                }
                if(l<i-1) {
                    int new_dp=max(i-1, rmq.query(l+1, i-1));
                    if(new_dp>dp[i]) {
                        is_left[i]=1;
                        lf[i]=l+1;
                        dp[i]=new_dp;
                    }
                }
                else {
                    if(dp[i]<i-1) {
                        is_left[i]=1;
                        lf[i]=i;
                        dp[i]=i-1;
                    }
                }
            }
        }
        if(dp[n]<n) cout<<"NO\n";
        else {
            cout<<"YES\n";
            for(int i=n; i; i--) {
                if(is_left[i]) {
                    for(int j=i-1; j>=lf[i]; j--) is_left[j]=0;
                    i=lf[i];
                }
            }
            rep1(i, n) cout<<(is_left[i]?'L':'R');
            cout<<endl;
        }
    }
}