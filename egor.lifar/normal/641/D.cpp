#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>


using namespace std;

const int MAXN = 100100;
int n;
double aa[MAXN], bb[MAXN];
double ans[2][MAXN];


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &aa[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &bb[i]);
    }
    double a = 0, b = 1;
    for (int i = 0; i < n - 1; i++) {
        a += aa[i];
        b -= bb[i];
        double d = (b - a - 1.0) * (b - a - 1.0) - 4.0 * a;
        if (d < 0) {
            d = 0;
        }
        d = sqrt(d);
        double c = 1 + a - b;
        ans[0][i] = (c - d) / 2.0;
        ans[1][i] = (c + d) / 2.0;
    }
    ans[0][n - 1] = 1;
    ans[1][n - 1] = 1;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            printf("%.10lf ", ans[k][i] - (i == 0 ? 0.0: ans[k][i - 1]));
        }
        printf("\n");
    }
    return 0;
}