#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        if (x >= 0) x = -x - 1;
    }

    if (n & 1) {
        auto it = min_element(a.begin(), a.end());
        *it = -*it - 1;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}