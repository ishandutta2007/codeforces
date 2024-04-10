#include <bits/stdc++.h>
using namespace std;

using ll = int;
#define endl '\n'

ll f(ll l, ll r, const vector<ll>& a, const ll& n) {
    if(l > r) return 0;
    l = max(1, l);
    r = min(r, n);
    assert(l >= 1 and l <= n and r >= 1 and r <= n);
    assert(r < a.size());
    ll ans = a[r] - a[l - 1];
    return ans;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> c(n + 2, 0);
    vector<vector<ll>> p(q);
    for(ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        p[i] = {l, r};
        c[l]++;
        c[r + 1]--;
    }
    ll total = 0;
    for(ll i = 1; i <= n; i++) {
        c[i] += c[i - 1];
        total += (c[i] > 0);
    }
    // prefix of 1 and 2
    vector<ll> pre1(n + 2, 0), pre2(n + 2, 0);
    for(ll i = 1; i <= n; i++) {
        pre1[i] = pre1[i - 1] + (c[i] == 1);
    }
    for(ll i = 1; i <= n; i++) {
        pre2[i] = pre2[i - 1] + (c[i] == 2);
    }
    ll ans = 0;

    vector<ll> b[3];
    int bL;
    for(ll i = 0; i < q; i++) {
        for(ll j = i + 1; j < q; j++) {
            ll l1 = p[i][0], r1 = p[i][1];
            ll l2 = p[j][0], r2 = p[j][1];
            if(l1 > l2) {
                swap(l1, l2);
                swap(r1, r2);
            }
            if(r1 < l2) {
                // [l1 -- r1] [l2 --- r2]
                b[0] = {l1, r1, 1};
                b[1] = {l2, r2, 1};
                bL = 2;
            }
            else {
                // "intersection"
                // [l1 ----- r1]
                //       [l2 ------ r2]
                // [l1, l2 - 1]
                // [l2, min(r1, r2)]
                // [min(r1, r2) + 1, max(r1, r2)]
                b[0] = {l1, l2 - 1, 1};
                b[1] = {l2, min(r1, r2), 2};
                b[2] = {min(r1, r2) + 1, max(r1, r2), 1};
                bL = 3;
            }
            ll cur = total;
            assert(bL <= 3);
            for(ll k = 0; k < bL; k++) {
                assert(b[k].size() == 3);
                if(b[k][2] == 1) {
                    cur -= f(b[k][0], b[k][1], pre1, n);
                }
                else {
                    cur -= f(b[k][0], b[k][1], pre2, n);
                }
            }
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}