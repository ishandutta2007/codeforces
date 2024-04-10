#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        cout << max(reduce(a.begin(), a.end(), 0) - m, 0) << "\n";
    }
    return 0;
}