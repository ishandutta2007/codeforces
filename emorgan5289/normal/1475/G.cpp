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

const int N = 2e5+5;
int a[N], f[N], dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i], f[a[i]]++;
        debug(n);
        for (int i = N; i > 0; i--) {
            dp[i] = f[i];
            for (int j = 2*i; j < N; j += i)
                dp[i] = max(dp[i], f[i]+dp[j]);
        }
        debug(dp[1]);
        cout << n-dp[1] << "\n";
        for (int i = 0; i < n; i++)
            f[a[i]] = 0;
    }
}