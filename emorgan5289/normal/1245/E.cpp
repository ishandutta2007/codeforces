#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    vector<int> a(100, -1);
    vector<double> dp(100, 1.0);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            int x; fin >> x;
            if (x == 0) continue;
            a[10*(9-i)+(i&1 ? j : 9-j)] = 10*(9-i+x)+((i-x)&1 ? j : 9-j);
        }
    dp[99] = 0.0;
    dp[98] = dp[97] = dp[96] = dp[95] = dp[94] = 6.0;
    for (int i = 93; i >= 0; i--)
        for (int j = i+1; j < i+7; j++)
            dp[i] += (a[j] == -1 ? dp[j] : min(dp[j], dp[a[j]]))/6.0;
    debug(dp);
    cout << setprecision(20) << dp[0] << "\n";
}