#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3005;
pair<int, int> a[N];
int p[N], dp[N][N], n;

void dfs(int i, int j) {
    if (i == n || a[i].first > a[j].second)
        dp[i][j] = 0;
    if (dp[i][j] != -1) return;
    dfs(i+1, j);
    dp[i][j] = dp[i+1][j];
    if (a[i].second <= a[j].second) {
        dfs(p[i], j), dfs(i+1, i);
        dp[i][j] = max(dp[i][j], 1+dp[p[i]][j]+dp[i+1][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int l, r; cin >> l >> r;
            a[i] = {l, -r};
        }
        sort(a, a+n);
        for (int i = 0; i < n; i++)
            a[i].second *= -1;
        fill(p, p+n, n);
        int k = 0;
        for (int i = 0; i < n; i++) {
            fill(dp[i], dp[i]+n, -1);
            if (a[i].second >= a[k].second)
                k = i;
            for (int j = 0; j < n; j++)
                if (a[j].first > a[i].second) {
                    p[i] = j; break;
                }
        }
        dfs(0, k);
        cout << dp[0][k] << "\n";
    }
}