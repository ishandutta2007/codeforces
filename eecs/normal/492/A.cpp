#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 1;; i++) {
        int sum = i * (i + 1) / 2;
        tot += sum;
        // cout << "sum=" << sum << " tot=" << tot << "\n";
        if (tot > n) {
            cout << i - 1 << "\n";
            break;
        }
    }
    return 0;
}