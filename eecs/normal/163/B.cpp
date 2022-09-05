#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, h, v[maxn], m[maxn], id[maxn];
vector<int> ans;

int main() {
    scanf("%d %d %d", &n, &K, &h);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [&](int x, int y) {
        return make_pair(m[x], v[x]) < make_pair(m[y], v[y]);
    });
    auto chk = [&](double lim) {
        vector<int> V;
        for (int i = 1; i <= n && V.size() < K; i++) {
            if (1.0 * h * (V.size() + 1) / v[id[i]] < lim) V.push_back(id[i]);
        }
        if (V.size() == K) ans = V;
        return V.size() == K;
    };
    double l = 0, r = 2e9, st = clock();
    while ((clock() - st) / CLOCKS_PER_SEC < 0.5) {
        double mid = (l + r) / 2;
        chk(mid) ? r = mid : l = mid;
    }
    for (int x : ans) printf("%d ", x);
    return 0;
}