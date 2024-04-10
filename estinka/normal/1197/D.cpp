#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <chrono>
#include <random>
#include <map>
#include <bitset>
typedef long long ll;
using namespace std;

const ll minf = -1e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> best(m, minf);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) if (best[j] != minf) best[j] += a[i];
        best[i % m] -= k;
        best[i % m] = max(best[i % m], a[i] - k);
        ans = max(ans, *max_element(best.begin(), best.end()));
    }
    cout << ans << "\n";
    return 0;
}