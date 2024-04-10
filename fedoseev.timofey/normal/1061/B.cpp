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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = n;
    int cur = a.back();
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (cur == 0) continue;
        if (a[i] >= cur) --cur;
        else {
            ans += cur - a[i];
            cur = a[i] - 1;
        }
    }
    ans += cur;
    ll sum = 0;
    for (auto x : a) sum += x;
    cout << sum - ans << '\n';
}