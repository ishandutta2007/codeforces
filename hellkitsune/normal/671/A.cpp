#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int ax, ay, bx, by, tx, ty;
int n;
int x[100000], y[100000];
vector<int> all;

double dist(double x, double y) {
    return sqrt(x * x + y * y);
}

void solve(double xx, double yy) {
    double mx = -1e20, mx2 = -1e20;
    int ind = -1, ind2 = -1;
    REP(i, n) {
        double dif = dist(tx - x[i], ty - y[i]) - dist(xx - x[i], yy - y[i]);
        if (dif > mx) {
            mx2 = mx;
            mx = dif;
            ind2 = ind;
            ind = i;
        } else if (dif > mx2) {
            mx2 = dif;
            ind2 = i;
        }
    }
    all.pb(ind);
    if (ind2 != -1) all.pb(ind2);
}

int main() {
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", x + i, y + i);
    }
    double sum = 0;
    REP(i, n) {
        sum += 2 * dist(x[i] - tx, y[i] - ty);
    }
    solve(ax, ay);
    solve(bx, by);
    double ans = 1e30;
    for (int i : all) {
        ans = min(ans, sum - dist(tx - x[i], ty - y[i]) + dist(ax - x[i], ay - y[i]));
        ans = min(ans, sum - dist(tx - x[i], ty - y[i]) + dist(bx - x[i], by - y[i]));
    }
    for (int i : all) for (int j : all) if (i != j) {
        ans = min(ans, sum - dist(tx - x[i], ty - y[i]) + dist(ax - x[i], ay - y[i])
                           - dist(tx - x[j], ty - y[j]) + dist(bx - x[j], by - y[j]));
    }
    printf("%.12f\n", ans);
    return 0;
}