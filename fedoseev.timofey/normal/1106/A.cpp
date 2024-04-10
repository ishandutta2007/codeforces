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
    int n;
    cin >> n;
    vector <vector <char>> a(n, vector <char> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < n; ++j) {
            if (a[i][j] == 'X' && a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j + 1] && a[i][j] == a[i + 1][j - 1] && a[i][j] == a[i + 1][j + 1]) ++cnt;
        }
    }
    cout << cnt << '\n';
}