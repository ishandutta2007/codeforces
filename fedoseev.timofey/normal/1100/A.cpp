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
    vector <int> a(n);
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == -1) ++a1;
        else ++a2;
    }
    int mx = 0;
    for (int b = 0; b < n; ++b) {
        int c1 = 0, c2 = 0;
        for (int i = -300; i <= 300; ++i) {
            int cur = b + i * k;
            if (0 <= cur && cur < n) {
                if (a[cur] == -1) ++c1;
                else ++c2;
            }
        }
        mx = max(mx, abs((a1 - c1) - (a2 - c2)));
    }
    cout << mx << '\n';
}