#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int m;
    cin >> m;
    vector<pair<int, int>> q(m);
    for (auto &[i, x] : q) {
        int t;
        cin >> t;

        if (t == 1) {
            cin >> i >> x;
            i--;
        } else {
            i = -1;
            cin >> x;
        }
    }

    reverse(q.begin(), q.end());
    for (int i = 0; i < n; i++) {
        q.emplace_back(i, a[i]);
    }
    a.assign(n, -1);

    int pay = 0;
    for (auto &[i, x] : q) {
        if (i == -1) {
            pay = max(x, pay);
        } else if (a[i] == -1) {
            a[i] = max(x, pay);
        }
    }

    for (int x : a) cout << x << ' ';
}