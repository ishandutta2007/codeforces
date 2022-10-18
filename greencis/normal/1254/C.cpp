#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll query(int tp, int i, int j, int k) {
    cout << tp << " " << i << " " << j << " " << k << endl;
    ll ans = 0;
    cin >> ans;
    return ans;
}

vector<int> solve(int a, int b, vector<pair<ll, int>> v) {
    vector<int> ans;
    ans.push_back(b);
    if (!v.empty()) {
        int support = max_element(all(v))->second;
        vector<pair<ll, int>> cw, ccw;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i].second == support) continue;
            int idx = v[i].second;
            ll sgn = query(2, a, support, idx);
            (sgn > 0 ? ccw : cw).push_back(v[i]);
        }
        sort(all(cw));
        sort(all(ccw), greater<>());
        for (auto& p : cw) ans.push_back(p.second);
        ans.push_back(support);
        for (auto& p : ccw) ans.push_back(p.second);
    }
    return ans;
}

int main() {
    int n, a = 1, b = 2;
    cin >> n;
    vector<pair<ll, int>> cw, ccw;
    for (int i = 1; i <= n; ++i) {
        if (i == a || i == b) continue;
        ll sgn = query(2, a, b, i);
        ll s = query(1, a, b, i);
        (sgn > 0 ? ccw : cw).emplace_back(s, i);
    }

    auto sol1 = solve(a, b, ccw);
    auto sol2 = solve(b, a, cw);
    for (int x : sol2) sol1.push_back(x);
    int idx = min_element(all(sol1)) - sol1.begin();
    rotate(sol1.begin(), sol1.begin() + idx, sol1.end());
    cout << 0;
    for (int x : sol1) cout << ' ' << x;
    cout << endl;
}