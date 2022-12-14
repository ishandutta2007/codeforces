#include <bits/stdc++.h>

using namespace std;

// (gcd, lcm) <=> (k, hk)
// h = ((x / k) + d) / c

const int N = 2e7 + 1;
int sieve[N];

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 2; i < N; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j < N; j += i) {
                sieve[j]++;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int c, d, x;
        cin >> c >> d >> x;

        int ans = 0;

        auto check = [&](int k) {
            if (x % k) return;

            int num = x / k + d;
            if (num % c) return;

            int h = num / c;
            ans += 1 << sieve[h];
        };

        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                check(i);
                if (i * i != x) check(x / i);
            }
        }

        cout << ans << '\n';
    }
}