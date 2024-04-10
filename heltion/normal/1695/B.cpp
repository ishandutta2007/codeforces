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
        vector<LL> a(n);
        for (LL& ai : a) cin >> ai; 
        if (n & 1) cout << "Mike\n";
        else {
            LL x = LLONG_MAX, y = LLONG_MAX;
            for (int i = 0; i < n; i += 1) {
                if (i % 2 == 0) x = min(x, n * a[i] + i);
                else y = min(y, n * a[i] + i);
            }
            cout << (x > y ? "Mike\n" : "Joe\n");
        }
    }
}