#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i].first; a[i].second = i;
    }
    vector<int> dp(n+1, inf), pre(n+1);
    dp[0] = 0;
    sort(all(a));
    int m = 0; int r = 0;
    for (int i = 3; i <= n; i++) {
        int best = dp[i-3]-a[i-3].first;
        if (best < m) {
            m = best; r = i-3;
        }
        dp[i] = m+a[i-1].first;
        pre[i] = r;
    }
    vector<int> res(n);
    int x = 1;
    for (int i = n; i > 0; x++) {
        int d = pre[i];
        for (; i > d; i--)
            res[a[i-1].second] = x;
    }
    cout << dp[n] << " " << res[a[0].second] << "\n";
    for (auto y : res) cout << y << " ";
}