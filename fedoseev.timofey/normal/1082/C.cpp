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
    vector <vector <int>> a(m);
    for (int i = 0; i < n; ++i) {
        int s, r;
        cin >> s >> r;
        --s;
        a[s].push_back(r);
    }
    for (int i = 0; i < m; ++i) sort(a[i].rbegin(), a[i].rend());
    vector <int> ans(n + 1);
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < a[i].size(); ++j) {
            sum += a[i][j];
            ans[j + 1] += max(0, sum);
        } 
    }
    int res = 0;
    for (int i = 0; i <= n; ++i) res = max(res, ans[i]);
    cout << res << '\n';
}