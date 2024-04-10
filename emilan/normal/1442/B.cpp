#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n + 1), b(k);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            p[x] = i;
        }
        for (int &x : b) {
            cin >> x;
            x = p[x];
        }

        set<int> s; {
            vector<int> a(n);
            iota(a.begin(), a.end(), 1);
            s = set<int>(a.begin(), a.end());
        }

        set<int> need;
        for (int i : b) need.insert(i);

        int ans = 1;
        for (int i : b) {
            auto it = s.lower_bound(i);

            int cho = 0;
            if (it != s.begin() && !need.count(*prev(it))) {
                if (!cho) s.erase(prev(it));
                cho++;
            }
            if (it != --s.end() && !need.count(*next(it))) {
                if (!cho) s.erase(next(it));
                cho++;
            }

            need.erase(i);

            ans *= cho;
            if (ans >= mod) ans -= mod;
            if (cho == 0) break;
        }

        cout << ans << '\n';
    }
}