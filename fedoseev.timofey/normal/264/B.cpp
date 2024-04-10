#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;
vector <int> pr(N);

int prBest[N];

vector <int> getPrimes(int x) {
    vector <int> d;
    while (x > 1) {
        int p = pr[x];
        d.push_back(p);
        while (x % p == 0) x /= p;
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 2; i < N; ++i) pr[i] = i;
    for (int i = 2; i < N; ++i) {
        if (pr[i] == i) {
            for (int j = 2 * i; j < N; j += i) {
                pr[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        vector <int> d = getPrimes(a[i]);
        for (auto x : d) {
            dp[i] = max(dp[i], prBest[x] + 1);
        }
        for (auto x : d) {
            prBest[x] = max(prBest[x], dp[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << ans << '\n';
}