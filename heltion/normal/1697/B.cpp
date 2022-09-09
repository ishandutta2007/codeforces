#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<LL> p(n);
    for (LL& pi : p) cin >> pi;
    ranges::sort(p, greater<LL>());
    partial_sum(p.begin(), p.end(), p.begin());
    for (int i = 0, x, y; i < q; i += 1) {
        cin >> x >> y;
        cout << p[x - 1] - (x == y ? 0 : p[x - y - 1]) << "\n";
    }
    return 0;
}