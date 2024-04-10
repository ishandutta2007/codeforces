#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        LL k, x;
        cin >> k >> x;
        cout << *ranges::partition_point(ranges::iota_view(0, 2 * k - 1), [&](LL n){
            if (n <= k) return n * (n + 1) / 2 < x;
            return k * (k + 1) / 2 + (k - 1 + 2 * k - n) * (n - k) / 2 < x;
        }) << "\n";
    }
    return 0;
}