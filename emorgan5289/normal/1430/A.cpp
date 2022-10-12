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

int dp[2000];
vector<int> d = {3, 5, 7};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[0] = 1;
    for (int i = 1; i < 2000; i++)
        for (auto& x : d)
            dp[i] = dp[i] || (i-x >= 0 && dp[i-x]);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (!dp[n]) cout << "-1\n";
        else {
            int r[10] = {};
            while (n > 0)
                for (auto& x : d)
                    if (n-x >= 0 && dp[n-x])
                        n -= x, r[x]++;
            cout << r[3] << " " << r[5] << " " << r[7] << "\n";
        }
    }
}