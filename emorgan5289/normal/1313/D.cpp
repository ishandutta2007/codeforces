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
    int n, m, k; fin >> n >> m >> k;
    vector<array<int, 3>> a(2*n); // (x, type, id)
    for (int i = 0; i < n; i++) {
        fin >> a[2*i][0] >> a[2*i+1][0];
        a[2*i][1] = 0; a[2*i+1][1] = 1;
        a[2*i][2] = a[2*i+1][2] = i;
    }
    sort(all(a));
    vector<ll> dp(1<<k, 0), bit(n, 0);
    ll mask = (1<<k)-1, px = 0;
    for (auto& [x, t, i] : a) {
        for (int j = 0; j < 1<<k; j++)
            if (__builtin_popcount(j)&1)
                dp[j] += x-px;
        if (t == 0) {
            for (int j = 0; j < k; j++)
                if (mask&(1<<j)) {
                    mask ^= bit[i] = 1<<j;
                    break;
                }
            for (int j = 0; j < 1<<k; j++) {
                if (j&bit[i]) {
                    dp[j] = dp[j^bit[i]];
                    if (__builtin_popcount(j)&1)
                        dp[j]++;
                    else
                        dp[j]--;
                }
            }
        } else {
            mask ^= bit[i];
            for (int j = 0; j < 1<<k; j++)
                if ((j&bit[i]) == 0)
                    dp[j] = max(dp[j^bit[i]], dp[j]);
        }
        px = x;
    }
    cout << dp[0] << "\n";
}