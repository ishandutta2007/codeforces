#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int r1 = 1e9;
    int l1 = -1e9;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        r1 = min(r1, r);
        l1 = max(l1, l);
    }
    cin >> m;
    int l2 = -1e9;
    int r2 = 1e9;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l2 = max(l2, l);
        r2 = min(r2, r);
    }
    cout << max(0, max(l2 - r1, l1 - r2)) << endl;
}