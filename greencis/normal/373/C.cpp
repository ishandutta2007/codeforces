#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    int L = 0, R = n / 2;
    while (L < R) {
        int mid = (L + R + 1) >> 1;
        bool good = true;
        for (int i = 0; i < mid; ++i) {
            if (2 * v[i] > v[n - mid + i]) {
                good = false;
                break;
            }
        }
        if (good)
            L = mid;
        else
            R = mid - 1;
    }
    cout << n - L << '\n';
}