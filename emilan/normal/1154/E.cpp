#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    for (int &x : a) cin >> x, x--;

    set<pii> stud, ord;
    for (int i = 0; i < n; i++) {
        stud.emplace(i, a[i]);
        ord.emplace(a[i], i);
    }

    vt<int> ans(n);
    int turn = 0;
    while (!ord.empty()) {
        pii sel = *ord.rbegin();
        sel = {sel.se, sel.fi};

        auto it = stud.find(sel);

        if (it != stud.begin()) {
            auto it_l = it;
            it_l--;
            for (int i = 0; i < k; i++) {
                ans[it_l->fi] = turn + 1;

                if (it_l != stud.begin()) {
                    auto it_l2 = it_l;
                    it_l--;
                    ord.erase({it_l2->se, it_l2->fi});
                    stud.erase(it_l2);
                } else {
                    ord.erase({it_l->se, it_l->fi});
                    stud.erase(it_l);
                    break;
                }
            }
        }

        auto it_r = it;
        it_r++;
        for (int i = 0; i < k && it_r != stud.end(); i++) {
            ans[it_r->fi] = turn + 1;

            auto it_r2 = it_r;
            it_r++;
            ord.erase({it_r2->se, it_r2->fi});
            stud.erase(it_r2);
        }

        ans[sel.fi] = turn + 1;
        ord.erase({it->se, it->fi});
        stud.erase(it);

        turn ^= 1;
    }

    for (int x : ans) cout << x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}