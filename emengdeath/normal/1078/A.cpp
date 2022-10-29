#include <bits/stdc++.h>
#define y1 YY1
#define x1 XX1
using namespace std;
struct point{
    long double x[2];
}p[10];
int a, b, c, tot;
int x1, x2, y1, y2;
long double f[10][10], ans;
void work(point& P) {
    if (!a) {
        p[++tot].x[1] = (long double)-c / b;
        p[tot].x[0] = P.x[0];
    }
    if (!b) {
        p[++tot].x[0] = (long double)-c / a;
        p[tot].x[1] = P.x[1];
    }
    if (a && b) {
        p[++tot].x[1] = (long double)(-c - P.x[0] * a) / b;
        p[tot].x[0] = P.x[0];
        
        
        p[++tot].x[0] = (long double)(-c - P.x[1] * b) / a;
        p[tot].x[1] = P.x[1];
    }
}
long double sqr(long double x) {
    return x * x;
}
int main() {
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    p[0].x[0] = x1;
    p[0].x[1] = y1;
    p[1].x[0] = x2;
    p[1].x[1] = y2;
    ans = abs((long double)x1 - x2) + abs((long double)y1 - y2);
    tot = 1;
    work(p[0]);
    work(p[1]);    
    for (int i = 0; i <= tot; i ++) {
        for (int j = 0; j <= tot; j ++)
            if (i != j) {
                if (i > 1 && j > 1) f[i][j] = sqrt(sqr(p[i].x[0] - p[j].x[0]) + sqr(p[i].x[1] - p[j].x[1]));
                else
                    f[i][j] = abs(p[i].x[0] - p[j].x[0]) + abs(p[i].x[1] - p[j].x[1]);
            }
    }
    for (int i = 0;i <= tot; i ++)
        for (int j = 0; j <= tot; j ++)
            if (i != j)
             for (int k = 0; k <= tot; k ++)
                if (i != k && j != k)
                if (f[j][i] + f[i][k] < f[j][k])
                    f[j][k] = f[k][j] = f[j][i] + f[i][k];
    ans = min(ans, f[0][1]);
    printf("%.10Lf", ans);
    return 0;
}