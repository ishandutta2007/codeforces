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
    int n;
    cin >> n;
    vector <int> a(n);
    vector <bool> ok(n);
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        a[i] = floor(x);
        if (floor(x) < ceil(x)) {
            ok[i] = 1;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    for (int i = 0; i < n; ++i) {
        if (sum < 0 && ok[i]) {
            ++sum;
            ++a[i];
        }
    }
    assert(sum == 0);
    for (int i = 0; i < n; ++i) cout << a[i] << '\n';
}