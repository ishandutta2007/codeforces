#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll res = 0;
        while (n > 0) {
            if (n % k == 0) {
                ++res;
                n /= k;
            }
            else {
                ll c = n - n % k;
                res += (n - c);
                n = c;
            }
        }
        cout << res << '\n';
    }
}