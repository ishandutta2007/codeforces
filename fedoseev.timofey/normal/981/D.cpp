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

using namespace std;

typedef long long ll;

vector <ll> ps;

ll get(int l, int r) {
    return ps[r + 1] - ps[l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ps.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + a[i];
    }
    auto check = [&](ll mask) {
        vector <vector <int>> dp(n + 1, vector <int>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int g = 0; g < i; ++g) {
                    if (dp[g][j - 1] && ((get(g, i - 1) & mask) == mask)) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        return dp[n][k];
    };
    ll ans = 0;
    for (int bit = 56; bit >= 0; --bit) {
        if (check(ans | (1ll << bit))) {
            ans |= (1ll << bit);
        }
    }
    cout << ans << '\n';
}