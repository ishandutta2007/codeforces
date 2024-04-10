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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename S>
using ordered_map = tree<T, S, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename S>
using ordered_multimap = tree<T, S, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// s.order_of_key(x) -> the number of elements strictly lower than x

// call randint() for a random integer
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

const int N = 3e5+5;
int a[N];
vector<int> s[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i], s[a[i]].pb(i);
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        int f = 0;
        for (int i = 0; i < 30; i++) {
            int x = a[uniform_randint(l, r)];
            cmax(f, int(upper_bound(all(s[x]), r)-lower_bound(all(s[x]), l)));
        }
        cout << max(1, 2*f-(r-l+1)) << "\n";
    }
}