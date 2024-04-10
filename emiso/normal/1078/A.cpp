#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

double a, b, c, ax, ay, bx, by;
double ans;

int main() {
    scanf("%lf %lf %lf", &a, &b, &c);
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);

    ans = abs(ax - bx) + abs(ay - by);

    if(a) {
        double ax_ = -(b * ay + c) / a;
        double bx_ = -(b * by + c) / a;

        ans = min(ans, abs(ax_ - ax) + abs(bx_ - bx) + hypot(ax_ - bx_, ay - by));
    }
    if(a && b) {
        double ax_ = -(b * ay + c) / a;
        double by_ = -(a * bx + c) / b;

        ans = min(ans, abs(ax_ - ax) + abs(by_ - by) + hypot(ax_ - bx, ay - by_));
    }
    if(b && a) {
        double ay_ = -(a * ax + c) / b;
        double bx_ = -(b * by + c) / a;

        ans = min(ans, abs(ay_ - ay) + abs(bx_ - bx) + hypot(ax - bx_, ay_ - by));
    }
    if(b) {
        double ay_ = -(a * ax + c) / b;
        double by_ = -(a * bx + c) / b;

        ans = min(ans, abs(ay_ - ay) + abs(by_ - by) + hypot(ax - bx, ay_ - by_));
    }

    printf("%.9f\n", ans);
    return 0;
}