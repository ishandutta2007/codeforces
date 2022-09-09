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
        int m = 0;
        for (int i = 1; i + 1 < n; i += 1)
            if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
                a[i + 1] = i + 2 < n ? max(a[i], a[i + 2]) : a[i];
                m += 1;
            }
        cout << m << "\n";
        for (int ai : a) cout << ai << " ";
        cout << "\n";
    }

}