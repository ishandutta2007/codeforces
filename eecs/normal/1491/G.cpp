#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, c[maxn], d[maxn], vis[maxn];
vector<vector<int>> foo;
vector<pair<int, int>> ans;

void solve(int a, int b) {
    ans.emplace_back(d[a], d[b]);
    swap(c[d[a]], c[d[b]]);
    c[d[a]] *= -1, c[d[b]] *= -1;
    swap(d[a], d[b]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]), d[c[i]] = i;
    }
    for (int i = 1; i <= n; i++) if (c[i] ^ i && !vis[i]) {
        int j = i;
        vector<int> bar;
        while (!vis[j]) {
            bar.push_back(j);
            vis[j] = 1, j = c[j];
        }
        foo.push_back(bar);
    }
    int i;
    for (i = 0; i + 1 < foo.size(); i += 2) {
        auto a = foo[i], b = foo[i + 1];
        solve(a[0], b[0]);
        for (int j = 0; j < b.size() - 2; j++) solve(b[j], b[j + 1]);
        solve(b.back(), a[1]);
        for (int j = 2; j < a.size(); j++) solve(a[j - 1], a[j]);
        solve(a[0], b.back());
        solve(b[b.size() - 2], a.back());
    }
    if (i < foo.size()) {
        auto a = foo[i];
        if (a.size() > 2) {
            solve(a[0], a.back());
            solve(a.back(), a[1]);
            for (int i = 2; i < a.size() - 1; i++) solve(a[i - 1], a[i]);
            solve(a[0], a.back());
            solve(a[a.size() - 2], a.back());
        } else {
            int baz;
            if (a[0] ^ 1 && a[1] ^ 1) baz = 1;
            if (a[0] ^ 2 && a[1] ^ 2) baz = 2;
            if (a[0] ^ 3 && a[1] ^ 3) baz = 3;
            solve(baz, a[0]);
            solve(a[0], a[1]);
            solve(baz, a[1]);
        }
    }
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}