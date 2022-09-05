#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, l, v1, v2;
double ans[maxn];
vector<pair<double, int>> ev;

int main() {
    scanf("%d %d %d %d", &n, &l, &v1, &v2);
    ev = {{0, 0}, {2 * l, 0}};
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        double p = x - 1.0 * l * v2 / (v1 + v2);
        if (p < 0) {
            ev.emplace_back(0, 1);
            ev.emplace_back(x, -1);
            ev.emplace_back(p + 2 * l, 1);
            ev.emplace_back(2 * l, -1);
        } else {
            ev.emplace_back(p, 1);
            ev.emplace_back(x, -1);
        }
    }
    sort(ev.begin(), ev.end());
    double lst = 0;
    int cur = 0;
    for (auto &p : ev) {
        ans[cur] += p.first - lst;
        lst = p.first, cur += p.second;
    }
    for (int i = 0; i <= n; i++) {
        printf("%.9f\n", ans[i] / l / 2);
    }
    return 0;
}