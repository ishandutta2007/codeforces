#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define x LL
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<LL> ans(T + 1);
    vector<int> l(T + 1), r(T + 1);
    int n = 200000;
    vector<vector<int>> R(n + 1);
    for (int i = 1; i <= T; i += 1) {
        cin >> l[i] >> r[i];
        ans[i] = (LL)(r[i] - l[i] + 1) * (r[i] - l[i]) * (r[i] - l[i] - 1) / 6;
        R[r[i]].push_back(i);
    }
    vector<vector<int>> d(2 * n + 1);
    for (int i = 1; i <= n; i += 1)
        for (int j = i; j <= 2 * n; j += i)
            d[j].push_back(i);
    auto lcm = [&](int i, int j, int k) {
        if (k % i == 0 and k % j == 0) return k;
        return 2 * k;
    };
    LL sum1 = 0;
    vector<int> bit(n + 1);
    auto add = [&](int x) {
        for (; x <= n; x += x & -x)
            bit[x] += 1;
    };
    auto sum = [&](int x) {
        int res = 0;
        for (; x; x -= x & -x)
            res += bit[x];
        return res;
    };
    for (int k = 1; k <= n; k += 1) {
        for (int j : d[2 * k]) {
            if (k % j and j * 2 <= k) continue;
            if (j >= k) break;
            for (int i : d[2 * k]) {
                if (i >= j) break;
                if (lcm(i, j, k) < i + j + k) {
                    sum1 += 1;
                    add(i);
                }
            }
        }
        for (int i : R[k]) {
            ans[i] -= sum1 - sum(l[i] - 1);
        }
    }
    for (int i = 1; i <= T; i += 1) cout << ans[i] << "\n";
}