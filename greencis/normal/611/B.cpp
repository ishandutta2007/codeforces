#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll a,b;
vector<ll> v;

int solve(ll x) {
    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
        if (v[i] <= x) ++ans;
    return ans;
}

int main()
{
    for (ll i = 1; i <= 62; ++i) {
        ll cur = (1ll << i) - 1;
        for (ll j = 0; j + 1 < i; ++j)
            v.push_back(cur ^ (1ll << j));
    }

    cin >> a >> b;
    cout << solve(b) - solve(a - 1);


    return 0;
}