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

ll n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    fin >> n >> m;
    if (m < n) {
        cout << "0\n"; return 0;
    }
    vector<ll> a(n);
    for (auto& x : a) fin >> x;
    ll out = 1;
    for (ll i = 0; i < n; i++)
        for (ll j = i+1; j < n; j++)
            out = (out*abs(a[i]-a[j]))%m;
    cout << out << "\n";
}