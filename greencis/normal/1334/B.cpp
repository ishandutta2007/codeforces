#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int a[100100];

int main() {
    ios_base::sync_with_stdio(false);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n, greater<>());
        int ans = 0;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (sum >= ll(i + 1) * x)
                ans = i + 1;
        }
        cout << ans << endl;
    }
}