#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    if (m < n) swap(n, m);

    if (3 <= n) {
        cout << n * m - ((n * m) % 2) << '\n';
    }
    else if (n == 2) {
        if (m == 2) {
            cout << "0\n";
        }
        else if (m == 3) {
            cout << "4\n";
        }
        else if (m == 7) {
            cout << "12\n";
        }
        else {
            cout << n * m << '\n';
        }
    }
    else if (n == 1) {
        int add = 6 * (m / 6);
        m %= 6;
        if (m == 0) cout << add << '\n';
        else if (m == 1) cout << add << '\n';
        else if (m == 2) cout << add << '\n';
        else if (m == 3) cout << add << '\n';
        else if (m == 4) cout << add + 2 << '\n';
        else if (m == 5) cout << add + 4 << '\n';
    }
    else {
        exit(1);
    }
   
    return 0;
}