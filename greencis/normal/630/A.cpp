#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll binpow(ll x, ll deg) {
    if (deg == 0) return 1;
    if (deg % 2) return (x * binpow(x, deg - 1)) % 100;
    x = binpow(x, deg / 2);
    return (x * x) % 100;
}

int main()
{
    ll n;
    cin >> n;
    cout << 25;
    return 0;
}