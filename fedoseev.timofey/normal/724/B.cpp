#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    bool kek = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            --a[i][j];
            if (a[i][j] != j) {
                kek = false;
            }
        }
    }
    if (kek) {
        cout << "YES\n";
        return 0;
    }
    for (int x = 0; x < m; ++x) {
        for (int y = x; y < m; ++y) {
            bool bad = false;
            vector <int> c(m);
            for (int i = 0; i < m; ++i) c[i] = i;
            swap(c[x], c[y]);
            for (int i = 0; i < n; ++i) {
                int i1 = -1, i2 = -1;
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != c[j]) {
                        if (i1 == -1) i1 = j;
                        else i2 = j;
                    }
                }
                if (i1 != -1) {
                    if (i2 == -1) {
                        bad = true;
                        break;
                    }
                    swap(c[i1], c[i2]);
                    if (c != a[i]) {
                        bad = true;
                        break;
                    }
                    swap(c[i1], c[i2]);
                }
            }
            if (!bad) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}