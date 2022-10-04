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
    int n, k;
    cin >> n >> k;
    vector <vector <int>> a(n, vector <int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            a[i][j] = (c == 'B');
        }
    }
    int cnt = 0;
    vector <vector <int>> goodr(n, vector <int> (n));
    vector <vector <int>> goodc(n, vector <int> (n));
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += a[i][j];
        }
        cnt += (sum == 0);
        if (sum > 0) {
            int l = n - 1, r = 0;
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) l = min(l, j), r = max(r, j);
            }
            for (int j = 0; j < n; ++j) {
                if (j <= l && j + k - 1 >= r) {
                    goodr[i][j] = 1;
                }
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i][j];
        }
        cnt += (sum == 0);
        if (sum > 0) {
            int l = n - 1, r = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i][j]) l = min(l, i), r = max(r, i);
            }
            for (int i = 0; i < n; ++i) {
                if (i <= l && i + k - 1 >= r) {
                    goodc[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            goodc[i][j] += goodc[i][j - 1];
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 1; i < n; ++i) {
            goodr[i][j] += goodr[i - 1][j];
        }
    }
    int ans = cnt;
    for (int i = 0; i + k <= n; ++i) {
        for (int j = 0; j + k <= n; ++j) {
            int cur_cnt = cnt;
            cur_cnt += goodc[i][j + k - 1] - (j == 0 ? 0 : goodc[i][j - 1]);
            cur_cnt += goodr[i + k - 1][j] - (i == 0 ? 0 : goodr[i - 1][j]);
            ans = max(ans, cur_cnt);
        }
    }
    cout << ans << '\n';
}