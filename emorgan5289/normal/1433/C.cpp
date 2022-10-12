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
        int ans = -2;
        int m = *max_element(all(a));
        for (int i = 0; i < n; i++) {
            if (a[i] == m && ((i != 0 && a[i] > a[i-1]) || (i != n-1 && a[i] > a[i+1])))
                ans = i;
        }
        cout << ans+1 << "\n";
    }
}