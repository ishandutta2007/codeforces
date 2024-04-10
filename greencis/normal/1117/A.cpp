#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[101005];

int main() {
    ios_base::sync_with_stdio(false);

    int ans = 0, cur = 0, mx = -1;
    cin >> n;
    a[0] = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == mx) ++cur;
        else cur = 0;
        ans = max(ans, cur);
    }
    cout << ans;
}