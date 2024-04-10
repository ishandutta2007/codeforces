#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

const int MX = 1e6 + 1;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <int>> dp(n, vector <int> (1, 1));
    vector <vector <int>> idx(MX);
    for (int i = 0; i < n; ++i) idx[a[i]].push_back(i);
    vector <int> lst;
    for (int i = 0; i < n; ++i) lst.push_back(i);
    for (int i = 2; i <= n; ++i) {
        vector <int> id;
        for (int j = i; j < MX; j += i) {
            for (auto k : idx[j]) {
                id.push_back(k);
            }
        }
        sort(id.begin(), id.end());
        int pt = 0;
        int cur = 0;
        vector <int> ndp;
        for (auto j : id) {
            while (pt < lst.size() && lst[pt] < j) {
                add(cur, dp[lst[pt]].back());
                ++pt;
            }
            ndp.push_back(cur);
        }
        lst = id;
        for (int j = 0; j < id.size(); ++j) {
            dp[id[j]].push_back(ndp[j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            add(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}