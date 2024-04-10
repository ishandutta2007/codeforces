#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int two = 0;
    for (int &x : a) {
        for (; ~x & 1; x /= 2) two++;
    }

    ll mx = *max_element(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0) - mx;
    mx <<= two;

    cout << sum + mx << "\n";
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