#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 998244353;
using T = tuple<LL, LL, LL>;
struct R{
    LL mx, sum, mxL, mxR;
    R operator + (const R& r) const {
        return {max({mx, r.mx, mxR + r.mxL}), sum + r.sum, max(mxL, sum + r.mxL), max(r.mxR, r.sum + mxR)};
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(1 << n);
    for (int& ai : a) {
        cin >> ai;
    }
    vector mp(n + 1, vector(1 << n, vector<R>()));
    function<R(int, int, int)> dfs = [&](int m, int L, int x) -> R {
        if (x >= mp[m][L].size()) mp[m][L].resize(x + 1, (R){-1, 0, 0, 0});
        if (mp[m][L][x].mx != -1) return mp[m][L][x];
        R& res = mp[m][L][x];
        if (m == 0) return res = {max(a[L], 0), a[L], max(a[L], 0), max(a[L], 0)};
        LL y = x & ((1 << (m - 1)) - 1);
        auto tL = dfs(m - 1, L, y);
        auto tR = dfs(m - 1, L + (1 << (m - 1)), y);
        if (x != y) swap(tL, tR);
        res = tL + tR;
        return res;
    };
    int q, x = 0;
    cin >> q;
    for (; q; q -= 1) {
        int k;
        cin >> k;
        x ^= 1 << k;
        cout << dfs(n, 0, x).mx << "\n";
    }
    return 0;
}