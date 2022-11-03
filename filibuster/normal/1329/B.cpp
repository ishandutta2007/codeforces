#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;


/*
2 1
2

3 3
1 3 1
*/

int sum(int a, int b, int m) {
    int res = (a + b) % m;
    return res;
}

int mul(int a, int b, int m) {
    return a * 1ll * b % m;
}

void solve() {
    int d, m;
    cin >> d >> m;

    int ans = 0;
    vector<int> dp(31, 0);
    dp[0] = 1;
    for(int i = 0; i < dp.size(); i++) {
        int cnt = min(d - (1 << i) + 1, (1 << (i)));
//        cout << i << ' ' << (1 << i) << ' ' << cnt << endl;
        if(cnt <= 0)
            break;
//        cout <<
        for(int j = 0; j <= i; j++) {
            dp[i + 1] = sum(dp[i + 1], mul(dp[j], cnt, m), m);
        }

        ans = sum(ans, dp[i + 1], m);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}