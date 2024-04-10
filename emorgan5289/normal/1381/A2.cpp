#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<int> o;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        o.clear();

        for (int i = n-2; i >= 0; i -= 2) {
            if (a[i] == b[i] && a[i+1] != b[i+1])
                o.pb(i+1), o.pb(0), o.pb(i+1);
            if (a[i] != b[i] && a[i+1] == b[i+1])
                o.pb(i), o.pb(0), o.pb(i);
            if (a[i] != b[i] && a[i+1] != b[i+1]) {
                if (a[i] == a[i+1])
                    o.pb(i+1), o.pb(1), o.pb(i+1);
                else {
                    o.pb(i), o.pb(i+1), o.pb(i);
                    if (i != 0) o.pb(i-1); 
                }
            }
        }

        if (n&1 && a[0] != b[0]) o.pb(0);

        cout << o.size();
        for (auto& x : o) cout << " " << x+1;
        cout << "\n";
    }
}