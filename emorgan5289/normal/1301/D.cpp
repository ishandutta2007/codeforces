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

#define t(x) to_string(x)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, m, k; fin >> n >> m >> k;
    if (k > 4*n*m - 2*n - 2*m) {
        cout << "NO\n"; return 0;
    }
    cout << "YES\n";

    vector<pair<ll, string>> path;
    path.pb({m-1, "R"});
    path.pb({m-1, "L"});
    for (ll i = 0; i < n-1; i++) {
        path.pb({1, "D"});
        path.pb({m-1, "RUD"});
        path.pb({m-1, "L"});
    }
    path.pb({n-1, "U"});

    vector<string> out;

    for (auto& [x, s] : path) {
        if (k >= x*s.size()) {
            k -= x*s.size();
            if (x > 0)
                out.pb(t(x)+" "+s+"\n");
        } else {
            if (k/s.size() > 0)
                if (k/s.size() > 0)
                    out.pb(t(k/s.size())+" "+s+"\n");
            k -= (k/s.size())*s.size();
            assert(k <= s.size());
            if (k > 0)
                out.pb("1 "+s.substr(0, k)+"\n");
            break;
        }
    }

    cout << out.size() << "\n";
    for (auto& s : out) cout << s;
}