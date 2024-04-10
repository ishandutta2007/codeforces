//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    int ans[2] = {0, 0};
    vector<int> odd;
    while (k--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (2 * i + 1 == n)
                odd.push_back(x);
            else
                ans[i < n / 2 ? 0 : 1] += x;
        }
    }
    sort(all(odd), greater<>());
    for (int i = 0; i < (int)odd.size(); ++i)
        ans[i % 2] += odd[i];
    cout << ans[0] << ' ' << ans[1] << '\n';
}