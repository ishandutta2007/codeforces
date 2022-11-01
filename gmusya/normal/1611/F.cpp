#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll s;
        cin >> s;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i - 1];
        }
        vector<int> lg(n + 2);
        for (int i = 2; i <= n + 1; ++i) {
            lg[i] = lg[i / 2] + 1;
        }
        vector<vector<ll>> sparse(lg[n + 1] + 1, vector<ll>(n + 1));
        for (int i = 0; i <= n; ++i) {
            sparse[0][i] = sum[i];
        }
        for (int p = 1; p <= lg[n + 1]; ++p) {
            for (int i = 0; i + (1 << (p - 1)) <= n; ++i) {
                sparse[p][i] = min(sparse[p - 1][i], sparse[p - 1][i + (1 << (p - 1))]);
            }
        }
        function<ll(int, int)> GetMin = [&](int l, int r) {
            int p = lg[r - l + 1];
            ll x = sparse[p][l];
            ll y = sparse[p][r - (1 << p) + 1];
            return min(x, y);
        };
        pair<int, int> answer;
        for (int first = 0; first <= n; ++first) {
            int L = first, R = n;
            while (L != R) {
                int M = (L + R + 1) / 2;
                ll F = GetMin(first, M);
                if (F - sum[first] + s >= 0) {
                    L = M;
                } else {
                    R = M - 1;
                }
            }
            if (L - first > answer.second - answer.first) {
                answer = {first, L};
            }
        }
        if (answer.first >= answer.second) {
            cout << -1 << '\n';
        } else {
            cout << answer.first + 1 << ' ' << answer.second << '\n';
        }
    }
    return 0;
}