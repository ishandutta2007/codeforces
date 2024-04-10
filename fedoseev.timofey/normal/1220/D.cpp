#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const int K = 100;

vector <ll> who[K];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <ll> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        ll x = b[i];
        while (x % 2 == 0) {
            ++cur;
            x /= 2;
        }
        who[cur].push_back(b[i]);
    }
    int mx = 0, res = -1;
    for (int i = 0; i < K; ++i) {
        if (who[i].size() > mx) {
            mx = who[i].size();
            res = i;
        }
    }
    cout << n - mx << '\n';
    set <ll> ans;
    for (auto x : b) ans.insert(x);
    for (auto x : who[res]) ans.erase(x);
    for (auto x : ans) cout << x << ' ';
}