#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, q;
ll x, b[100105];
set<ll> s;

ll solve(ll cur) {
    ll ans = 9e18;
    auto it = s.lower_bound(cur);
    if (it != s.end())
        ans = min(ans, *it - cur);
    if (it != s.begin()) {
        --it;
        ans = min(ans, cur - *it);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> q;
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cur += (i % 2 == 0 ? 1 : -1) * x;
    }
    ll cur2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        cur2 += (i % 2 == 0 ? -1 : 1) * b[i];
    }
    s.insert(cur + cur2);
    for (int i = 0; i < m - n; ++i) {
        cin >> b[i + n];
        cur2 = -(cur2 + b[i]);
        cur2 += (n % 2 == 0 ? 1 : -1) * b[i + n];
        s.insert(cur + cur2);
    }
    cur = 0;
    cout << solve(cur) << "\n";
    while (q--) {
        int l, r;
        cin >> l >> r >> x;
        --l; --r;
        if ((r - l + 1) % 2) {
            if (l % 2)
                cur -= x;
            else
                cur += x;
        }
        cout << solve(-cur) << "\n";
    }

    return 0;
}