#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        bool zero = false;
        vector<int> pos, neg;
        while (n--) {
            int x;
            cin >> x;
            if (!x) zero = true;
            else if (x > 0) pos.push_back(x);
            else neg.push_back(-x);
        }
        sort(all(pos));
        sort(all(neg));
        ll ans = zero ? 0 : -1e18;
        int p = pos.size();
        n = neg.size();
        if (p >= 5)
            ans = max(ans, pos[p - 5] * (ll)pos[p - 4] * pos[p - 3] * pos[p - 2] * pos[p - 1]);
        if (p >= 3 && n >= 2)
            ans = max(ans, neg[n - 2] * (ll)neg[n - 1] * pos[p - 3] * pos[p - 2] * pos[p - 1]);
        if (p >= 1 && n >= 4)
            ans = max(ans, neg[n - 4] * (ll)neg[n - 3] * neg[n - 2] * neg[n - 1] * pos[p - 1]);

        if (n >= 1 && p >= 4)
            ans = max(ans, -neg[0] * (ll)pos[0] * pos[1] * pos[2] * pos[3]);
        if (n >= 3 && p >= 2)
            ans = max(ans, -neg[0] * (ll)neg[1] * neg[2] * pos[0] * pos[1]);
        if (n >= 5)
            ans = max(ans, -neg[0] * (ll)neg[1] * neg[2] * neg[3] * neg[4]);

        cout << ans << '\n';
    }
}