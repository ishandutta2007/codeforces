#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, cl, ce, v;
int l[100105], e[100105];
int q, xa, ya, xb, yb;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> cl >> ce >> v;
    for (int i = 0; i < cl; ++i) cin >> l[i];
    for (int i = 0; i < ce; ++i) cin >> e[i];
    cin >> q;
    while (q--) {
        cin >> ya >> xa >> yb >> xb;
        if (ya == yb) { cout << abs(xa - xb) << "\n"; continue; }
        int ans = 2e9;
        int li = lower_bound(l, l + cl, xa) - l;
        if (li < cl)
            ans = min(ans, abs(xa - l[li]) + abs(ya - yb) + abs(l[li] - xb));
        if (li > 0)
            ans = min(ans, abs(xa - l[li - 1]) + abs(ya - yb) + abs(l[li - 1] - xb));
        int ei = lower_bound(e, e + ce, xa) - e;
        if (ei < ce)
            ans = min(ans, abs(xa - e[ei]) + (abs(ya - yb) + v - 1) / v + abs(e[ei] - xb));
        if (ei > 0)
            ans = min(ans, abs(xa - e[ei - 1]) + (abs(ya - yb) + v - 1) / v + abs(e[ei - 1] - xb));
        cout << ans << "\n";
    }
}