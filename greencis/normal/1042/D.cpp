#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

// wow, glamorous data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n;
ll t, a[200105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> t;
    ordered_set st;
    ll cur = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cur += a[i];
        st.insert(cur);
    }
    cur = 0;
    for (int i = 0; i < n; ++i) {
        ans += st.order_of_key(t);
        cur += a[i];
        st.erase(st.lower_bound(cur - 1)); // using lower_bound or find doesn't work correctly...
        t += a[i];
    }
    cout << ans << endl;
}