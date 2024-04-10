#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr LL inf = 4E18;
struct BIT{
    int n;
    vector<LL> v;
    BIT(int n) : n(n), v(n + 1, inf) {
    }
    void set(int x, LL y) {
        for (; x <= n; x += x & -x) v[x] = min(v[x], y);
    }
    LL sum(int x) {
        LL res = inf;
        for (; x; x -= x & -x) res = min(res, v[x]);
        return res;
    }
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, q;
    cin >> n >> q;
    vector<LL> x(n + 1), w(n + 1);
    for (int i = 1; i <= n; i += 1) cin >> x[i] >> w[i];
    vector<int> l(q), r(q), L(n + 1), R(n + 1);
    vector<LL> ans(q, inf);
    vector<vector<int>> ql(n + 1), qr(n + 1), fL(n + 1), fR(n + 1);
    for (int i = 0; i < q; i += 1) {
        cin >> l[i] >> r[i];
        ql[l[i]].push_back(i);
        qr[r[i]].push_back(i);
    }
    {
        vector<int> s;
        for (int i = 1; i <= n; i += 1) {
            while (not s.empty() and w[i] < w[s.back()])
                s.pop_back();
            if (not s.empty()) {
                L[i] = s.back();
                fL[s.back()].push_back(i);
            }
            s.push_back(i);
        }
    }
    {
        vector<int> s;
        for (int i = n; i >= 1; i -= 1) {
            while (not s.empty() and w[i] <= w[s.back()])
                s.pop_back();
            if (not s.empty()) {
                R[i] = s.back();
                fR[s.back()].push_back(i);
            }
            s.push_back(i);
        }
    }
    {
        BIT bit(n);
        for (int i = n; i >= 1; i -= 1) {
            for (int j : fL[i])
                bit.set(j, (x[j] - x[i]) * (w[i] + w[j]));
            for (int j : ql[i])
                ans[j] = min(ans[j], bit.sum(r[j]));
        }
    }
    {
        BIT bit(n);
        for (int i = 1; i <= n; i += 1) {
            for (int j : fR[i])
                bit.set(n + 1 - j, (x[i] - x[j]) * (w[i] + w[j]));
            for (int j : qr[i])
                ans[j] = min(ans[j], bit.sum(n + 1 - l[j]));
        }
    }
    for (LL x : ans) cout << x << "\n";
}