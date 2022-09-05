#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll ax, ay, bx, by, tx, ty;

int main() {
    scanf("%lld %lld %lld %lld %lld %lld", &ax, &ay, &bx, &by, &tx, &ty);
    scanf("%d", &n);
    double all = 0, mn1 = 1e18, mn2 = 1e18;
    double sec1 = 1e18, sec2 = 1e18;
    int pos1, pos2;
    while (n--) {
        ll x, y; scanf("%lld %lld", &x, &y);
        double a = sqrt((x - ax) * (x - ax) + (y - ay) * (y - ay));
        double b = sqrt((x - bx) * (x - bx) + (y - by) * (y - by));
        double c = sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));
        if (a - c < mn1) sec1 = mn1, mn1 = a - c, pos1 = n;
        else sec1 = min(sec1, a - c);
        if (b - c < mn2) sec2 = mn2, mn2 = b - c, pos2 = n;
        else sec2 = min(sec2, b - c);
        all += c + c;
    }
    double inc = 1e18;
    double x = mn1, y = pos1 == pos2 ? sec2 : mn2;
    if (x > 0 && y > 0) inc = min(x, y);
    else inc = min(0.0, x) + min(0.0, y);
    x = mn2, y = pos1 == pos2 ? sec1 : mn1;
    if (x > 0 && y > 0) inc = min(inc, min(x, y));
    else inc = min(inc, min(0.0, x) + min(0.0, y));
    printf("%.9f\n", all + inc);
    return 0;
}