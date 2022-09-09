#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int k;
        cin >> k;
        for (int i = 1; ; i += 1)
            if (i * i >= k) {
                k -= (i - 1) * (i - 1);
                if (k <= i) cout << k << " " << i << "\n";
                else cout << i << " " <<2 * i - k << "\n";
                break;
            }
    }
    return 0;
}