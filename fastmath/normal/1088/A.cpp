#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            if (i % j == 0 && i / j < n && i * j > n) {
                cout << i << ' ' << j << '\n';
                exit(0);
            }   
        }   
    }   

    cout << "-1\n";
    return 0;
}