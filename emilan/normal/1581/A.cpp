#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll inv2 = 5e8 + 4;
ll fact[N];

void solve() {
    int n;
    cin >> n;
    cout << fact[2 * n] * inv2 % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}