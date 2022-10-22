#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <array>
typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;
void recalculate(vector<ll>& pv, vector<ll>& dp, vector<int >& v)
{
    ll sum = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        sum = (sum + pv[i]) % mod;
        dp[i] = (sum * 1ll * v[i]) % mod;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, l;
    cin >> n >> l >> k;
    vector<int> a(n, 0);
    map<int, int> m;
    m[-1] = 0;
    vector<int> last;
    map<int, int> m2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
        if (l % n != 0 && (l - 1) % (ll)n == i) m2 = m;
    }
    vector<int> v;
    for (pair<int, int> i : m) v.push_back(i.second), m2[i.first] += 0;
    for (pair<int, int> i : m2) last.push_back(i.second);
    ll num = min(k, l / n);
    ll ans = 0;
    vector<vector<ll> > dp(num + 1, vector<ll>(v.size(), 0));
    dp[0][0] = 1;
    for (int i = 1; i <= num; i++) recalculate(dp[i - 1], dp[i], v);
    vector<ll> dp_last(v.size(), 0);
    for (int i = 0; i <= min(k - 1, num); i++)
    {
        dp_last.assign(v.size(), 0);
        recalculate(dp[i], dp_last, last);
        for (int j = 0; j < v.size(); j++) ans = (ans + dp_last[j]) % mod;
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            ans = (ans + (((l / n - (ll)(i - 1)) % mod) * 1ll * dp[i][j]) % mod) % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}