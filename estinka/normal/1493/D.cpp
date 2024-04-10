#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <list>
typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;
const int maxn = 2e5 + 128;
vector<int> lp(maxn, 1), pr;
vector<pair<int, int>> factor(int x)
{
    vector<pair<int, int> > v;
    while (x > 1)
    {
        if (v.empty() || v.back().first != lp[x]) v.push_back({ lp[x], 0 });
        v.back().second++;
        x /= lp[x];
    }
    return v;
}
int gcd(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < maxn; i++)
    {
        if (lp[i] == 1)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i < maxn; j++)
            lp[i * pr[j]] = pr[j];
    }
    int n, q;
    cin >> n >> q;
    vector<int> a(n), in(q), x(q);
    vector<multiset<int> > low(maxn);
    vector<map<int, int> > v(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans = gcd(ans, a[i]);
        vector<pair<int, int> > u = factor(a[i]);
        for (pair<int, int> j : u) low[j.first].insert(j.second), v[i][j.first] = j.second;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> in[i] >> x[i]; in[i]--;
        vector<pair<int, int> > u = factor(x[i]);
        for (pair<int, int> j : u)
        {
            int dif = low[j.first].size() == n ? -*low[j.first].begin() : 0;
            if (v[in[i]][j.first]) low[j.first].erase(low[j.first].find(v[in[i]][j.first]));
            v[in[i]][j.first] += j.second;
            low[j.first].insert(v[in[i]][j.first]);
            dif += *low[j.first].begin();
            if (low[j.first].size() == n)
            {
                for (int k = 0; k < dif; k++) ans = (ans * 1ll * j.first) % mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}