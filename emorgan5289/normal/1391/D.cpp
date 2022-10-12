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

const int N = 1e6+5;
char a[N][3];
int dp[N][4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    if (n > 3) return cout << "-1\n", 0;
    if (n == 1) return cout << "0\n", 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[j][i], a[j][i] -= '0';
    if (n == 2) {
        int x = 0, y = 0;
        for (int i = 0; i < m; i++) {
            if (a[i][0]^a[i][1]^(i&1)) x++;
            else y++;
        }
        return cout << min(x, y) << "\n", 0;
    }
    for (int i = 1; i < m; i++) {
        a[i-1][0] ^= a[i-1][1]^a[i][0]^a[i][1];
        a[i-1][1] ^= a[i-1][2]^a[i][1]^a[i][2];
        int x = a[i-1][0] + 2*a[i-1][1];
        for (int j = 0; j < 4; j++)
            dp[i][j] = dp[i-1][3^j^x] + ((j^x) == 3 ? 0 : 1);
    }
    cout << min(dp[m-1][0], 1+min({dp[m-1][1], dp[m-1][2], dp[m-1][3]})) << "\n";
}