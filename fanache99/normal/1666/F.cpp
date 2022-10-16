#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

const int MAXN = 5000;
const int MOD = 998244353;

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int power(int base, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = mul(answer, base);
        }
        base = mul(base, base);
        power >>= 1;
    }
    return answer;
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int f[1 + MAXN], pref[1 + MAXN], fact[1 + MAXN], dp[1 + MAXN][1 + MAXN];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    srand(time(0));
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            f[x]++;
        }
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + f[i];
        }

        for (int i = 1; i <= n; i++) {
            dp[0][i] = f[i];
        }
        for (int r = 1; r < n / 2; r++) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                dp[r][i] = mul(sum, mul(f[i], pref[i - 1] - (2 * r - 1)));
                add(sum, dp[r - 1][i]);
            }
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            dp[n / 2][i] = mul(sum, f[i]);
            add(sum, dp[n / 2 - 1][i]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            add(ans, dp[n / 2][i]);
        }
        for (int i = 1; i <= n; i++) {
            ans = mul(ans, power(fact[f[i]], MOD - 2));
        }
        cout << ans << "\n";

        for (int i = 1; i <= n; i++) {
            f[i] = pref[i] = 0;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}