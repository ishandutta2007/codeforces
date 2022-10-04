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
    vector <int> cnt(n + 1);
    vector <vector <int>> who(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[n - x];
        who[n - x].push_back(i);
    }
    vector <int> ans(n);
    int cur = 1;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] % i) {
            cout << "Impossible\n";
            return 0;
        }
        int cnt = 0;
        for (auto j : who[i]) {
            ans[j] = cur;
            ++cnt;
            if (cnt == i) {
                cnt = 0;
                ++cur;
            }
        }
    }
    cout << "Possible\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}