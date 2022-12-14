#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int M = 1e6 + 1;

bitset<M> not_prime;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    ll ans = 0;
    for (int p = 0; p < k; p++) {
        int x = a[p];
        for (int l = p, m = p, r = p; l < n; x /= a[l], l += k) {
            while (r + k < n && (a[r + k] == 1 || x == 1)) {
                r += k;
                x *= a[r];
                if (!not_prime[ a[r] ]) m = r;
            }
            if (!not_prime[x]) {
                ans += (r - max(m, l + k)) / k + 1;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    not_prime[1] = true;
    for (int i = 2; i < M; i++) if (!not_prime[i]) {
        for (int j = 2 * i; j < M; j += i) {
            not_prime[j] = true;
        }
    }

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}