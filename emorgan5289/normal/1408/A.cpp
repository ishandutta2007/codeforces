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
        vector<int> b(n); for (auto& x : b) cin >> x;
        vector<int> c(n); for (auto& x : c) cin >> x;
        vector<int> p(n);
        p[0] = a[0];
        for (int i = 1; i < n-1; i++) {
            if (a[i] != p[i-1]) {
                p[i] = a[i];
            }
            else if (b[i] != p[i-1]) {
                p[i] = b[i];
            }
            else if (c[i] != p[i-1]) {
                p[i] = c[i];
            }
        }
        if (a[n-1] != p[0] && a[n-1] != p[n-2]) {
            p[n-1] = a[n-1]; 
        }
        else if (b[n-1] != p[0] && b[n-1] != p[n-2]) {
            p[n-1] = b[n-1];
        }
        else if (c[n-1] != p[0] && c[n-1] != p[n-2]) {
            p[n-1] = c[n-1];
        }
        for (auto& x : p) cout << x << " ";
        cout << "\n";
    }
}