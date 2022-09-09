#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL A = 0, B = 1;
        int n;
        cin >> n;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            if (a == 0) B *= 2;
            if (a == 1) A += 1;
        }
        cout << A * B << "\n";
    }
    return 0;
}