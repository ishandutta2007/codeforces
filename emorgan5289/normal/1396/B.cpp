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
        int c = 0, d = 0, m = 0;
        for (auto& x : a) {
            if (x&1) c++;
            d += x;
            m = max(m, x);
        }
        if (m > d-m) cout << "T\n";
        else cout << (d&1 ? "T" : "HL") << "\n";
    }
}