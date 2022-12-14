#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int _t;
    cin >> _t;
    while (_t--) []{
        int n;
        cin >> n;
        vt<int> a(n);
        for (int& i : a) cin >> i;
        int mn = *min_element(all(a));
        vt<int> b(a);
        sort(all(b));
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && a[i] % mn) return cout << "NO\n", 0;
        }
        
        return cout << "YES\n", 0;
    }();
}