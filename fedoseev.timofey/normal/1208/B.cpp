#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map <int, int> lst;
    for (int i = 0; i < n; ++i) {
        lst[a[i]] = i;
    }
    set <int> hv;
    int minR = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (hv.count(a[i])) {
            minR = i;
            break;
        }
        hv.insert(a[i]);
    }
    if (minR == -1) {
        cout << "0\n";
        return 0;
    }
    int ans = n;
    for (int l = 0; l < n; ++l) {
        bool bad = false;
        hv.clear();
        int r = max(l, minR);
        for (int i = 0; i < l; ++i) {
            if (hv.count(a[i])) {
                bad = true;
                break;
            }
            hv.insert(a[i]);
            if (lst.count(a[i])) r = max(r, lst[a[i]]);
        }
        if (!bad) ans = min(ans, r - l + 1);
    }
    cout << ans << '\n';
}