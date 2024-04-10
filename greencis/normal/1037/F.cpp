#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef uint64_t ull;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;

const int mod = 1000000007;
inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int n, k, a[1001005];
pii p[1001005];
set<int> st;

inline int calc(int len, int k) {
    int z = len / (k - 1);
    return (z * (ll)len - z * ll(z + 1) / 2 * (k - 1)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i] = { a[i], i + 1 };
    }
    st.insert(0);
    st.insert(n + 1);
    sort(p, p + n, greater<pii>());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int idx = p[i].second;
        auto it = st.lower_bound(idx);
        int R = *it - idx - 1;
        int L = idx - *--it - 1;
        st.insert(idx);
        int cur = calc(L + R + 1, k);
        add(cur, mod - calc(L, k));
        add(cur, mod - calc(R, k));
        add(ans, cur * ll(p[i].first) % mod);
    }
    cout << ans << endl;
}