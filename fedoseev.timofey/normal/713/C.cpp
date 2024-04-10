#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3007;

ll dp[N][N];

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i;
    }
    vector <int> b = a;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) dp[0][i] = abs(a[0] - b[i]);
    for (int i = 1; i < n; ++i) {
        ll best = 2e18;
        for (int j = 0; j < n; ++j) {
            best = min(best, dp[i - 1][j]);
            dp[i][j] = best + abs(a[i] - b[j]);
        }
    }
    ll ans = 2e18;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans << '\n';
}