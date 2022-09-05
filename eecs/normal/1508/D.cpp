#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2010;
int n, a[maxn], x[maxn], y[maxn], fa[maxn];
vector<int> id;
vector<pair<int, int>> ans;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &n);
    int mn = INT_MAX, k = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &a[i]);
        if (i ^ a[i] && x[i] < mn) mn = x[i], k = i;
    }
    if (!k) puts("0"), exit(0);
    iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fa[find(i)] = find(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] ^ i && i ^ k) id.push_back(i);
    }
    sort(id.begin(), id.end(), [&](int i, int j) {
        return atan2(y[i] - y[k], x[i] - x[k]) < atan2(y[j] - y[k], x[j] - x[k]);
    });
    for (int i = 0; i < id.size() - 1; i++) if (find(id[i]) ^ find(id[i + 1])) {
        ans.emplace_back(id[i], id[i + 1]), swap(a[id[i]], a[id[i + 1]]);
        fa[find(id[i])] = find(id[i + 1]);
    }
    vector<int> V;
    for (int i = k; ; i = a[i]) {
        V.push_back(i);
        if (a[i] == k) break;
    }
    for (int i = 1; i < V.size(); i++) {
        ans.emplace_back(k, V[i]);
    }
    printf("%d\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}