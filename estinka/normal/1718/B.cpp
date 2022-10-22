#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxk = 60;
vector<ll> f(maxk, 0);
ll encode(ll n)
{
    ll ans = 0;
    for (int i = maxk - 1; i > 0; i--)
    {
        if (f[i] <= n)
        {
            ans |= (1ll << (ll)i);
            n -= f[i];
        }
    }
    return ans >> 1ll;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    f[0] = f[1] = 1;
    for (int i = 2; i < maxk; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<ll> f(maxk, 0);
        vector<ll> c(k);
        bool ok = false;
        for (int i = 0; i < k; i++)
        {
            cin >> c[i];
            ll e = encode(c[i]);
            for (ll j = 0; j < maxk; j++) if (e & (1ll << j)) f[j]++;
        }
        for (int i = 0; i < k; i++) // to ktore dostane prvu jednotku
        {
            ll e = encode(c[i]);
            ll e1 = encode(c[i] - 1);
            if (e1 & 1ll) continue;
            bool bad = false, zero = false;
            for (ll j = 0; j < maxk; j++)
            {
                ll f2 = f[j];
                if (e & (1ll << j)) f2--;
                if (e1 & (1ll << j)) f2++;

                if (f2 > 1) bad = true;
                if (zero && f2) bad = true;
                if (!f2) zero = true;
            }
            if (!bad) ok = true;
        }
        //cout << "                       ";
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}