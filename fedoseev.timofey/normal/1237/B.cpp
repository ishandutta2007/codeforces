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
    vector <int> a(n), b(n);
    vector <int> tm(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        tm[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    int mn = n;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (tm[b[i]] > mn) {
            ++ans;
        }
        mn = min(mn, tm[b[i]]);
    }
    cout << ans << '\n';
}