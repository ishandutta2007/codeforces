#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll cur = 0;
    vector<ll> pre(n + 1);
    pre[1] = 1;
    pre[2] = -1;
    for (int q = 1; q < n; q++) {
        cur = (cur + pre[q] + m) % m;

        // subtraction
        pre[q + 1] = (pre[q + 1] + cur) % m;

        // floor-div O(n / q)
        for (int d = 2; d * q <= n; d++) {
            pre[d * q] = (pre[d * q] + cur) % m;
            if (d * q + d <= n) {
                pre[d * q + d] = (pre[d * q + d] - cur + m) % m;
            }
        }
    }
    cur = (cur + pre[n] + m) % m;

    cout << cur << '\n';
}