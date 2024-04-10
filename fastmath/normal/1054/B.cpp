#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int curr = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (curr < x) {
            cout << i + 1 << '\n';
            exit(0);
        }
        curr += (x == curr);
    }     

    cout << "-1\n";
    return 0;
}