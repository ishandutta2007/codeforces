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
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    ll ans = 0;
    int cur = 1;
    int cnt = 1;
    bool eq = true;
    for (int i = 0; i < n; ++i) {
        if (eq) {
            if (s[i] != t[i]) {
                cnt = 2;
                eq = false;
            }
        }
        else {
            cnt -= 2;
            cnt *= 2;
            cnt = min(cnt, (int)1e9);
            cnt += 2;
            if (s[i] == 'a') ++cnt;
            if (t[i] == 'b') ++cnt;
            cnt = min(cnt, (int)1e9);
        }
        ans += min(cnt, k);
    }
    cout << ans << '\n';
}