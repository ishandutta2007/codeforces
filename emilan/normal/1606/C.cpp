#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 19;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    a.push_back(18);

    vector<ll> ten(N, 1);
    for (int i = 1; i < N; i++) {
        ten[i] = 10 * ten[i - 1];
    }

    ll x = 0;
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        ll vals = ten[ a[i + 1] - a[i] ] - 1;
        if (cost + vals <= k) {
            cost += vals;
            x += vals * ten[ a[i] ];
        } else {
            x += (k - cost + 1) * ten[ a[i] ];
            break;
        }
    }

    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}