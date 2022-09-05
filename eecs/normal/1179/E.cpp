#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    int n;
    ll L, lim, lb, rb, val;
    cin >> n >> L;
    auto ask = [&](int i, ll x) {
        cout << "? " << i + 1 << " " << x << endl;
        return cin >> x, x;
    };
    auto get = [&](int i, ll x) {
        ll l = lb, r = rb;
        while (l <= r) {
            ll mid = (l + r) / 2, v = ask(i, mid);
            if (v == x) return mid;
            v < x ? l = mid + 1 : r = mid - 1;
        }
    };
    mt19937 rnd(time(0));
    function<vector<int>(vector<int>, int)> kth = [&](vector<int> V, int k) {
        int p = rnd() % V.size();
        ll ind = get(V[p], lim);
        vector<int> L, R, eq;
        for (int i = 0; i < V.size(); i++) {
            ll x = ask(V[i], ind);
            (x > lim ? L : x == lim ? eq : R).push_back(V[i]);
        }
        if (L.size() >= k) return kth(L, k);
        k -= L.size();
        if (eq.size() >= k) {
            val = ind;
            while (k--) L.push_back(eq.back()), eq.pop_back();
            return L;
        }
        k -= eq.size();
        copy(eq.begin(), eq.end(), back_inserter(L));
        R = kth(R, k), copy(R.begin(), R.end(), back_inserter(L));
        return L;
    };
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    vector<array<ll, 2>> ans(n);
    function<void(int, int, ll, ll)> solve = [&](int l, int r, ll ql, ll qr) {
        if (l == r) { ans[id[l]] = {ql, qr}; return; }
        int mid = (l + r) / 2;
        lim = L / n * (mid + 1), lb = ql, rb = qr;
        auto V = kth(vector<int>(id.begin() + l, id.begin() + r + 1), mid - l + 1);
        vector<int> o(id.begin() + l, id.begin() + r + 1);
        int p = mid + 1;
        for (int x : o) {
            if (!count(V.begin(), V.end(), x)) id[p++] = x;
        }
        copy(V.begin(), V.end(), id.begin() + l);
        ll tmp = val;
        solve(l, mid, ql, tmp), solve(mid + 1, r, tmp, qr);
    };
    solve(0, n - 1, 0, 1e18);
    cout << "!" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}