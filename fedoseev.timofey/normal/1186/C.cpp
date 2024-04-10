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
    string a, b;
    cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    for (auto c : b) cnt1 += (c == '0');
    for (int i = 0; i < (int)b.size(); ++i) cnt2 += (a[i] == '0');
    int ans = 0;
    for (int i = 0; i + b.size() <= a.size(); ++i) {
        ans += (abs(cnt1 - cnt2) % 2 == 0);
        cnt2 -= (a[i] == '0');
        if (i + b.size() < a.size()) {
            cnt2 += (a[i + (int)b.size()] == '0');
        }
    }
    cout << ans << '\n';
}