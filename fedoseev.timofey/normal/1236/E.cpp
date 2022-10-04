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
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    vector <int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    map <int, int> goL;
    vector <int> whereL(m);
    for (int i = m - 1; i >= 0; --i) {
        if (goL.count(a[i] + i)) {
            whereL[i] = goL[a[i] + i];
        } else {
            whereL[i] = max(0, a[i] - (m - 1 - i));
        }
        goL[a[i] + i - 1] = whereL[i];
    }
    map <int, int> goR;
    vector <int> whereR(m);
    for (int i = m - 1; i >= 0; --i) {
        if (goR.count(a[i] - i)) {
            whereR[i] = goR[a[i] - i];
        } else {
            whereR[i] = min(n - 1, a[i] + (m - 1- i));
        }
        goR[a[i] - i + 1] = whereR[i];
    }
    goL.clear(), goR.clear();
    for (int i = m - 1; i >= 0; --i) {
        goR[a[i] - i - 1] = whereR[i];
    }
    for (int i = m - 1; i >= 0; --i) {
        goL[a[i] + i + 1] = whereL[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = i, r = i;
        if (goL.count(i)) {
            l = goL[i];
        } else {
            l -= m + 1;
        }
        if (goR.count(i)) {
            r = goR[i];
        } else {
            r += m + 1;
        }
        l = max(l, 0);
        r = min(r, n - 1);
        ans += r - l + 1;
    }
    cout << ans << '\n';
}