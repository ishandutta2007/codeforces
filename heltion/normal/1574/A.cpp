#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= i; j += 1) cout << "(";
            for (int j = 1; j <= i; j += 1) cout << ")";
            for (int j = i + 1; j <= n; j += 1) cout << "()";
            cout << "\n";
        }
    }
    return 0;
}