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
#define debug(...)
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

const int N = 2e5+5;
int a[N], ainv[N], b[N];
ordered_set<int> seg[2*N];

void add(int i, int x) {
    for (i++; i < N; i += i & -i)
        seg[i].insert(x);
}

void rem(int i, int x) {
    for (i++; i < N; i += i & -i)
        seg[i].erase(seg[i].find(x));
}

int qry(int i, int k) {
    int ans = 0;
    for (; i > 0; i -= i & -i)
        ans += seg[i].order_of_key(k);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i], ainv[a[i]] = i;
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i] = ainv[b[i]], add(i, b[i]);
    while (m--) {
        int t; cin >> t;
        if (t == 2) {
            int x, y; cin >> x >> y; x--, y--;
            rem(x, b[x]), rem(y, b[y]);
            swap(b[x], b[y]);
            add(x, b[x]), add(y, b[y]);
        } else {
            int la, ra, lb, rb; cin >> la >> ra >> lb >> rb; la--, ra--, lb--, rb--;
            cout << qry(rb+1, ra+1)-qry(lb, ra+1)-qry(rb+1, la)+qry(lb, la) << "\n";
        }
    }
}