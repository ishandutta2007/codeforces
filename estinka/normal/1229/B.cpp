#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <array>
typedef long long ll;
typedef long double ld;
using namespace std;

ll gcd(ll a, ll b)
{
    if (a < b) swap(a, b);
    while (b)
    {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
const int maxn = 1e5 + 128;
const ll mod = 1e9 + 7;
vector<vector<int> > g(maxn);
vector<int> d(maxn, 0);
vector<ll> x(maxn);
ll ans = 0;
void dfs(int v, int p, vector<pair<ll, int> > a)
{
    for (pair<ll, int>& i : a) i.first = gcd(i.first, x[v]);
    a.push_back({ x[v], v });
    vector<pair<ll, int> > nwa;
    for (int i = 0; i < a.size(); i++) if (i == a.size() - 1 || a[i].first != a[i + 1].first) nwa.push_back(a[i]);
    for (int i = 0; i < nwa.size(); i++)
    {
        ans += ((nwa[i].first % mod) * 1ll * (d[nwa[i].second] - (i ? d[nwa[i - 1].second] : -1))) % mod;
        ans %= mod;
    }
    for (int i : g[v])
    {
        if (i == p) continue;
        d[i] = d[v] + 1;
        dfs(i, v, nwa);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0, a, b; i < n - 1; i++)
    {
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    dfs(0, -1, vector<pair<ll, int> >());
    cout << ans << "\n";
    return 0;
}