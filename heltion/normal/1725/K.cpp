#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<pair<int, int>> sp;
    int n;
    cin >> n;
    vector<int> a(n + 1), id(n + 1);
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
        id[i] = i;
    }
    for (int i = 1; i <= n; i += 1)
        sp.emplace(a[i], i);
    int q;
    cin >> q;
    vector<int> p(n + q + 1);
    for (int i = 1; i <= n + q; i += 1) p[i] = i;
    a.resize(n + q + 1);
    function<int(int)> fp = [&](int u) {
        return p[u] == u ? u : p[u] = fp(p[u]);
    };
    for (int i = 1, op, j = n + 1; i <= q; i += 1) {
        cin >> op;
        if (op == 1) {
            int k, w;
            cin >> k >> w;
            id[k] = j;
            sp.emplace(a[j] = w, j);
            j += 1;
        }
        else if (op == 2) {
            int k;
            cin >> k;
            cout << a[fp(id[k])] << "\n";
        }
        else {
            int l, r;
            cin >> l >> r;
            vector<int> L, R;
            for (auto it = sp.lower_bound({l, 0}); it != sp.end() and it->first <= r; it = sp.erase(it)) {
                if (it->first - l < r - it->first) L.push_back(it->second);
                else R.push_back(it->second);
            }
            if (L.size()) {
                for (int l : L) p[l] = L[0];
                sp.emplace(a[L[0]] = l - 1, L[0]);
            }
            if (R.size()) {
                for (int r : R) p[r] = R[0];
                sp.emplace(a[R[0]] = r + 1, R[0]);
            }
        }
    }
}