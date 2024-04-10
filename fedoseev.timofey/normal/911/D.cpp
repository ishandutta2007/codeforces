#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    bool fl = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < n; ++j) {
        for (int i = j + 1; i < n; ++i) {
            if (a[i] < a[j]) fl ^= 1;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int z = r - l + 1;
        int pairs = z * (z - 1) / 2;
        if (pairs & 1) fl ^= 1;
        if (fl) {
            cout << "odd" << endl;
        }
        else {
            cout << "even" << endl;
        }
    }
}