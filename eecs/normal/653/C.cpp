#include <bits/stdc++.h>
using namespace std;

const int maxn = 150010;
int n, tim, cnt, ans, mark[maxn], a[maxn];
set<pair<int, int>> S;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> V;
    for (int i = 1; i < n; i++) {
        if (i % 2 && a[i] >= a[i + 1]) V.push_back(i), V.push_back(i + 1), cnt++;
        if (!(i % 2) && a[i] <= a[i + 1]) V.push_back(i), V.push_back(i + 1), cnt++;
    }
    auto chk = [&](int x, int y) {
        if (x > y) swap(x, y);
        if (S.count({x, y})) return;
        S.emplace(x, y);
        int o = cnt;
        auto calc = [&](int p, int coef) {
            if (p < 1 || p == n) return;
            if (mark[p] == tim) return;
            mark[p] = tim;
            if (p % 2 && a[p] >= a[p + 1]) cnt += coef;
            if (!(p % 2) && a[p] <= a[p + 1]) cnt += coef;
        };
        tim++, calc(x - 1, -1), calc(x, -1), calc(y - 1, -1), calc(y, -1);
        swap(a[x], a[y]);
        tim++, calc(x - 1, 1), calc(x, 1), calc(y - 1, 1), calc(y, 1);
        if (!cnt) ans++;
        cnt = o, swap(a[x], a[y]);
    };
    if (V.size() > 8) puts("0"), exit(0);
    for (int x : V) {
        for (int i = 1; i <= n; i++) chk(x, i);
    }
    printf("%d\n", ans);
    return 0;
}