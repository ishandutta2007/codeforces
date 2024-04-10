#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2005;
int ml[N], dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, p; cin >> s >> p;
    int n = s.size(), m = p.size();
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == p[k]) k++;
            if (k == m) {
                ml[i] = j-i+1;
                break;
            }
        }
    }
    for (int x = 0; x <= n; x++) {
        dp[x][n] = x == 0 ? 0 : -inf;
        for (int i = n-1; i >= 0; i--) {
            dp[x][i] = dp[x][i+1];
            if (x > 0) cmax(dp[x][i], dp[x-1][i+1]);
            if (ml[i] && x-ml[i]+m >= 0)
                cmax(dp[x][i], dp[x-ml[i]+m][i+ml[i]]+1);
        }
        // debug(vector(dp[x], dp[x]+n+1));
        cout << dp[x][0] << " \n"[x == n];
    }
}