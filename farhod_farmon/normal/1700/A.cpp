#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        cout << m * (m + 1) / 2 + m * (n * (n + 1) / 2 - 1) << "\n";
    }
}