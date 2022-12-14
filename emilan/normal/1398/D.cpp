#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

int dp[201][201][201];
int r, g, b;
int ar[200], ag[200], ab[200];

int f(int x, int y, int z) {
    if (dp[x][y][z] == -1) {
        int cur = 0;
        if (x && y) 
            cur = max(cur, ar[x - 1] * ag[y - 1] + f(x - 1, y - 1, z));
        if (x && z)
            cur = max(cur, ar[x - 1] * ab[z - 1] + f(x - 1, y, z - 1));
        if (y && z)
            cur = max(cur, ag[y - 1] * ab[z - 1] + f(x, y - 1, z - 1));
        dp[x][y][z] = cur;
    }
    return dp[x][y][z];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> r >> g >> b;
    rep(i, r) cin >> ar[i];
    rep(i, g) cin >> ag[i];
    rep(i, b) cin >> ab[i];
    sort(ar, ar + r);
    sort(ag, ag + g);
    sort(ab, ab + b);
    rep(i, r + 1) rep(j, g + 1) fill(dp[i][j], dp[i][j] + b + 1, -1);

    cout << f(r, g, b);
}