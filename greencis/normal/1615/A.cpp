#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll n, sum = 0, x;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            sum += x;
        }
        ll ans = !!(sum % n);
        cout << ans << endl;
    }
}