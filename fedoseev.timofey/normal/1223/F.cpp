#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;

int a[N];

ll ans = 0;

void rec(int l, int r) {
    int m = (l + r) >> 1;
    map <pair <int, int>, int> go;
    vector <int> par(1, 0);
    vector <int> sum(1, 0);
    int cnt = 1;
    int cur = 0;
    vector <int> st;
    for (int i = m - 1; i >= l; --i) {
        if (!st.empty() && st.back() == a[i]) {
            cur = par[cur];
            st.pop_back();
        } else {
            st.push_back(a[i]);
            if (go.count({cur, a[i]})) {
                cur = go[{cur, a[i]}];
            } else {
                par.push_back(cur);
                sum.push_back(0);
                go[{cur, a[i]}] = cnt;
                cur = cnt;
                ++cnt;
            }
        }
        ++sum[cur];
    }
    st.clear();
    cur = 0;
    for (int i = m; i < r; ++i) {
        if (!st.empty() && st.back() == a[i]) {
            cur = par[cur];
            st.pop_back();
        } else {
            st.push_back(a[i]);
            if (go.count({cur, a[i]})) {
                cur = go[{cur, a[i]}];
            } else {
                par.push_back(cur);
                sum.push_back(0);
                go[{cur, a[i]}] = cnt;
                cur = cnt;
                ++cnt;
            }
        }
        ans += sum[cur];
    }
    if (r - l > 1) {
        rec(l, m);
        rec(m, r);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    ans = 0;
    rec(0, n);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    while (q--) solve();
}