#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int s, x1, x2, t1, t2, p, d;
    scanf("%d%d%d%d%d%d%d", &s, &x1, &x2, &t1, &t2, &p, &d);
    int answer = t2 * abs(x1 - x2);
    int first;
    if (p == x1)
        first = 0;
    else
        if (p > x1)
            if (d == -1)
                first = (p - x1) * t1;
            else {
                first = t1 * (s - p + s - x1);
                d = -1;
            }
        else
            if (d == 1)
                first = (x1 - p) * t1;
            else {
                first = t1 * (p + x1);
                d = 1;
            }
    int second;
    if (x1 > x2)
        if (d == -1)
            second = (x1 - x2) * t1;
        else
            second = t1 * (s - x1 + s - x2);
    else
        if (d == 1)
            second = (x2 - x1) * t1;
        else
            second = t1 * (x1 + x2);
    printf("%d\n", min(answer, first + second));
    return 0;
}