#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector <int> b;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) b.push_back(a[i]);
        else b.insert(b.begin(), a[i]);
    }
    for (auto x : b) {
        cout << x << ' ';
    }
}