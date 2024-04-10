#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const double PI = acos(-1);
int n, K;
double x[maxn], y[maxn], d[maxn], ang[maxn];

int main() {
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        d[i] = sqrt(x[i] * x[i] + y[i] * y[i]);
        ang[i] = atan2(y[i], x[i]);
    }
    auto chk = [&](double r) {
        vector<pair<double, int>> event;
        int cur = 0;
        for (int i = 1; i <= n; i++) if (d[i] < 2 * r) {
            double alpha = acos(d[i] / r / 2);
            double l = ang[i] - alpha, r = ang[i] + alpha;
            if (l < 0) l += 2 * PI;
            if (r < 0) r += 2 * PI;
            event.emplace_back(l, 1);
            event.emplace_back(r, -1);
            if (l > r) cur++;
        }
        sort(event.begin(), event.end());
        for (auto &p : event) {
            if ((cur += p.second) >= K) return 1;
        }
        return 0;
    };
    double st = clock();
    double l = 0, r = 2e5;
    while ((clock() - st) / CLOCKS_PER_SEC < 4) {
        double mid = (l + r) / 2;
        chk(mid) ? r = mid : l = mid;
    }
    cout << setprecision(9) << fixed << r << endl;
    return 0;
}