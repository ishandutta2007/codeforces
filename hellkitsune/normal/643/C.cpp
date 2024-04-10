#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;
typedef pair<Double, Double> PDD;

int n, k;
int a[200005];
Double d[200005], nd[200005];
LL sum[200005];
Double rsum[200005];
Double pref[200005];
deque<PDD> q;

Double getTime(const PDD &a, const PDD &b) {
    return (b.second - a.second) / (a.first - b.first);
}

void solve(int from) {
    q.clear();
    q.push_back(mp(-sum[from], d[from] - pref[from] + sum[from] * rsum[from]));
    for (int i = from + 1; i <= n; ++i) {
        while ((int)q.size() > 1 && getTime(q[1], q[0]) < rsum[i]) {
            q.pop_front();
        }
        PDD &best = q.front();
        nd[i] = best.first * rsum[i] + best.second + pref[i];
        PDD newP = mp(-sum[i], d[i] - pref[i] + sum[i] * rsum[i]);
        while ((int)q.size() > 1 && getTime(newP, q.back()) < getTime(q.back(), q.end()[-2])) {
            q.pop_back();
        }
        q.push_back(newP);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    sum[0] = pref[0] = 0;
    rsum[0] = 0;
    REP(i, n) {
        sum[i + 1] = sum[i] + a[i];
        rsum[i + 1] = rsum[i] + 1.0 / a[i];
        pref[i + 1] = pref[i] + (Double)sum[i + 1] / a[i];
    }
    REP(i, n + 1) d[i] = pref[i];
    REP(times, k - 1) {
        solve(times);
        memcpy(d, nd, sizeof d);
    }
    printf("%.14f\n", (double)d[n]);
    return 0;
}