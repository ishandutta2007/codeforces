#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i += 1) cin >> a[i];
        if (a[1] == 1) {
            cout << n + 1;
            for (int i = 1; i <= n; i += 1) cout << " " << i;
            cout << "\n";
        }
        else if (a[n] == 0) {
            for (int i = 1; i <= n; i += 1) cout << i << " ";
            cout << n + 1 << "\n";
        }
        else {
            for (int i = 1; i < n; i += 1) if (a[i] == 0 and a[i + 1] == 1) {
                for (int j = 1; j <= i; j += 1) cout << j << " ";
                cout << n + 1;
                for (int j = i + 1; j <= n; j += 1) cout << " " << j;
                cout << "\n";
                break;
            }
        }
    }
    return 0;
}