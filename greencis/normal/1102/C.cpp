#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, x, y, a[105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    if (x > y) cout << n;
    else {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] <= x)
                ++cnt;
        cout << (cnt + 1) / 2;
    }
}