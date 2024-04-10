#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
typedef long long ll;
using namespace std;

int n, m, seed, vmax;
const ll mod = 1e9 + 7;
int rnd()
{
    int rval = seed; seed = ((ll)(seed) * 7ll + 13ll) % mod;
    return rval;
}
ll pwr(ll a, ll b, ll m)
{
    if (!b)return 1;
    ll h = pwr(a, (b >> 1), m);
    h = (h * h) % m;
    if (b & 1) h = (h * a) % m;
    return h;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, ll> b;
    cin >> n >> m >> seed >> vmax;
    vector<int> a(n); b[n] = -1;
    for (int i = 0; i < n; i++)
    {
        a[i] = rnd() % vmax + 1;
        if (!i || a[i] != a[i - 1]) b[i] = a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int op = rnd() % 4 + 1, l = rnd() % n, r = rnd() % n, x; ll y;
        if (l > r) swap(l, r);
        if (op == 3) x = rnd() % (r - l + 1) + 1;
        else x = rnd() % vmax + 1;
        if (op == 4) y = rnd() % vmax + 1;
        //cout << op << " " << l + 1<< " " << r + 1 << " " << x; if (op == 4) cout << " " << y;
        //cout << "\n";
        if (op == 1 || op == 2)
        {
            auto itl = prev(b.upper_bound(l));
            if (itl->first < l)
                b[l] = itl->second;
            auto itr = b.upper_bound(r);
            if (itr != b.end() && itr->first != r + 1)
                b[r + 1] = prev(itr)->second;
            if (op == 1)
            {
                for (auto it = b.lower_bound(l); it != b.end() && it->first <= r; it++)
                {
                    it->second += x;
                }
            }
            else
            {
                for (auto it = b.lower_bound(l); it != b.end() && it->first <= r; )
                {
                    auto tmp = next(it);
                    b.erase(it);
                    it = tmp;
                }
                b[l] = x;
            }
        }
        else
        {
            auto itl = prev(b.upper_bound(l)), itr = b.upper_bound(r);
            if (op == 3)
            {
                vector<pair<ll, int> > val;
                for (auto it = itl; it != itr; it++) val.push_back({ it->second, min(r + 1, next(it)->first) - max(l, it->first) });
                sort(val.begin(), val.end()); x--;
                for (int i=0;i<val.size();i++)
                {
                    if (val[i].second > x)
                    {
                        cout << val[i].first << "\n";
                        break;
                    }
                    x -= val[i].second;
                }
            }
            else
            {
                ll ans = 0;
                for (auto it = itl; it != itr; it++)
                {
                    ll how_many = min(r + 1, next(it)->first) - max(l, it->first);
                    //cout << pwr(it->second, x, y) << "\n";
                    ans = (ans + pwr(it->second % y, x, y) * how_many) % y;
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}