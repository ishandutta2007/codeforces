#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

const int inf = 1e9;

struct SegTree {
    vector<int> t;
    int n;

    int get(int v, int l, int r, int L, int R) {
        if (R <= l || r <= L)
            return -inf;
        if (L <= l && r <= R)
            return t[v];
        int m = (l + r) / 2;
        return max(get(v * 2 + 1, l ,m ,L, R), get(v * 2, m, r, L, R));
    }

    void update(int v, int l, int r, int pos, int val) {
        if (r - l == 1) {
            t[v] = max(t[v], val);
            return;
        }

        int m = (l + r) / 2;
        if (pos < m)
            update(v * 2 + 1, l, m, pos, val);
        else
            update(v * 2, m, r, pos, val);
        t[v] = max(t[v * 2 + 1], t[v * 2]);
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n, pos, val);
    }

    SegTree(int _n) {
        n = _n;
        t.resize(4 * n, -inf);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    SegTree t1(pref.size()), t2(pref.size()), t3(pref.size());
    vector<long long> who = pref;
    sort(all(who));
    t1.update(lower_bound(all(who), pref[0]) - who.begin(), 1);
    t2.update(lower_bound(all(who), pref[0]) - who.begin(), 0);
    t3.update(lower_bound(all(who), pref[0]) - who.begin(), -1);
    int res;
    for (int i = 0; i < n; ++i) {
        int ind = lower_bound(all(who), pref[i + 1]) - who.begin();
        res = max({t1.get(0, ind) + i, t2.get(ind, ind + 1), t3.get(ind + 1, pref.size()) - i});
        // cout << res << ',';
        t1.update(ind, res - i);
        t2.update(ind, res);
        t3.update(ind, res + i);
    }
    cout << res << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}