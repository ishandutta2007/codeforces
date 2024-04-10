#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (n % 2)
        --n;
    ull ans = 0;
    for (int i = 0; i < n; i += 2) {
        ll balance = 0;
        ll min_balance = 0;
        for (int j = i + 1; j < n; ++j) {
            if (j % 2 == 0) {
                balance += v[j];
            } else {
                ll L = max<ll>(1, max(balance + 1, balance - min_balance));
                ll R = min<ll>(v[j], balance + v[i]);
                if (L <= R)
                    ans += R - L + 1;
                balance -= v[j];
                min_balance = min(min_balance, balance);
            }
        }
    }
    cout << ans << '\n';
}