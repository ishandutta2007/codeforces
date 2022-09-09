#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int k;
        cin >> k;
        for (int i = 1; k; i += 1) {
            if (i % 3 == 0 or i % 10 == 3) continue;
            k -= 1;
            if (k == 0) cout << i << '\n';
        }
    }
    return 0;
}