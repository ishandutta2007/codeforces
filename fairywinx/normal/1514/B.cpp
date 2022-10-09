#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>
#include <queue>
#include <set>
#include <random>
#include <ctime>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int mod = 1e9 + 7;

void solve() {
    long long n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    long long res = n;
    for (int i = 0; i < k - 1; ++i)
        res = (1ll * res * n) % mod;

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}