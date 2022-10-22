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

const ll mod = 1e9 + 7, inf = 1e18;
const int maxn2 = 1 << 18;
vector<ll> sum(maxn2 * 2, 0), mini(maxn2 * 2, inf);
vector<int> l(maxn2 * 2), r(maxn2 * 2);
void recalc(int vr)
{
    mini[vr] = min(mini[vr * 2 + 1], mini[vr * 2 + 2]);
    sum[vr] = 0;
    if (mini[vr] == mini[vr * 2 + 1]) sum[vr] = sum[vr * 2 + 1];
    if (mini[vr] == mini[vr * 2 + 2]) sum[vr] = (sum[vr] + sum[vr * 2 + 2]) % mod;
}
void update(int x, ll nwsum, ll nwmini, int vr = 0)
{
    if (x < l[vr] || x > r[vr]) return;
    if (x == l[vr] && x == r[vr])
    {
        sum[vr] = nwsum; mini[vr] = nwmini;
        return;
    }
    update(x, nwsum, nwmini, vr * 2 + 1);
    update(x, nwsum, nwmini, vr * 2 + 2);
    recalc(vr);
}
pair<ll, ll> query(int li, int ri, int vr = 0)
{
    if (ri < l[vr] || li > r[vr]) return { inf, 0 };
    if (li <= l[vr] && r[vr] <= ri) return { mini[vr], sum[vr] };
    pair<ll, ll> p1 = query(li, ri, vr * 2 + 1), p2 = query(li, ri, vr * 2 + 2);
    if (p1.first < p2.first) return p1;
    if (p2.first < p1.first) return p2;
    return { p1.first, p2.second + p1.second };
}
class info
{
public:
    ll mini, sum;
    int i;
    info(ll MINI, ll SUM, int I) :mini(MINI), sum(SUM), i(I) {}
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = maxn2 - 1; i < maxn2 * 2; i++) l[i] = r[i] = i - (maxn2 - 1);
    for (int i = maxn2 - 2; i >= 0; i--) l[i] = l[i * 2 + 1], r[i] = r[i * 2 + 2];
    int n;
    cin >> n;
    vector<int> in(n), out(n);
    vector<pair<int, int> > ev;
    vector<pair<ll, ll> > dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> out[i] >> in[i];
        ev.push_back({ in[i], i + 1 });
        ev.push_back({ out[i], -i - 1 });
    }
    sort(ev.begin(), ev.end());
    set<pair<int, int> > op;
    for (int i = 0; i < 2 * n; i++)
    {
        int j = abs(ev[i].second) - 1;
        if (ev[i].second >= 0) // in -> we need to calculate dp
        {
            pair<ll, ll> qu = query(0, n - 1);
            if (qu.first == inf) qu = { 0, 1 };
            qu.first += in[j] - out[j];
            dp[j] = qu;
        }
        else // out -> we need to add dp
        {
            while (!op.empty() && op.begin()->first <= in[j])
            {
                int j2 = op.begin()->second;
                update(j2, 0, inf);
                op.erase(op.begin());
            }
            update(j, dp[j].second, dp[j].first);
            op.insert({ out[j], j });
        }
    }
    ll mymin = inf, mysum = 0;
    for (pair<int, int> i : op)
    {
        dp[i.second].first += out[i.second];
        if (mymin > dp[i.second].first) mymin = dp[i.second].first, mysum = 0;
        if (mymin == dp[i.second].first) mysum = (mysum + dp[i.second].second) % mod;
    }
    cout << mysum << "\n";
    return 0;
}