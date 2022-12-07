#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

//24:00
int n, k;
int t[200005];
double sum[200005], dsum[200005];
double invsum[200005];

//sum(l, r) sum[i + 1] / t[i] - sum[l] / t[i]

double getSeg(int l, int r) {
    return dsum[r] - dsum[l] - sum[l] * (invsum[r] - invsum[l]);
}

typedef pair<int, pair<double, double> > P;

P q[200005];
int qh, qt;
double d[200005];
int cnt[200005];

double getTime(pair<double, double> le, pair<double, double> ri) {
    return (ri.second - le.second) / (le.first - ri.first);
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", t + i);
    sum[0] = invsum[0] = dsum[0] = 0;
    forn(i, n) {
        sum[i + 1] = sum[i] + t[i];
        dsum[i + 1] = dsum[i] + sum[i + 1] / t[i];
        invsum[i + 1] = invsum[i] + 1.0 / t[i];
    }
    double lo = 0, hi = 1e18;
    int iter = 0;
    double ans = 0;
    while (iter++ < 120 && (double)clock() / CLOCKS_PER_SEC < 2.5) {
        //f(i) = -sum[i] * invsum[j] + sum[i] * invsum[i] + d[i] - dsum[i]
        //f(i) = a * invsum[j] + b
        //a = -sum[i]
        //b = sum[i] * invsum[i] + d[i] - dsum[i]
        double mid = 0.5 * (lo + hi);
        qh = 0;
        qt = 1;
        q[0] = mp(0, mp(0, 0));
        d[0] = 0;
        cnt[0] = 0;
        for (int j = 1; j <= n; ++j) {
            while (qh + 1 < qt && q[qh].second.first * invsum[j] + q[qh].second.second >
                   q[qh + 1].second.first * invsum[j] + q[qh + 1].second.second) {
                ++qh;
            }
            int i = q[qh].first;
            d[j] = d[i] + getSeg(i, j) + mid;
            cnt[j] = cnt[i] + 1;
            P nval = mp(j, mp(-sum[j], sum[j] * invsum[j] + d[j] - dsum[j]));
            while (qh + 1 < qt && getTime(q[qt - 2].second, q[qt - 1].second) > getTime(q[qt - 1].second, nval.second)) {
                --qt;
            }
            q[qt++] = nval;
        }
        if (cnt[n] > k) {
            lo = mid;
        } else {
            hi = mid;
        }
        ans = d[n] - mid * k;
    }
    printf("%.15f\n", ans);
    return 0;
}