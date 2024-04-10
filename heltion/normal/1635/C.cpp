#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        int nond = 1;
        for (int i = 1; i < n; i += 1)
            if (a[i] < a[i - 1]) nond = 0;
        if (nond) {
            cout << "0\n";
            continue;
        }
        if (a[n - 2] <= a[n - 1] and a[n - 1] >= 0) {
            cout << n - 2 << "\n";
            for (int i = 1; i <= n - 2; i += 1)
                cout << i << " " << n - 1 << " " << n << "\n";
        }
        else cout << "-1\n";
    }

}