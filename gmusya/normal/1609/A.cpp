#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cnt = 0;
        vector<ll> b = a;
        for (int i = 0; i < n; ++i) {
            while (b[i] % 2 == 0) {
                b[i] /= 2;
                ++cnt;
            }
        }
        sort(b.rbegin(), b.rend());
        while (cnt) {
            b[0] *= 2;
            --cnt;
        }
        ll sum = 0;
        for (ll x : b) {
            sum += x;
        }
        cout << sum << '\n';
    }
    return 0;
}