#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
    int a, b;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector <Edge> E;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        E.push_back({a, b});
    }
    vector <int> used(3 * n);
    vector <int> ans;
    for (int i = 0; i < m; ++i) {
        if (!used[E[i].a] && !used[E[i].b]) {
            ans.push_back(i);
            used[E[i].a] = 1;
            used[E[i].b] = 1;
        }
    }
    if (ans.size() >= n) {
        cout << "Matching\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << "IndSet\n";
        int cnt = 0;
        for (int i = 0; i < 3 * n; ++i) {
            if (!used[i] && cnt < n) {
                cout << i + 1 << ' ';
                ++cnt;
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}