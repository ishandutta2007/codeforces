#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

vector<ll> solve(vector<ll> v) {
    int n = (int)v.size();
    if (n == 0) return v;
    ll g = 0;
    for (int i = 0; i < n; ++i)
        g = gcd(g, v[i]);
    vector<ll> odd, even;
    for (int i = 0; i < n; ++i) {
        ((v[i] / g) % 2 == 0 ? even : odd).push_back(v[i]);
    }
    vector<ll> odd_addon = solve(even);
    for (ll x : odd_addon)
        odd.push_back(x);
    if (odd.size() < even.size())
        return odd;
    return even;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    auto ans = solve(v);
    cout << ans.size() << endl;
    for (ll x : ans) cout << x << " ";
}