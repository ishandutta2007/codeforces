#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, k; cin >> n >> k;
    vector<ll> a(n), d(n-1); for (auto& x : a) cin >> x;
    ll out = 0;
    for (int i = 0; i < n-1; i++)
        d[i] = a[i+1]-a[i];
    sort(all(d), greater<ll>());
    for (int i = k-1; i < n-1; i++)
        out += d[i];
    cout << out << "\n";
}