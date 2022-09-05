#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const double PI = acos(-1);
int n, m;
pair<int, int> a[maxn], b[maxn];
double ans, ang1[maxn], ang2[maxn];
vector<pair<double, int>> V1, V2;
mt19937 rnd(time(0));

double calc(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
        (p1.second - p2.second) * (p1.second - p2.second));
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &b[i].first, &b[i].second);
    }
    shuffle(a + 1, a + n + 1, rnd);
    shuffle(b + 1, b + m + 1, rnd);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ang1[j] = atan2(b[j].second - a[i].second, b[j].first - a[i].first);
        }
        for (int j = 1; j <= n; j++) {
            ang2[j] = atan2(a[j].second - a[i].second, a[j].first - a[i].first);
        }
        auto chk = [&](double r) {
            V1.clear();
            V1.emplace_back(0, 0), V1.emplace_back(2 * PI, 0);
            int cur = 0, cur2 = 0;
            for (int j = 1; j <= m; j++){
                double d = calc(a[i], b[j]);
                if (d > 2 * r) continue;
                double ang = ang1[j];
                double alpha = acos(d / r / 2);
                double l = ang - alpha, r = ang + alpha;
                if (l < 0) l += 2 * PI;
                if (r < 0) r += 2 * PI;
                V1.emplace_back(l, 1), V1.emplace_back(r, -1);
                if (l > r) cur++;
            }
            sort(V1.begin(), V1.end());
            for (auto &p : V1) {
                cur += p.second;
                if (!cur) return 1;
            }
            return 0;
        };
        if (!chk(ans + 1e-5)) continue;
        double l = ans, r = 1.5e8;
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;
            chk(mid) ? l = mid : r = mid;
        }
        ans = l;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            ang1[j] = atan2(b[j].second - b[i].second, b[j].first - b[i].first);
        }
        for (int j = 1; j <= n; j++) {
            ang2[j] = atan2(a[j].second - b[i].second, a[j].first - b[i].first);
        }
        auto chk = [&](double r) {
            V1.clear(), V2.clear();
            V2.emplace_back(0, 0);
            V2.emplace_back(2 * PI, 0);
            int cur = 0, cur2 = 0;
            for (int j = 1; j <= m; j++) if (i ^ j) {
                double d = calc(b[i], b[j]);
                if (d > 2 * r) continue;
                double ang = ang1[j];
                double alpha = acos(d / r / 2);
                double l = ang - alpha, r = ang + alpha;
                if (l < 0) l += 2 * PI;
                if (r < 0) r += 2 * PI;
                V1.emplace_back(l, 1);
                V1.emplace_back(r, -1);
                if (l > r) cur++;
            }
            for (int j = 1; j <= n; j++) {
                double d = calc(b[i], a[j]);
                if (d > 2 * r) continue;
                double ang = ang2[j];
                double alpha = acos(d / r / 2);
                double l = ang - alpha, r = ang + alpha;
                if (l < 0) l += 2 * PI;
                if (r < 0) r += 2 * PI;
                V2.emplace_back(l, 1), V2.emplace_back(r, -1);
                if (l > r) cur2++;
            }
            sort(V1.begin(), V1.end()), sort(V2.begin(), V2.end());
            int m = V1.size();
            for (auto &p : V2) V1.emplace_back(p.first, 0);
            inplace_merge(V1.begin(), V1.begin() + m, V1.end());
            int pos = 0;
            for (auto &p : V1) {
                cur += p.second;
                if (cur) continue;
                while (pos < V2.size() && V2[pos].first < p.first) cur2 += V2[pos++].second;
                if (V2.empty() || cur2) return 1;
            }
            return 0;
        };
        if (!chk(ans + 1e-5)) continue;
        double l = ans, r = 1.5e8;
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;
            chk(mid) ? l = mid : r = mid;
        }
        ans = l;
    }
    if (ans > 1.45e8) puts("-1");
    else printf("%.9f\n", ans);
    return 0;
}