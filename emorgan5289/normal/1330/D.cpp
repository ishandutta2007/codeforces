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
        ll d, m; fin >> d >> m;
        ll out = 1;
        // 1
        // 2..3
        // 4..7
        // 8..15
        // debug(d, m);
        for (ll i = 1; i <= d; i *= 2) {
            // debug(i);
            out = (out*(min(d, 2*i-1ll) - i + 2ll))%m;
        }
        out = (out-1ll+m)%m;
        cout << out << "\n";
    }
}