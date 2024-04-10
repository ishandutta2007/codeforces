#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

int n;
vector<int> a;
vector<int> pos;
vector<int> ans;

void rev(int i) {
    ans.push_back(i + 1);
    reverse(a.begin(), a.begin() + i + 1);
    for (int j = 0; j < n; ++j)
        pos[a[j]] = j;
}

void solve() {
    cin >> n;
    a.resize(n);
    ans.clear();
    pos.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 != i % 2) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = n - 1; i > 0; i -= 2) {
        rev(pos[i]);
        rev(pos[i - 1] - 1);
        rev(pos[i - 1] + 1);
        rev(2);
        rev(i);
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}