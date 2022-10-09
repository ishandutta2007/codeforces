#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <random>
#include <ctime>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n % 2050 != 0) {
        cout << -1 << '\n';
    } else {
        n /= 2050;
        long long ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}