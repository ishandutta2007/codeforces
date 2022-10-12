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
    int t; fin >> t;
    while (t--) {
        ll n; fin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            fin >> a[i] >> b[i];

        ll out = 0;
        for (auto& x : a) out += x;
        for (int i = 0; i < n; i++)
            out -= min(b[i], a[(i+1)%n]);
        ll m = inf_ll;
        for (int i = 0; i < n; i++)
            m = min(m, min(b[i], a[(i+1)%n]));
        out += m;
        cout << out << "\n";        
    }
}