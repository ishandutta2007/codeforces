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
        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= i; j += 1) {
                if (j == 1 or j == i) cout << "1 ";
                else cout << "0 ";;
            }
            cout << "\n";
        }
    }
}