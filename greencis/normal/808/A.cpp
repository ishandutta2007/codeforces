#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int main()
{
    vector<ll> v;
    for (ll i = 1; i <= 9; ++i) {
        ll x = i;
        for (int iter = 11; iter--; )
            v.push_back(x), x *= 10;
    }
    sort(v.begin(), v.end());

    ll n;
    cin >> n;
    cout << *lower_bound(v.begin(), v.end(), n + 1) - n;

    return 0;
}