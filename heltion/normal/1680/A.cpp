#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int l = max(l1, l2), r = min(r1, r2);
        if (l <= r) cout << l << "\n";
        else cout << l1 + l2 << "\n";
    }
}