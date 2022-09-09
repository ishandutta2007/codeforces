#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ : ranges::iota_view(0, t)) {
        int n, m;
        cin >> n >> m;
        for (int i : ranges::iota_view(0, n)) {
            for (int j : ranges::iota_view(0, m))
                cout << (((i + 1) >> 1) + ((j + 1) >> 1)) % 2 << " ";
            cout << "\n";
        }
    }
}