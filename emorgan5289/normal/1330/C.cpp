#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, m; fin >> n >> m;
    vector<ll> a(m); for (auto& x : a) fin >> x;
    vector<ll> p(m);
    for (ll i = 0; i < m; i++) {
        p[i] = a[i] + (i == 0 ? 0 : p[i-1]);
        if (n-a[i] < i) {
            cout << "-1\n"; return 0;
        }
    }
    if (p[m-1] < n) {
        cout << "-1\n"; return 0;
    }
    vector<ll> b(m);
    for (ll i = m-1; i >= 0; i--) {
        ll z = i == 0 ? 0 : p[i-1];
        b[i] = min(z, min(n-a[i], (i == m-1 ? inf : b[i+1]-1)));
    }
    for (auto& x : b) cout << x+1 << " ";
    cout << "\n";
}