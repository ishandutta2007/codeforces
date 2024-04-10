#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int md = 1e9 + 7;
 
void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}
 
int mul(int a, int b) {
    return ((ll)a * b) % md;
}
 
int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <vector <int>> dp(k + 1, vector <int> (k + 1));
    dp[0][0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= min(n, k); ++j) {
            if (j + 1 <= min(n, k)) add(dp[i + 1][j + 1], mul(dp[i][j], n - j));
            add(dp[i + 1][j], mul(dp[i][j], j));
        }
    }
    int ans = 0;
    for (int j = 1; j <= min(n, k); ++j) {
        add(ans, mul(dp[k][j], power(2, n - j)));
    }
    cout << ans << '\n';
}