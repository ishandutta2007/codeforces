#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1e5;
const double eps = 1e-10;
vector<pair<double, pair<int, int> > >d;
int n;
int xl[N], xr[N], y[N];
vector<int> L, R;
int cntL[N], cntR[N];
double cal(int a, int b, int x) {
    return  (double)(b - a) / x;
}
bool the_same(double x, double y) {
    return fabs(x - y) < eps;
}
double get(int a, int b, double v) {
    return (xr[b] + y[b] * v) - (xl[a] + y[a] * v);
}

#include <assert.h>
int main() {
    scanf("%d", &n);
    int l = 1e8, r = -1e8;
    for (int i = 1; i <= n;i ++) {
        scanf("%d %d %d", &xl[i], &xr[i], &y[i]);
        L.push_back(i);
        R.push_back(i);
        l = min(l, xl[i]);
        r = max(r, xr[i]);
    }
    bool sig = 0;
    for (int i = 1; i <= n;i ++) {
        for (int j = 1; j <= n; j++)
            if (y[i] > y[j]) {
                d.push_back({cal(xl[i], xr[j], y[i] - y[j]), {1, 0}});
                d.push_back({cal(xr[i], xl[j], y[i] - y[j]), {-1, 0}});
                d.push_back({cal(xl[i], xl[j], y[i] - y[j]), {i + 1, -1}});
                d.push_back({cal(xl[i], xl[j], y[i] - y[j]), {j + 1, 1}});
                d.push_back({-1e18, {j + 1, -1}});
                sig = 1;
                d.push_back({cal(xr[i], xr[j], y[i] - y[j]), {i + 1, 2}});
                d.push_back({cal(xr[i], xr[j], y[i] - y[j]), {j + 1, -2}});
                d.push_back({-1e18, {i+ 1, -2}});
            } else
            if (i!=j&&y[i] == y[j]) {
                if (xl[i] < xl[j]) {
                    d.push_back({-1e18, {i + 1, -2}});
                } else
                    d.push_back({-1e18, {i + 1, -1}});
            }
    }
    sort(d.begin(), d.end(), [](pair<double, pair<int, int> > a, pair<double, pair<int,int> >b ) {
        if (the_same(a.first, b.first)) return a.second > b.second;
        return a.first < b.first;
    });
    int cnt = 0;
    double ans = 1e18;
    if (!sig) ans = r - l;
    for (auto u:d)
    {
        if (u.second.second) {
            switch(u.second.second) {
                case 1:
                    cntL[u.second.first - 1] ++;
                    if (!cntL[u.second.first - 1]) L.push_back(u.second.first - 1);
                    break;
                case 2:
                    cntR[u.second.first - 1] ++;
                    if (!cntR[u.second.first - 1]) R.push_back(u.second.first - 1);
                    break;
                case -1:
                    cntL[u.second.first - 1] --;
                    break;
                case -2:
                    cntR[u.second.first - 1] --;
                    break;
            }
        }else {
            if (u.second.first == 1) {
                cnt ++;
                if (cnt >= 0)
                {
                    while (L.size() && cntL[L[L.size() - 1]] < 0) L.pop_back();
                    while (R.size() && cntR[R[R.size() - 1]] < 0) R.pop_back();
                    assert(L.size() > 0);
                    assert(R.size() > 0);
                    ans = min(get(L[L.size() - 1], R[R.size() - 1], u.first), ans);
                }
            } else {
                if (cnt >= 0) {
                    while (L.size() && cntL[L[L.size() - 1]] < 0) L.pop_back();
                    while (R.size() && cntR[R[R.size() - 1]] < 0) R.pop_back();
                    assert(L.size() > 0);
                    assert(R.size() > 0);
                    ans = min(get(L[L.size() - 1], R[R.size() - 1], u.first), ans);
                }
                cnt --;
            }
        }
    }
    printf("%.10f\n", ans);
    return 0;
}