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
    string s;
    cin >> s;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int ans = 0;
    for (int t = 0; t < 10000; ++t) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (t < b[i]) {
                cnt += s[i] - '0';
            } else {
                int c = (t - b[i]) / a[i] + 1;
                cnt += (s[i] - '0') ^ (c % 2);
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}