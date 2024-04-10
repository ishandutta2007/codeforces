#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 5, K = 12;
ll bit[K][N];

void add(int k, int i, ll d) {
    for (i++; i < N; i += i & -i) {
        bit[k][i] += d;
    }
}

ll sum0(int k, int i) {
    ll ret = 0;
    for (i++; i > 0; i -= i & -i) {
        ret += bit[k][i];
    }
    return ret;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    add(0, 0, 1);
    for (int x : a) {
        for (int i = 0; i <= k; i++) {
            add(i + 1, x, sum0(i, x - 1));
        }
    }

    cout << sum0(k + 1, n) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}