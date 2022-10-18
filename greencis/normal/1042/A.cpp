#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, x, mx, sum;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    int ans = 0;
    if (n * mx >= sum + m)
        ans = mx;
    else
        ans = mx + (m - (n * mx - sum) + n - 1) / n;
    cout << ans << " " << mx + m << endl;
}