#include "bits/stdc++.h"

using namespace std;

const int N = 200200;
const int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << a[0] << "\n";
    }
}