#include <bits/stdc++.h>

using namespace std;

#define int long long

const int KEK = 2007;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (k > KEK) {
        cout << "No\n";
        exit(0);
    }
    
    for (int i = 1; i <= k; ++i) {
        for (int j = i + 1; j <= k; ++j) {
            if (n % i == n % j) {
                cout << "No\n";
                exit(0);
            }
        }
    }

    cout << "Yes\n";
    return 0;
}