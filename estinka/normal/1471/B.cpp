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
#include <list>
#include <array>
#include <fstream>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        queue<pair<ll, ll> > q;
        ll total = 0;
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            total += a;
            q.push({ a, 1 });
        }
        while (!q.empty())
        {
            pair<ll, ll> p = q.front();
            q.pop();
            if (p.first % x != 0) break;
            else
            {
                total += p.first * p.second;
                q.push({ p.first / x, p.second * x });
            }
        }
        cout << total << "\n";
    }
    return 0;
}