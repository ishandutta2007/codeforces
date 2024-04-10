#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

pair<vector<int>, vector<int>> linear_sieve(int n) {
    vector<int> lpf(n + 1, -1);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (lpf[i] == -1) {
            lpf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > lpf[i] || p * i > n) break;
            lpf[p * i] = p;
        }
    }
    return {lpf, primes};
}

auto [lpf, primes] = linear_sieve(1e6);

int solve() {
    int n;
    cin >> n;

    for (int m : primes) {
        cerr << n << ' ' << m << endl;
        if (lpf[n + m] != n + m) {
            return m;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}