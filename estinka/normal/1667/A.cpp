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

ll divup(ll a, ll b) // chceme najblizsie VACSIE cislo
{
    return a / b + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 1e18;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        vector<ll> b(n, 0);
        ll sum = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            ll k = divup(b[j + 1], a[j]);
            b[j] = k * a[j];
            sum += k;
        }
        for (int j = i + 1; j < n; j++)
        {
            ll k = divup(b[j - 1], a[j]);
            b[j] = k * a[j];
            sum += k;
        }
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}