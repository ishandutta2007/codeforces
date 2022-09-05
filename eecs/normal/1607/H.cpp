#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], b[maxn], m[maxn], ans[maxn], from[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector<pair<int, int>> id;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &a[i], &b[i], &m[i]);
            id.emplace_back(a[i] + b[i] - m[i], i);
            ans[i] = a[i], from[i] = 0;
        }
        sort(id.begin(), id.end());
        int cnt = 0;
        for (int i = 0, j; i < id.size(); i = j) {
            for (j = i; j < id.size() && id[i].first == id[j].first; j++);
            vector<array<int, 3>> V, _V;
            for (int k = i; k < j; k++) {
                int p = id[k].second;
                V.push_back({max(0, a[p] - m[p]), a[p], p});
            }
            sort(V.begin(), V.end(), [&](array<int, 3> x, array<int, 3> y) {
                return x[1] ^ y[1] ? x[1] < y[1] : x[0] > y[0];
            });
            int mx = -1, foo;
            for (auto &p : V) {
                if (mx >= p[0]) from[p[2]] = foo;
                else mx = p[0], foo = p[2], _V.push_back(p);
            }
            for (int j = 0, k; j < _V.size(); j = k) {
                for (k = j; k < _V.size() && _V[j][1] >= _V[k][0]; k++);
                cnt++;
                for (int p = j; p < k; p++) ans[_V[p][2]] = _V[k - 1][0];
            }
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= n; i++) {
            if (from[i]) ans[i] = ans[from[i]];
            printf("%d %d\n", a[i] - ans[i], m[i] - (a[i] - ans[i]));
        }
    }
    return 0;
}