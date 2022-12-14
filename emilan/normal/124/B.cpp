#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = 1 << 30;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> a0(n);
    for (auto &x : a0) cin >> x;

    vector<int> p(k);
    iota(p.begin(), p.end(), 0);

    int ans = kInf;
    do {
        vector a(n, string(k, '\0'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                a[i][p[j]] = a0[i][j];
            }
        }

        ans = min(ans, stoi(*max_element(a.begin(), a.end()))
                - stoi(*min_element(a.begin(), a.end())));
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
}