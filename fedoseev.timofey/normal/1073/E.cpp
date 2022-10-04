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

const int lim = 1 << 10;
const int md = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

ll count(ll x, int k) {
    if (x == 0) return 0;
    vector <int> a;
    while (x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }
    reverse(a.begin(), a.end());
    int n = a.size();
    vector <vector <vector <int>>> sum(n, vector <vector <int>>(2, vector <int> (lim)));
    vector <vector <vector <int>>> dp(n, vector <vector <int>>(2, vector <int> (lim)));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < 10; ++j) {
            if (i == 0 && j > a[0]) continue;
            int t = 0;
            if (i == 0 && j == a[i]) t = 1;
            sum[i][t][1 << j] = j;
            dp[i][t][1 << j] = 1;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int t = 0; t < 2; ++t) {
            if (t == 1) {
                for (int j = 0; j <= a[i + 1]; ++j) {
                    for (int mask = 0; mask < lim; ++mask) {
                        int nmask = mask | (1 << j);
                        if (__builtin_popcount(nmask) > k) continue;
                        int nt = a[i + 1] == j;
                        sum[i + 1][nt][nmask] = add(sum[i + 1][nt][nmask], add(mul(sum[i][t][mask], 10), mul(j, dp[i][t][mask])));
                        dp[i + 1][nt][nmask] = add(dp[i + 1][nt][nmask], dp[i][t][mask]);
                    }
                }
            }
            else {
                for (int j = 0; j < 10; ++j) {
                    for (int mask = 0; mask < lim; ++mask) {
                        int nmask = mask | (1 << j);
                        if (__builtin_popcount(nmask) > k) continue;
                        sum[i + 1][0][nmask] = add(sum[i + 1][0][nmask], add(mul(sum[i][t][mask], 10), mul(j, dp[i][t][mask])));
                        dp[i + 1][0][nmask] = add(dp[i + 1][0][nmask], dp[i][t][mask]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < lim; ++mask) {
        if (__builtin_popcount(mask) <= k) { 
            ans = add(ans, sum[n - 1][0][mask]);
            ans = add(ans, sum[n - 1][1][mask]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll l, r; int k;
    cin >> l >> r >> k;
    cout << sub(count(r, k), count(l - 1, k)) << '\n';
}