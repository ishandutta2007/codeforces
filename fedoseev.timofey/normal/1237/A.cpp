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
    vector <int> can(n);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            a[i] = x / 2;
            can[i] = 0;
        } else {
            if (x > 0) a[i] = x / 2;
            else a[i] = x / 2 - 1;
            can[i] = 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    for (int i = 0; i < n; ++i) {
        if (sum < 0 && can[i]) {
            ++a[i];
            ++sum;
        }
    }
    for (int i = 0; i < n; ++i) cout << a[i] << '\n';
}