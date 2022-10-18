#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MOD = 1'000'000'007;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= MOD)
        z -= MOD;
    return z;
}
inline int mul(int x, int y) {
    return int(x * (ll)y % MOD);
}
inline int binpow(int x, int deg) {
    int ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans = mul(ans, x);
        deg >>= 1;
        x = mul(x, x);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int q;
    cin >> s >> q;
    vector<string> queries(q);
    for (int i = 0; i < q; ++i) cin >> queries[i];

    vector<pii> rules(10, {10, 0}); /// mult/addon
    for (int i = 0; i <= 9; ++i)
        rules[i].second = i;
    auto apply = [&](pii x, char c) {
        int d = c - '0';
        x.first = mul(x.first, rules[d].first);
        x.second = add(mul(x.second, rules[d].first), rules[d].second);
        return x;
    };
    auto calc = [&](const string& tmp) {
        pii cur{1, 0};
        for (char c : tmp)
            cur = apply(cur, c);
        return cur;
    };

    reverse(all(queries));
    for (auto t : queries) {
        int d = t[0] - '0';
        t = t.substr(3, t.size() - 3);
        pii cur = calc(t);
        rules[d] = cur;
    }

    int ans = calc(s).second;
    cout << ans << '\n';
}