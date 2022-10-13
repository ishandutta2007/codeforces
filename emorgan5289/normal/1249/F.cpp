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

int n, k;
int a[205], dp[205][205];
vector<int> adj[205];

void dfs(int r, int p) {
    for (int i : adj[r])
        if (i != p) dfs(i, r);
    int level[205] = {};
    for (int i : adj[r])
        for (int j = 0; j <= k; j++) {
            // debug(r, i, j, dp[i][j]);
            level[j] += dp[i][j];
        }

    for (int m = 1; m <= k; m++)
        dp[r][m] = level[max(m-1, (k-1)/2)];
    dp[r][0] = a[r]+level[k-1];

    // for (int i = 0; i <= k; i++)
    //     debug(r, level[i]);

    for (int i : adj[r])
        for (int j = 0; j <= k-2; j++) {
            int c = dp[i][j]+level[max(k-2-j, (k-1)/2)]-dp[i][max(k-2-j, (k-1)/2)];
            for (int m = 0; m <= k; m++)
                if (min(j, k-2-j) >= m-1)
                    dp[r][m] = max(dp[r][m], c);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    fin >> n >> k; k++;
    for (int i = 0; i < n; i++)
        fin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int x, y; fin >> x >> y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    dfs(0, 0);
    // for (int r = 0; r < n; r++)
    //     for (int m = 0; m <= k; m++)
    //         debug(r, m, dp[r][m]);
    cout << dp[0][0] << "\n";
}