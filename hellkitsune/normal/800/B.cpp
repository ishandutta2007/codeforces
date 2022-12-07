#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int x[1005], y[1005];

double solve(int ind) {
    double a = y[ind + 2] - y[ind];
    double b = x[ind] - x[ind + 2];
    double c = -(a * x[ind] + b * y[ind]);
    double dist = abs(a * x[ind + 1] + b * y[ind + 1] + c) / sqrt(a * a + b * b);
    return 0.5 * dist;
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", x + i, y + i);
    forn(i, 5) {
        x[i + n] = x[i];
        y[i + n] = y[i];
    }
    double ans = 1e50;
    forn(i, n) {
        ans = min(ans, solve(i));
    }
    printf("%.15f\n", ans);
    return 0;
}