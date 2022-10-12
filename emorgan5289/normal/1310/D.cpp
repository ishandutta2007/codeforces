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

mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, k; fin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (auto& row : a) for (auto& x : row) fin >> x;
    ll out = inf_ll;
    vector<int> c(n, -1);
    vector<vector<ll>> dp(k+1, vector<ll>(n));
    for (int t = 0; t < 4000; t++) {
        for (int i = 0; i < n; i++)
            c[i] = randint()%2;
        for (int x = 0; x <= k; x++)
            for (int i = 0; i < n; i++)
                dp[x][i] = inf_ll;
        dp[0][0] = 0;
        for (int x = 1; x <= k; x++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) 
                    if (c[i] != c[j]) {
                        dp[x][i] = min(dp[x][i], dp[x-1][j]+a[j][i]);
                        dp[x][j] = min(dp[x][j], dp[x-1][i]+a[i][j]);
                    }
        out = min(out, dp[k][0]);
    }
    cout << out << "\n";
}