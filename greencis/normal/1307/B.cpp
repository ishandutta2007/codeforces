#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, a[100100];

int main() {
    ios_base::sync_with_stdio(false);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        cin >> n >> x;
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        int idx = lower_bound(a, a + n, x) - a;
        int ans = -1;
        if (idx < n && a[idx] == x)
            ans = 1;
        else
            ans = max(2, (x + a[n - 1] - 1) / a[n - 1]);
        cout << ans << "\n";
    }
}