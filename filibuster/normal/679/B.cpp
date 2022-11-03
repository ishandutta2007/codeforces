#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

int sqrt3(li n) {
    int l = 1, r = 1e5 + 13;
    while(r - l > 1) {
        int m = (l + r) / 2;

        if(m * 1ll * m * m <= n)
            l = m;
        else
            r = m;
    }

    return l;
}

li sq3(int x) {
    return x * 1ll * x * x;
}

map<li, pair<int, li>> dp;

pair<int, li> calc(li n) {
    if(n < 8) {
        return {n, n};
    }

    if(dp.count(n)) {
        return dp[n];
    }

    int x = sqrt3(n);
//    if(x * 1ll * x * x == n)
//        x--;

    auto res1 = calc(n - sq3(x));
    auto res2 = calc(sq3(x) - sq3(x - 1) - 1);

    if(res1.f >= res2.f) {
        return dp[n] = {res1.f + 1, res1.s + sq3(x)};
    } else {
        return dp[n] = {res2.f + 1, res2.s + sq3(x - 1)};
    }
}




//int dp[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int mx = 1;
//    dp[1] = 1;
//    for(int i = 2; i < N; i++) {
//        int x = sqrt3(i);
//        dp[i] = dp[i - x * x * x] + 1;
////        cout << i << ' ' << dp[i] << endl;
//        mx = max(mx, dp[i]);
//    }
//    cout << mx << endl;

    li n;
    cin >> n;

    auto res = calc(n);
    cout << res.f << ' ' << res.s << endl;
}