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
    sort(a.begin(), a.end());
    vector <int> used(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++ans;
            used[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] % a[i] == 0) {
                    used[j] = 1;
                }
            }
        }
    }
    cout << ans << '\n';
}