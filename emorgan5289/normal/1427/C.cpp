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

const ll N = 1e5+5;
array<int, 3> a[N];
ll dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int r, n; cin >> r >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    a[0] = {0, 1, 1}; n++;
    for (int i = n-1; i >= 0; i--) {
        auto [t, x, y] = a[i];
        dp[i] = 0;
        for (int j = i+1; j < min(n, i+2005); j++)
            if (abs(a[j][1]-x)+abs(a[j][2]-y)+t <= a[j][0])
                dp[i] = max(dp[i], dp[j]+1);
    }
    cout << dp[0] << "\n";
}