#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        vi a(n);
        for (int& i : a) cin >> i;
        int m;
        cin >> m;
        map<int, int> h;
        rep(i, m) {
            int p, e;
            cin >> p >> e;
            auto it = h.lower_bound(p);
            if (it != h.end() && it->se >= e) continue;

            while (it != h.begin()) {
                it--;
                if (it->se <= e) {
                    auto it2 = it;
                    it++;
                    h.erase(it2);
                } else break;
            }

            h[p] = e;
        }

        if (h.rbegin()->fi < *max_element(all(a))) {
            cout << "-1\n";
            continue;
        }

        int d = 1, cnt = 0, po = 1 << 30;
        rep(i, n) {
            int cur = h.lower_bound(a[i])->se;
            cnt++;
            po = min(po, cur);
            if (cnt > po) cnt = 1, d++, po = cur;
        }
        
        cout << d << '\n';
    }
}