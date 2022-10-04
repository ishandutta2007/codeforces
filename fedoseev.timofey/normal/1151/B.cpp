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
    vector <vector <int>> prev(n, vector <int> (1024));
    vector <int> can(1024);
    can[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector <int> ncan(1024);
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            a[i][j] = x;
            for (int y = 0; y < 1024; ++y) {
                if (can[y]) {
                    ncan[x ^ y] = 1;
                    prev[i][x ^ y] = j;
                }
            }
        }
        can = ncan;
    }
    int ans = 0;
    for (int i = 1; i < 1024; ++i) {
        if (can[i]) ans = i;
    }
    if (ans == 0) {
        cout << "NIE\n";
    }
    else {
        cout << "TAK\n";
        vector <int> res;
        for (int i = n - 1; i >= 0; --i) {
            res.push_back(prev[i][ans]);
            ans ^= a[i][prev[i][ans]];
        }
        reverse(res.begin(), res.end());
        for (auto x : res) {
            cout << x + 1 << '\n';
        }
    }
}