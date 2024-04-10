#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k, x;
    cin >> n >> x >> k;
    vector <long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (k > 0) {
            long long low = lower_bound(a.begin(), a.end(), (k + (a[i] - 1) / x) * x) - a.begin();
            long long high = upper_bound(a.begin(), a.end(), (k + (a[i] - 1) / x) * x + x - 1) - a.begin();
            ans += high - low;
        }
        else {
            long long low = lower_bound(a.begin(), a.end(), a[i]) - a.begin();
            long long high = upper_bound(a.begin(), a.end(), (k + (a[i] - 1) / x) * x + x - 1) - a.begin();
            ans += high - low;
        }
    }
    cout << ans << endl;
    // k = h / x - (l - 1) / x;
    // h = (k + (l - 1) / x) * x
}