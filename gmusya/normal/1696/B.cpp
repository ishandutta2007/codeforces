#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        int zeros = 0;
        for (int& x : a) {
            if (x == 0) {
                ++zeros;
            }
        }
        if (zeros == n) {
            cout << 0 << '\n';
            continue;
        }
        int firstNonZero = 0;
        int lastNonZero = n - 1;
        while (a[firstNonZero] == 0) {
            ++firstNonZero;
        }
        while (a[lastNonZero] == 0) {
            --lastNonZero;
        }
        if (zeros + lastNonZero - firstNonZero + 1 == n) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}