#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int getfa(int v) {
        return fa[v] == v ? v : (fa[v] = getfa(fa[v]));
    }
    bool merge(int u, int v) {
        u = getfa(u), v = getfa(v);
        if (u == v) {
            return false;
        }
        fa[u] = v;
        return true;
    }
};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    DSU dsu(n * 2);
    map<int, array<int, 2>> lst;
    int sum = 0;
    lst[0] = {0, 0};
    for (int i = 0; i < n * 2; i++) {
        sum += (s[i] == '(' ? 1 : -1);
        lst.erase(lst.upper_bound(sum), lst.end());
        if (lst.count(sum)) {
            auto x = lst[sum];
            dsu.merge(x[0], i);
            dsu.merge(x[1], i);
        } else {
            lst[sum][0] = i + 1;
        }
        lst[sum][1] = i + 1;
    }
    int ans = 0;
    for (int i = 0; i < n * 2; i++) {
        if (dsu.getfa(i) == i) {
            ++ans;
        }
    }
    printf("%d\n", ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}