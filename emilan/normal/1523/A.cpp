#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;

        for (int k = 0; k < min(m, n); k++) {
            string b(a);
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                if (i > 0 && a[i - 1] == '1') cnt++;
                if (i < n - 1 && a[i + 1] == '1') cnt++;
                if (cnt == 1) b[i] = '1';
            }
            swap(a, b);
        }

        cout << a << '\n';
    }
}