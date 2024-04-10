#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ : ranges::iota_view(0, t)) {
        int n;
        cin >> n;
        if (n & 1) cout << "-1\n";
        else cout << n / 2 << " 0 0\n";
    }
}