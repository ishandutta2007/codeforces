#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long x = (n + k - 1) / k;
        k *= x;
        long long ans = (k + n - 1) / n;
        cout << ans << "\n";
    }
    return 0;
}