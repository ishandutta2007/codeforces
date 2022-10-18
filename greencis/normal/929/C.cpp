#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, c, va[1005], vb[1005], vc[1005];

int main() {
    cin >> a >> b >> c;
    for (int i = 0; i < a; ++i)
        cin >> va[i];
    for (int i = 0; i < b; ++i)
        cin >> vb[i];
    for (int i = 0; i < c; ++i)
        cin >> vc[i];
    sort(va, va + a);
    sort(vb, vb + b);
    sort(vc, vc + c);
    ll ans = 0;
    int ai = 0, bi = 0, ci = 0;
    while (ai < a && bi < b && ci < c) {
        if (va[ai] <= vb[bi] && va[ai] <= vc[ci]) {
            int upper = va[ai++] * 2;
            ll bcnt = lower_bound(vb + bi, vb + b, upper + 1) - (vb + bi);
            ll ccnt = lower_bound(vc + ci, vc + c, upper + 1) - (vc + ci);
            ans += bcnt * (bcnt - 1) / 2 * ccnt * (ccnt - 1) * (ccnt - 2) / 6;
        } else if (vb[bi] <= va[ai] && vb[bi] <= vc[ci]) {
            int upper = vb[bi++] * 2;
            ll acnt = lower_bound(va + ai, va + a, upper + 1) - (va + ai);
            ll bcnt = lower_bound(vb + bi, vb + b, upper + 1) - (vb + bi);
            ll ccnt = lower_bound(vc + ci, vc + c, upper + 1) - (vc + ci);
            ans += acnt * bcnt * ccnt * (ccnt - 1) * (ccnt - 2) / 6;
        } else {
            int upper = vc[ci++] * 2;
            ll acnt = lower_bound(va + ai, va + a, upper + 1) - (va + ai);
            ll bcnt = lower_bound(vb + bi, vb + b, upper + 1) - (vb + bi);
            ll ccnt = lower_bound(vc + ci, vc + c, upper + 1) - (vc + ci);
            ans += acnt * bcnt * (bcnt - 1) / 2 * ccnt * (ccnt - 1) / 2;
        }
    }
    cout << ans;
}