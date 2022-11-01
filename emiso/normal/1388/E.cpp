#include <bits/stdc++.h>

#define MN 1001000
#define EPS 1e-12

using namespace std;

struct func {
    int a, b;
    func() {}
    func(int a, int b): a(a), b(b) {}
    double y(double x) { return 1.0*a*x + b; }
    double intersec(func o) {
        assert(a != o.a);
        return (o.b - b + 0.0) / (0.0 + a - o.a);
    }
};

struct CHT {
    int mini;
    CHT(int mini) : mini(mini) {};

    deque<func> cht;
    bool bad(func a, func b, func c) {
        if(mini) return a.intersec(c) <= a.intersec(b);
        return a.intersec(c) >= a.intersec(b);
    }
    // f.a dec
    void add(func f) {
        while(!cht.empty() && cht.back().a == f.a) {
            if(mini) {
                if(cht.back().b >= f.b) cht.pop_back();
                else return;
            } else {
                if(cht.back().b <= f.b) cht.pop_back();
                else return;
            }
        }
        while(cht.size() > 1 && bad(cht[cht.size()-2], cht.back(), f)) {
            cht.pop_back();
        }
        cht.push_back(f);
    }
    // x dec
    double query(double x) {
        while(cht.size() > 1 && cht[0].y(x) <= cht[1].y(x))
            cht.pop_front();
        return cht.front().y(x);
    }
};

int n, xl[MN], xr[MN], y[MN], app[2020][2020], ok, maxix = INT_MIN, minix = INT_MAX;

vector<int> rr;
bool cmp(int a, int b) {
    return y[a] > y[b];
}

int main() {
    scanf("%d", &n);

    CHT ma(0), mi(0);

    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &xl[i], &xr[i], &y[i]);
        rr.push_back(i);
        maxix = max(maxix, xr[i]);
        minix = min(minix, xl[i]);
    }
    sort(rr.begin(), rr.end(), cmp);

    for(int i = 0; i < n; i++) {
        int j = rr[i];
        ma.add(func(y[j], xr[j]));
        //mi.add(func(y[j], xl[j]));
    }
    for(int i = n-1; i >= 0; i--) {
        int j = rr[i];
        mi.add(func(-y[j], -xl[j]));
    }

    vector<pair<double, pair<int, int>>> ev;
    ev.push_back({0, {n, n}});
    ev.push_back({0, {n, n}});
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double d = xl[j] - xr[i], hd = y[j] - y[i];
            double d2 = xl[i] - xr[j], h2 = y[i] - y[j];

            if(hd != 0) {
                double p1 = - d / hd, p2 = - d2 / h2;
                if(p1 > p2) swap(p1, p2);
                ev.push_back({p1 + EPS, {i, j}});
                ev.push_back({p2 - EPS, {i, j}});
            }
        }
    }
    sort(ev.begin(), ev.end());
    reverse(ev.begin(), ev.end());

    double ans = DBL_MAX;
    if(n == 1) ans = maxix - minix;

    for(auto ee : ev) {
        int i = ee.second.first, j = ee.second.second;
        if(app[i][j] == 1) {
            app[i][j]++;
            ok--;
        }
        if(ok == 0) {
            ans = min(ans, ma.query(ee.first) + mi.query(ee.first));
        }
        if(app[i][j] == 0) {
            app[i][j]++;
            ok++;
        }
    }


    printf("%.9f\n", ans);
    return 0;
}