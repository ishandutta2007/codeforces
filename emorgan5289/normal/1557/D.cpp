#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// ordered statistic tree using fenwick tree.
// all operations take O(log(N)),
// where N is the limit on size of elements.
// see https://codeforces.com/blog/entry/61364

template<int N, typename T = int>
struct fenwick_multiset {

    T s = 0, tree[N+1];
    T size() const { return s; }
    fenwick_multiset() { fill(tree, tree+N+1, 0); }
    
    // insert x into the set with multiplicity k
    void insert(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    T index(int x) const {
        if (x <= 0) return 0;
        if (x >= N) return size();
        T i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    T count(int x) const {
        if (x < 0 || x >= N) return 0;
        int y = x+1; T i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(T x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }

    // returns the smallest element of the set
    // which is > x, or N if no such element
    int next_greater(int x) {
        return get(index(x+1));
    }

    // returns the largest element of the set
    // which is < x, or -1 if no such element
    int next_lower(int x) {
        T i = index(x);
        return i == 0 ? -1 : get(i-1);
    }

    // returns the number of values in the set
    // in the semi-open interval [l, r)
    T count_interval(int l, int r) {
        return index(r)-index(l);
    }
};

const int N = 1e6+5;
fenwick_multiset<N> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<vector<array<ll, 2>>> a(n);
    for (int i = 0; i < m; i++) {
        ll x, l, r; cin >> x >> l >> r; x--, l--, r--;
        a[x].pb({l, r});
    }
    vector<array<ll, 2>> b;
    for (int i = 0; i < n; i++) {
        sort(all(a[i]));
        vector<array<ll, 2>> tmp;
        for (auto& [x, y] : a[i]) {
            if (!tmp.empty() && x <= tmp.back()[1]+1) {
                cmax(tmp.back()[1], y);
            }
            else
                tmp.pb({x, y});
        }
        debug(i, tmp);
        for (auto& [x, y] : tmp) {
            b.pb({x, i+1});
            b.pb({y+1, -i-1});
        }
    }
    sort(all(b));
    debug(b);
    vector<vector<int>> adj(n);
    for (auto& [x, i] : b) {
        if (i > 0) {
            i--;
            debug("ins", i+1);
            f.insert(i);
            int j = f.next_lower(i);
            if (j != -1)
                adj[i].pb(j);
            int k = f.next_greater(i);
            if (k != N)
                adj[k].pb(i);
        } else {
            i = -(i+1);
            debug("rem", i+1);
            f.remove(i);
            int j = f.next_lower(i);
            int k = f.next_greater(i);
            if (j != -1 && k != N)
                adj[k].pb(j);
        }
    }
    debug(adj);
    vector<ll> dp(n);
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            cmax(dp[i], dp[j]+1);
    vector<ll> ans(n);
    int x = max_element(all(dp))-dp.begin();
    debug(x, dp[x]);
    cout << n-dp[x]-1 << "\n";
    while (1) {
        ans[x] = 1;
        if (dp[x] == 0) break;
        for (int j : adj[x])
            if (dp[j] == dp[x]-1) {
                x = j; break;
            }
    }
    for (int i = 0; i < n; i++)
        if (!ans[i]) cout << i+1 << " ";
    cout << "\n";
}