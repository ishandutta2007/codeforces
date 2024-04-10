#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int T, p[4];
pair<int, int> a[4];

int main() {
    scanf("%d", &T);
    auto calc = [&](vector<int> V) {
        sort(V.begin(), V.end());
        return 1LL * abs(V[0] - V[1]) + abs(V[1] - V[2]) + abs(V[1] - V[3]);
    };
    while (T--) {
        iota(p, p + 4, 0);
        for (int i = 0; i < 4; i++) {
            scanf("%d %d", &a[i].x, &a[i].y);
        }
        vector<int> cand;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                cand.push_back(abs(a[i].x - a[j].x));
                cand.push_back(abs(a[i].y - a[j].y));
            }
        }
        long long ans = LLONG_MAX;
        do {
            auto solve = [&](int d) {
                int x0 = a[p[0]].x, x1 = a[p[1]].x;
                int x2 = a[p[2]].x - d, x3 = a[p[3]].x - d;
                int y0 = a[p[0]].y, y1 = a[p[1]].y - d;
                int y2 = a[p[2]].y, y3 = a[p[3]].y - d;
                return calc({x0, x1, x2, x3}) + calc({y0, y1, y2, y3});
            };
            for (int d : cand) ans = min(ans, solve(d));
        } while (next_permutation(p, p + 4));
        printf("%lld\n", ans);
    }
    return 0;
}