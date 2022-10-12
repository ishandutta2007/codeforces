#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 3e5+5, K = 3005;
ll dp[K];
ll left_star[N], p_monster[N], p_star[N];
ll group_end[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(all(a)), sort(all(b));

    dp[0] = -1;
    fill(dp+1, dp+K, inf);
    fill(left_star, left_star+N, -1);

    for (int i = 0; i < m; i++) {
        left_star[b[i]] = i;
        p_star[b[i]] = 1;
    }
    for (int i = 0; i < n; i++)
        p_monster[a[i]] = 1;

    for (int i = 1; i < N; i++) {
        cmax(left_star[i], left_star[i-1]);
        p_monster[i] += p_monster[i-1];
        p_star[i] += p_star[i-1];
    }

    for (int i = n-1; i >= 0; i--)
        group_end[i] = i < n-1 && a[i]+1 == a[i+1] ? group_end[i+1] : i;

    for (int i = 0; i < n; i++) {
        ll x = a[i], mid = 0;

        // monster index i, location x, update mid
        for (int j = 0; j < K; j++) {
            if (dp[j] >= x)
                break;
            ll y = x-(p_monster[x]-(dp[j] == -1 ? 0 : p_monster[dp[j]])-1);
            if (y > x) continue;
            // we can hit any stars in the interval [y, x]
            cmax(mid, j+p_star[x]-(y == 0 ? 0 : p_star[y-1]));
        }

        // monster index i, location x, update dp
        for (int j = 0; j < K; j++) {
            // try to get dp_mid[i]+j stars
            int k = left_star[x]+j;
            // k is the index of the rightmost star we need to cover
            if (k >= m) continue;
            int y = k == -1 ? i : i+max(0ll, b[k]-x);
            // y is the index of the monster needed to do it
            if (y < n)
                cmin(dp[j+mid], a[group_end[y]]);
        }

        for (int j = K-2; j >= 0; j--)
            cmin(dp[j], dp[j+1]);
    }
    for (int i = K-1; i >= 0; i--)
        if (dp[i] < inf) {
            cout << i << "\n";
            break;
        }
}