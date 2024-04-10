#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

char C[5005][5005];
int dp[5005][5005];
int a[5005];

int main() {
    ios_base::sync_with_stdio(false);

    C[0][0] = 1;
    for (int i = 1; i <= 5000; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) & 1;
    }

    int n, q;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int len = 1; len <= n; ++len) {
        vector<int> pos;
        for (int j = 0; j < len; ++j)
            if (C[len - 1][j])
                pos.push_back(j);
        for (int i = 1; i + len <= n + 1; ++i) {
            int cur = 0;
            for (int x : pos)
                cur ^= a[i + x];
            dp[i][len] = max(max(dp[i][len - 1], dp[i + 1][len - 1]), cur);
        }
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r - l + 1] << "\n";
    }
}