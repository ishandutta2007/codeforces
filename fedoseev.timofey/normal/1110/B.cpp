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
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> b;
    for (int i = 1; i < n; ++i) {
        b.push_back(a[i] - a[i - 1] - 1);
    }
    sort(b.rbegin(), b.rend());
    int ans = a[n - 1] - a[0] + 1;
    for (int i = 0; i + 1 < k; ++i) {
        if (i < b.size()) ans -= b[i];
    }
    cout << ans << '\n';
}