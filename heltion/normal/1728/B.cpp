#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i <= n - 2; i += 1) cout << ((i - 1) ^ 1) + 1 << " ";
            cout << n - 1 << " " << n;
        }
        else {
            for (int i = 1; i <= n - 5; i += 1) cout << ((i - 1) ^ 1) + 1 << " ";
            cout << n - 3 << " " << n - 2 << " " << n - 4 << " ";
            cout << n - 1 << " " << n;
        }
        cout << "\n";
    }
}