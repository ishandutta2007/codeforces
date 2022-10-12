#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

ll qry(ll i, ll j) {
    ll x = 0, y = 0;
    cout << "and "<< i+1 << " " << j+1 << endl;
    cin >> x;
    cout << "or "<< i+1 << " " << j+1 << endl;
    cin >> y;
    return x+y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    ll a = qry(0, 1);
    ll b = qry(1, 2);
    ll c = qry(2, 0);
    vector<ll> v(n);
    v[0] = (a-b+c)/2;
    v[1] = (a+b-c)/2;
    v[2] = (-a+b+c)/2;
    for (int i = 3; i < n; i++)
        v[i] = qry(0, i)-v[0];
    sort(all(v));
    cout << "finish " << v[k-1] << endl;
}