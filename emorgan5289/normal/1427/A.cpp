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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); for (auto& x : a) cin >> x;
        ll s = accumulate(all(a), 0);
        if (s == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (s > 0) sort(all(a), greater<int>());
            else sort(all(a));
            for (auto& x : a) cout << x << " ";
                cout << "\n";
        }
    }
}