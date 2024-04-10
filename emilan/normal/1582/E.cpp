#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int S = 455;
const int INF = 1 << 30;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    reverse(a.begin(), a.end());

    array<queue<pii>, S> wait;
    array<int, S> mx;
    array<ll, S> sum;
    mx.fill(0);
    mx[0] = INF;
    sum.fill(0);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < S; j++) {
            sum[j] += a[i];
            if (i - j >= 0) sum[j] -= a[i - j];

            while (!wait[j].empty()) {
                auto [p, x] = wait[j].front();
                if (p > i) break;

                wait[j].pop();

                mx[j] = max(mx[j], x);
            }

            if (sum[j] < mx[j - 1]) {
                wait[j].emplace(i + j + 1, sum[j]);
            }
        }
    }

    for (int j = 1; j < S; j++) {
        while (!wait[j].empty()) {
            auto [p, x] = wait[j].front();
            wait[j].pop();

            mx[j] = max(mx[j], x);
        }
    }

    cout << find(mx.begin(), mx.end(), 0) - mx.begin() - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}