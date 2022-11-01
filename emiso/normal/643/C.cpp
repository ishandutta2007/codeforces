#include <bits/stdc++.h>

#define KM 51
#define MN 200020

using namespace std;

double dp[MN][KM];

int n, k, t[MN];
double acum_num[MN], acum_denom[MN], pref[MN];

// [l, r]
double C(int l, int r) {
    if(l == 0) return pref[r];
    return pref[r] - pref[l-1] - acum_num[l-1]*(acum_denom[r] - acum_denom[l-1]);
}

struct func {
    double a, b;
    int q;
    func() {}
    func(double a, double b, int q): a(a), b(b), q(q) {}
    double y(double x) { return a*x + b; }
    double intersec(func o) {
        //assert(abs(a - o.a) > EPS);
        return (o.b - b) / (a - o.a);
    }
};

struct CHT {
    deque<func> cht;

    bool bad(func a, func b, func c) {
        return a.intersec(c) <= a.intersec(b);
    }
    void add(func f) {
        while(cht.size() > 1 && bad(cht[cht.size()-2], cht.back(), f)) {
            cht.pop_back();
        }
        cht.push_back(f);
    }
    pair<double, int> query(double x) {
        while(cht.size() > 1 && cht[0].y(x) >= cht[1].y(x)) cht.pop_front();
        return {cht.front().y(x), cht.front().q};
    }
};

pair<double, int> solve(double C) {
    CHT resp;
    pair<double, int> ans;
    resp.add(func(0, C, 1));
    for(int i = 1; i <= n; i++) {
        ans = resp.query(acum_denom[i]);
        ans.first += pref[i];
        resp.add(func(-acum_num[i], ans.first - pref[i] + acum_num[i]*acum_denom[i] + C, ans.second + 1));
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &t[i]);

    for(int i = 1; i <= n; i++) {
        acum_num[i] = acum_num[i-1] + t[i];
        acum_denom[i] = acum_denom[i-1] + 1.0/t[i];
        pref[i] = pref[i-1] + acum_num[i]/t[i];
    }

    double l = 0, r = 1e16, m;
    pair<double, int> ans;

    for(int it = 70; it; it--) {
        m = (l + r)/2;
        ans = solve(m);
        if(ans.second > k) l = m;
        else {
            r = m;
            if(ans.second == k) break;
        }

    }
    ans = solve(r);

    printf("%.9f\n", ans.first - r*k);
    return 0;
}