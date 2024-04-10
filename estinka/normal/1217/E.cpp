#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
//#define DEBUG
//#define RANDOM
typedef long long ll;
typedef long double ld;
using namespace std;

const ll d = 10;
const ll inf = 1e11;
class intervalac
{
    vector<int> l, r;
    vector<pair<ll, ll>*> best;
    inline void merge(int vr)
    {
        int lf = vr * 2 + 1, ri = vr * 2 + 2;
        for (int i = 0; i < d; i++)
        {
            if (best[lf][i].first < best[ri][i].first)
            {
                best[vr][i].first = best[lf][i].first;
                best[vr][i].second = min(best[lf][i].second, best[ri][i].first);
            }
            else
            {
                best[vr][i].first = best[ri][i].first;
                best[vr][i].second = min(best[ri][i].second, best[lf][i].first);
            }
        }
    }
    inline void change(int vr, ll nw)
    {
        string s = to_string(nw);
        reverse(s.begin(), s.end());
        s.resize(d, '0');
        for (int i = 0; i < d; i++)
        {
            if (s[i] != '0')
            {
                best[vr][i] = { nw, inf };
            }
            else
            {
                best[vr][i] = { inf, inf };
            }
        }
    }
public:
    void init(int n)
    {
        int n2 = 1;
        while (n2 < n)
        {
            n2 <<= 1;
        }
        l.resize(n2 * 2);
        r.resize(n2 * 2);
        best.resize(n2 * 2);
        for (int i = n2 - 1; i < n2 * 2; i++)
        {
            best[i] = new pair<ll, ll>[d];
            for (int j = 0; j < d; j++)
            {
                best[i][j] = { inf, inf };
            }
            l[i] = r[i] = i - (n2 - 1);
        }
        for (int i = n2 - 2; i >= 0; i--)
        {
            best[i] = new pair<ll, ll>[d];
            merge(i);
            l[i] = l[i * 2 + 1];
            r[i] = r[i * 2 + 2];
        }
    }
    pair<ll, ll> mini(int li, int ri, int d, int vr = 0)
    {
        // najde minimalne cislo v intervale, ktore ma cifru na pozicii d
        if (li > r[vr] || ri < l[vr])
        {
            return { inf, -1 };
        }
        if (li <= l[vr] && r[vr] <= ri)
        {
            return best[vr][d];
        }
        pair<ll, ll> p1 = mini(li, ri, d, vr * 2 + 1);
        pair<ll, ll> p2 = mini(li, ri, d, vr * 2 + 2);
        if (p1.first < p2.first)
        {
            return { p1.first, min(p1.second, p2.first) };
        }
        else
        {
            return { p2.first, min(p2.second, p1.first) };
        }
    }
    void update(int i, ll x, int vr = 0)
    {
        if (i > r[vr] || i < l[vr])
        {
            return;
        }
        if (i == l[vr] && r[vr] == i)
        {
            change(vr, x);
            return;
        }
        update(i, x, vr * 2 + 1);
        update(i, x, vr * 2 + 2);
        merge(vr);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll pow10[d + 1];
    pow10[0] = 1;
    for (int i = 1; i <= d; i++)
    {
        pow10[i] = pow10[i - 1] * 10ll;
    }
    int n, m;
    cin >> n >> m;
    vector<ll>a(n);
    intervalac in;
    in.init(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        in.update(i, a[i]);
    }
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            ll x;
            cin >> i >> x;
            i--;
            in.update(i, x);
            a[i] = x;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--; r--;
            ll ans = inf;
            for (int i = 0; i < d; i++)
            {
                if (pow10[i] * 2ll >= ans)
                {
                    break;
                }
                pair<ll, ll> p1 = in.mini(l, r, i);
                ans = min(p1.first + p1.second, ans);
            }
            if (ans >= 1e10)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << ans << "\n";
            }
        }
    }
    return 0;
}