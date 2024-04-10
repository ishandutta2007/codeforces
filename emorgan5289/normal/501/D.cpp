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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    auto fwd = [&](vector<int>& p){
        ordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(p[i]);
            p[i] -= s.order_of_key(p[i]);
        }
    };
    fwd(a), fwd(b);
    debug(a);
    debug(b);
    for (int i = n-1; i >= 0; i--) {
        a[i] += b[i];
        if (a[i] >= n-i) {
            a[i] -= (n-i);
            if (i > 0) a[i-1]++;
        }
    }
    ordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(i);
    debug(s);
    for (int i = 0; i < n; i++) {
        debug(s, i, a[i]);
        a[i] = *s.find_by_order(a[i]);
        s.erase(s.find(a[i]));
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n-1];
}