#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    double ans = abs(x1 - x2) + abs(y1 - y2);
    double x3, y3, x4, y4;
    auto chk = [&]() {
        ans = min(ans, abs(x1 - x3) + abs(y1 - y3) + abs(x2 - x4) + abs(y2 - y4)
            + sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4)));
    };
    vector<pair<double, double>> V1, V2;
    if (b || abs(a * x1 + c) < 1e-5) V1.emplace_back(x1, abs(b) < 1e-5 ? y1 : (c + a * x1) / -b);
    if (a || abs(b * y1 + c) < 1e-5) V1.emplace_back(abs(a) < 1e-5 ? x1 : (c + b * y1) / -a, y1);
    if (b || abs(a * x2 + c) < 1e-5) V2.emplace_back(x2, abs(b) < 1e-5 ? y2 : (c + a * x2) / -b);
    if (a || abs(b * y2 + c) < 1e-5) V2.emplace_back(abs(a) < 1e-5 ? x2 : (c + b * y2) / -a, y2);
    for (auto p1 : V1) for (auto p2 : V2) {
        x3 = p1.first, y3 = p1.second;
        x4 = p2.first, y4 = p2.second, chk();
    }
    printf("%.9f\n", ans);
    return 0;
}