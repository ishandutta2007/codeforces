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
    int ans = 0;
    for (int mask = 0; mask < (1 << 4); ++mask) {
        vector <int> b = a;
        int res = 0;
        while (!is_sorted(b.begin(), b.end())) {
            vector <int> c;
            if (mask & (1 << res)) {
                c = vector <int> (b.begin(), b.begin() + (int)b.size() / 2);
            }
            else {
                c = vector <int> (b.begin() + (int)b.size() / 2, b.end());
            }
            ++res;
            b = c;
        }
        ans = max(ans, (int)b.size());
    }
    cout << ans << '\n';
}