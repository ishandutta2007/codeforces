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
#else
#include "../../debug.cpp"
#endif

const int maxn = 400005;
ll s[20], p[20][20], dp[1<<20];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        s[a]++;
        for (int j = 0; j < 20; j++)
            if (j != a)
                p[a][j] += s[j];
    }
    fill(dp, dp+(1<<20), inf_ll);
    dp[0] = 0;
    for (int i = 0; i < 1<<20; i++)
        for (int j = 0; j < 20; j++)
            if (i&(1<<j)) {
                ll c = 0;
                for (int k = 0; k < 20; k++)
                    if (i&(1<<k))
                        c += p[j][k];
                dp[i] = min(dp[i], dp[i^(1<<j)]+c);
            }
    cout << dp[(1<<20)-1] << "\n";
}