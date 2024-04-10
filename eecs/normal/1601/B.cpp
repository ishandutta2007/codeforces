#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, a[maxn], b[maxn], f[maxn];
pair<int, int> pre[maxn];
queue<int> Q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    set<int> cand;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]), b[i] += i;
        cand.insert(i);
    }
    memset(f, -1, sizeof(f));
    Q.push(n), f[n] = 0;
    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        if (i == a[i] && !~f[0]) {
            f[0] = f[i] + 1, pre[0] = {i, 0};
        }
        while (1) {
            auto it = cand.lower_bound(i - a[i]);
            if (it == cand.end() || *it > i) break;
            int _i = b[*it];
            if (!~f[_i]) Q.push(_i), f[_i] = f[i] + 1, pre[_i] = {i, *it};
            cand.erase(it);
        }
    }
    if (!~f[0]) puts("-1"), exit(0);
    printf("%d\n", f[0]);
    vector<int> ans;
    for (int i = 0; i != n; i = pre[i].first) {
        ans.push_back(pre[i].second);
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x);
    return 0;
}