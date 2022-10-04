#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <vector <int>> kek = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n));
    int cnt = -1;
    for (int i = 0; i < n; i += 4) {
        for (int j = 0; j < n; j += 4) {
            ++cnt;
            for (int k = 0; k < 4; ++k) {
                for (int t = 0; t < 4; ++t) {
                    a[i + k][j + t] = kek[k][t] ^ (cnt << 4);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}