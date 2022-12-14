#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    ll w = 0, b = 0;
    for (int i = 0; i < n; i++) {
        (i & 1 ? w : b) += (a[i] + 1) / 2;
        (i & 1 ? b : w) += a[i] / 2;
    }

    cout << min(w, b);
}