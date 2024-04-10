#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int l, r;
        cin >> l >> r;
        vector<int> a(r - l + 1);
        for (int& ai : a) cin >> ai;
        auto check = [&](const vector<int>& a, int l, int r, int x) {
            for (int i = l; i <= r; i += 1) {
                int y = x ^ i;
                auto it = ranges::lower_bound(a, y);
                if (it == a.end() or *it != y) return 0;
            }
            return 1;
        };
        function<int(vector<int> a, int l, int r)> DFS = [&](vector<int> a, int l, int r) {
            if (l == r) return a[0] ^ l;
            if (l % 2 == 0 and r % 2) {
                vector<int> b;
                for (int ai : a) if (ai % 2 == 0) b.push_back(ai / 2);
                return DFS(b, l / 2, r / 2) * 2;
            }
            vector<int> x, y;
            ranges::sort(a);
            for (int i = 0; i < a.size(); i += 1) {
                if (a[i] % 2 and (i == 0 or a[i - 1] + 1 != a[i])) x.push_back(a[i]);
                if (a[i] % 2 == 0 and (i + 1 == a.size() or a[i] + 1 != a[i + 1])) x.push_back(a[i]);
            }
            if (l & 1) y.push_back(l);
            if (r % 2 == 0) y.push_back(r);
            for (int xi : x) for (int yi : y)
                if (check(a, l, r, xi ^ yi)) return xi ^ yi;
            assert(0);
            return 0;
        };
        cout << DFS(a, l, r) << "\n";
    }
    return 0;
}