#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    ll ans = 1e18 + 7;
    for (int k = 0; k < n; ++k) {
        ll tmp = -1e18 - 7;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == k) continue;
                tmp = max(tmp, a[i] * b[j]);
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}