#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, z;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    int mn1 = 10, mn2 = 10, mn3 = 10;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < mn1) mn1 = a[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
        if (b[i] < mn2) mn2 = b[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                if (a[i] < mn3) mn3 = a[i];
            }
        }
    }
    if (mn3 != 10) cout << mn3;
    else cout << min(mn1, mn2) << max(mn2, mn1);
}