#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    vt<int> div;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            div.push_back(n / i);
        }
    }
    sort(all(div));
    div.erase(unique(all(div)), div.end());

    vt<int> primes;
    int t = n;
    for (int i = 2; i * i <= t; i++) {
        if (t % i == 0) {
            primes.push_back(i);
            t /= i;
            while (t % i == 0) t /= i;
        }
    }
    if (t != 1) primes.push_back(t);
    int m = sz(primes);

    int cnt = 0;
    vt<int> ans{n};
    for (int i = 0; i < m; i++) {
        if (i) {
            int p = primes[i - 1] * primes[i];
            if (p == n) cnt++;
            else ans.push_back(p);
        }

        for (int &x : div) {
            if (x % primes[i]) continue;
            if ((i && x == primes[i - 1] * primes[i])
                    || (i != m - 1 && x == primes[i] * primes[i + 1])) {
                continue;
            }

            ans.push_back(x);
            x = -x;
        }
        div.erase(
            remove_if(all(div), [](int x) { return x < 0; }),
            div.end()
        );
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}