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
    vector <int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        --a[i];
    }
    int ans = 0;
    vector <int> last(n, -1), first(n, k);
    for (int i = 0; i < k; ++i) {
        last[a[i]] = i;
    }
    for (int i = k - 1; i >= 0; --i) {
        first[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int k = i + j;
            if (i >= 0 && i < n && k >= 0 && k < n && last[i] < first[k]) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}