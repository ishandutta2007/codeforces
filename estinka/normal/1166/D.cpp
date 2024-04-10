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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    const ll maxi = 61;
    vector<ll> koeficient(maxi, 0);
    koeficient[1] = 1;
    koeficient[2] = 1;
    for (int i = 3; i < maxi; i++)
    {
        koeficient[i] = koeficient[i - 1] << 1ll;
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll a, b, m;
        cin >> a >> b >> m;
        if (a == b)
        {
            cout << 1 << " " << a << "\n";
            continue;
        }
        vector<ll>ans;
        for (ll k = 2; k < maxi; k++)
        {
            if (koeficient[k] * (a + 1) > b)
            {
                break;
            }
            // vyskusame ci vieme najst postupnost ktora ma
            // k clenov a je m-cute a jej zaciatok je a a jej
            // koniec je b.
            vector<ll>r(k - 1, 1);
            ll last = koeficient[k] * (a + 1ll);
            for (int i = 0; i < k - 1; i++)
            {
                /*while (last + koeficient[k - i - 1] <= b && r[i] < m)
                {
                    r[i]++;
                    last += koeficient[k - i - 1];
                }*/
                ll now = min(m - 1, (b - last) / koeficient[k - i - 1]);
                r[i] += now;
                last += koeficient[k - i - 1] * now;
            }
            if (last != b)
            {
                continue;
            }
            ans.resize(k, 0);
            for (int i = 0; i < k; i++)
            {
                ans[i] += a * koeficient[i + 1];
                if (i < k - 1)
                {
                    for (int j = i + 1; j < k; j++)
                    {
                        ans[j] += koeficient[j - i] * r[i];
                    }
                }
            }
            break;
        }
        if (ans.empty())
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans.size() << " ";
            for (ll& i : ans)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}