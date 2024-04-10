// Codeforces Beta Round #9
// Problem B -- Running Student
#include <cstdio>
#include <cmath>

#define maxN 100
#define EPS 1e-8

#define sqr(x) ((x) * (x))

using namespace std;

int n;
double v_b, v_s, x[maxN], x_u, y_u;

int main()
{
    scanf("%d%lf%lf", &n, &v_b, &v_s);
    for(int i = 0; i != n; ++ i)
        scanf("%lf", x + i);
    scanf("%lf%lf", &x_u, &y_u);
    int b = 1;
    for(int i = 2; i != n; ++ i)
        if(x[i] / v_b + sqrt(sqr(x_u - x[i]) + sqr(y_u)) / v_s + EPS <= x[b] / v_b + sqrt(sqr(x_u - x[b]) + sqr(y_u)) / v_s)
            b = i;
        else
        if(fabs(x[i] / v_b + sqrt(sqr(x_u - x[i]) + sqr(y_u)) / v_s - x[b] / v_b - sqrt(sqr(x_u - x[b]) + sqr(y_u)) / v_s) <= EPS)
        {
            if(sqrt(sqr(x_u - x[i]) + sqr(y_u)) + EPS <= sqrt(sqr(x_u - x[b]) + sqr(y_u)))
                b = i;
        }
    printf("%d\n", b + 1);
    return 0;
}