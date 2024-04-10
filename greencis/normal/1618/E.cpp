#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<ll> b(n), a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            sum += b[i];
        }
        ll divr = n * ll(n + 1) / 2;
        bool good = true;
        if (sum % divr) {
            good = false;
        } else {
            sum /= divr;
            for (int i = 0; i < n; ++i) {
                int j = (i + n - 1) % n;
                ll cur = sum - b[i] + b[j];
                if (cur % n || (cur /= n, cur < 1 || cur > (ll) 1e9)) {
                    good = false;
                    break;
                }
                a[i] = cur;
            }
        }
        if (!good) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
    }
}