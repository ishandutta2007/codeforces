#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0] << "\n";
        exit(0);
    }
    cout << 1 << " " << n << "\n";
    for (ll i = 0; i < n-1; i++)
        cout << -a[i]*n << " ";
    cout << "0 \n";
    cout << 1 << " " << n-1 << "\n";
    for (ll i = 0; i < n-1; i++)
        cout << a[i]*(n-1) << " ";
    cout << "\n";
    cout << n << " " << n << "\n";
    cout << -a[n-1] << "\n";
}