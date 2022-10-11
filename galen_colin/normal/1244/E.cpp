// testing code; not mine

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()
#define intvect vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; i < n; ++i)
#define ld long double
#define deb(x) cout << #x << " " << x << '\n';
#define pb push_back
#define pob pop_back
#define lcm(a, b) (a / __gcd(a, b) * b)
#define F first
#define S second
#define ull unsigned long long

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

const ll mod = 1e9 + 7;
const ll N = (ll)1e5 + 5;

void vjudge()
{
#ifndef RTE
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    intvect a(n);
    intvect pre(n, 0);
    fo(i, n) cin >> a[i];
    sort(all(a));
    pre[0] = a[0];
    fo(i, n) if (i != 0) pre[i] = pre[i - 1] + a[i];
    int res = INT_MAX;
    intvect yes(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int sm = pre[n - 1] - pre[i];
        sm -= ((n - 1 - i) * a[i]);
        yes[i] = sm;
    }
    reverse(all(yes));
    for (int i = 0; i < n; i++)
    {
        // let's say used first i numbers
        int used = (i + 1) * a[i] - pre[i];
        int have = k - used;

        if (have < 0)
            continue;
        int p = a[n - 1];
        int l = a[i], r = a[n - 1] + 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            int x = lower_bound(a.begin() + i, a.end(), m) - a.begin();
            int cost = pre[n - 1] - pre[x] + a[x] - (n - x) * m;
            if (cost <= have)
            {
                p = min(p, m);
                r = m;
            }
            else
                l = m + 1;
        }
        res = min(res, p - a[i]);
    }
    for (int i = 0; i < n; i++)
        yes[i] = (i + 1) * a[i] - pre[i];
    for (int i = n - 1; i >= 0; i--)
    {
        int used = (pre[n - 1] - pre[i]) - (n - i - 1) * a[i];
        int have = k - used;
        if (have < 0)
            continue;

        int l = a[0], r = a[i];
        int u = a[0];
        while (l <= r)
        {
            int m = (l + r) / 2;
            int x = upper_bound(a.begin(), a.begin() + i + 1, m) - a.begin() - 1;
            if (x >= n) x = n - 1;
            int cost = m * (x + 1) - pre[x];
            if (cost > have)
                r = m - 1;
            else
            {
                u = max(u, m);
                l = m + 1;
            }
        }
        // cout << u << " ";
        res = min(res, a[i] - u);
    }
    // cout << res << " ";
    cout << res;
}

int32_t main()
{
    vjudge();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}