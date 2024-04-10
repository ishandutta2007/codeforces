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

    vt<bool> sieve(n + 1);
    vt<int> pri;
    for (int i = 2; i <= n; i++) if (!sieve[i]) {
        pri.push_back(i);

        for (int j = i; j <= n; j += i) {
            sieve[j] = true;
        }
    }

    int m = sz(pri);
    vt<int> got;
    int rem = n;
    int p = lower_bound(all(pri), 320) - pri.begin();
    int in;

    for (int i = 500; p < m && got.empty(); i += 500) {
        int pp = p;

        for (; p < m && pri[p] <= i; p++) {
            cout << "B " << pri[p] << endl;
            cin >> in;

            rem -= in;
        }

        cout << "A 1" << endl;
        cin >> in;

        if (in != rem) {
            for (; pp < p; pp++) {
                cout << "A " << pri[pp] << endl;
                cin >> in;

                if (in) {
                    got.push_back(pri[pp]);

                    break;
                }
            }
        }
    }

    for (p = 0; p < m && pri[p] < 320; p++) {
        cout << "B " << pri[p] << endl;
        cin >> in;
        cout << "A " << pri[p] << endl;
        cin >> in;

        if (in) {
            got.push_back(pri[p]);
            for (int k = pri[p] * pri[p]; k <= n; k *= pri[p]) {
                cout << "A " << k << endl;
                cin >> in;

                if (!in) break;
                got.back() = k;
            }
        }
    }

    cout << "C " << accumulate(all(got), 1, multiplies<int>());
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}