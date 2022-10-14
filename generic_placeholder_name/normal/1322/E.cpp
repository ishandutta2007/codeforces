//testing RMQ template

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

template<typename T, typename Comparator>
struct rmq {
    static const Comparator comparator;
    int n;
    vector<vector<T>> tb;

    __attribute__((always_inline)) T op(const T& a, const T& b) const {
        return comparator(a, b) ? a : b;
    }

    rmq(const vector<T>& v) {
        n = v.size(); int dep = __lg(n) + 1;
        tb.resize(dep);
        tb[0] = v;
        for(int j = 1; j < dep; j++) {
            tb[j].resize(n - (1 << j) + 1);
            for(int i = 0; i + (1 << j) <= n; i++) {
                tb[j][i] = op(tb[j - 1][i], tb[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int l, int r) const {
        assert(l <= r);
        int dep = __lg(r - l + 1);
        auto x = op(tb[dep][l], tb[dep][r - (1 << dep) + 1]);
        return x;
    }
};

using min_rmq = rmq<int, less<int>>;
using max_rmq = rmq<int, greater<int>>;

int median(int a, int b, int c) {
    return a^b^c^max({a, b, c})^min({a, b, c});
}

int32_t main() {
    fastio;
    int n; cin>>n;
    vi a(n); rep(i, n) cin>>a[i];
    vi even, odd;
    rep(i, n) {
        if(i&1) odd.pb(a[i]);
        else even.pb(a[i]);
    }
    max_rmq even_max(even), odd_max(odd);
    min_rmq even_min(even), odd_min(odd);
    auto get = [&](int l, int r, bool mx) { //final value
        if(l<0) l&=1;
        if(r>=n) r=n-1-((r-n+1)&1);
        if(l&1) {
            if(mx) return odd_max.query(l/2, r/2);
            else return odd_min.query(l/2, r/2);
        }
        else {
            if(mx) return even_max.query(l/2, r/2);
            else return even_min.query(l/2, r/2);
        }
    };
    auto can_change = [&](int i, int k) { //if id can change for the first k turns
        bool small=(a[i]<a[i-1])&&(a[i]<a[i+1]);
        int l=k/2, r=(k+1)/2;
        if(small) return get(i-l*2, i+l*2, 1)<get(i-r*2+1, i+r*2-1, 0);
        else return get(i-l*2, i+l*2, 0)>get(i-r*2+1, i+r*2-1, 1);
    };
    vi lst(n), cnt(n);
    rep(i, n) {
        if(!i||i+1==n||median(a[i-1], a[i], a[i+1])==a[i]) {
            lst[i]=a[i];
            continue;
        }
        cnt[i]=cnt[i-1];
        int& c=cnt[i];
        if(can_change(i, c+1)) ++c;
        else if(!can_change(i, c)) --c;
        c=min({c, i, n-i-1});
        lst[i]=get(i-c, i+c, ((a[i]<a[i-1])&&(a[i]<a[i+1]))^(c&1));
    }
    cout<<*max_element(all(cnt))<<endl;
    rep(i, n) cout<<lst[i]<<' '; cout<<endl;
}