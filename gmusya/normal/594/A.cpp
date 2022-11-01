#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll x = a[n - 1];
    for (int i = 0; i < n / 2; ++i) {
        x = min(x, a[i + n / 2] - a[i]);
    }
    cout << x;
    return 0;
}