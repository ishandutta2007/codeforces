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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back((int)1e3 + 1);
    a.insert(a.begin(), 0);
    n += 2;
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i - 1] + 1 == a[i] && a[i] + 1 == a[i + 1]) {
            ++cnt;
        }
        else {
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}