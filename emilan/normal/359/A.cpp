#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;

            if (x && (!i || !j || i == n - 1 || j == m - 1)) return cout << 2, 0;
        }
    }

    cout << 4;
}