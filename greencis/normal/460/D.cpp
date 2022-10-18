//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

ll getXor(const vector<ll>& v) {
    ll ans = 0;
    for (ll x : v)
        ans ^= x;
    return ans;
}

vector<ll> solve(ll L, ll R, int k) {
    ll bestAns = 1e18;
    vector<ll> bestVec;

    auto update = [&](const vector<ll>& v) {
        ll cur = getXor(v);
        if (cur < bestAns) {
            bestAns = cur;
            bestVec = v;
        }
    };

    for (int offset = 0; offset <= 3; ++offset) {
        for (int sz = 1; sz <= 4 && sz <= k && L + offset + sz - 1 <= R; ++sz) {
            vector<ll> v;
            for (int i = 0; i < sz; ++i)
                v.push_back(L + offset + i);
            update(v);
        }
    }

    if (bestAns == 0 || k <= 2)
        return bestVec;

    ll len = R - L + 1;
    if (len <= 6) {
        for (int mask = 1 << len; mask--; ) {
            vector<ll> v;
            for (int i = 0; i < len; ++i) {
                if (mask & (1 << i))
                    v.push_back(L + i);
            }
            if (!v.empty() && (int)v.size() <= k)
                update(v);
        }
        return bestVec;
    }

    // k == 3, len >= 7, xor <= 1
    int highest = 63 - __builtin_clzll(R);
    if (!(L & (1LL << highest))) {
        ll c = (1LL << highest) - 1;
        ll a = c / 2;
        ll b = a + 1;
        if (a >= L) {
            update({a, b, c});
        } else if (R & (1LL << (highest - 1))) {
            // L = 01..., cannot take all three 01, must take 011111, 101111, 110000
            a = c;
            c = (c + 1) * 3 / 2;
            b = a ^ c;
            update({a, b, c});
        }
    }
    return bestVec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, r, k;
    cin >> l >> r >> k;
    auto ans = solve(l, r, k);
    cout << getXor(ans) << '\n' << ans.size() << '\n';
    for (ll x : ans)
        cout << x << ' ';
    cout << '\n';
}