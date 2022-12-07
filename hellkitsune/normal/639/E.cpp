#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int p[150000], t[150000], ord[150000], tmp[150000], from[150000], to[150000];
LL T = 0;
LL sum[150001];

inline bool cmp(const int &lhs, const int &rhs) {
    if ((LL)p[lhs] * t[rhs] != (LL)p[rhs] * t[lhs]) {
        return (LL)p[lhs] * t[rhs] > (LL)p[rhs] * t[lhs];
    }
    return p[lhs] < p[rhs];
}

inline bool cmp2(const int &lhs, const int &rhs) {
    return p[lhs] < p[rhs];
}

void reord(int *a) {
    REP(i, n) tmp[i] = a[ord[i]];
    REP(i, n) a[i] = tmp[i];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d", p + i);
    REP(i, n) scanf("%d", t + i), T += t[i];
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    reord(p);
    reord(t);
    double lo = 0, hi = 1;
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp2);
    REP(i, n) from[i] = to[i] = i;
    for (int i = 1; i < n; ++i) if ((LL)p[i] * t[i - 1] == (LL)p[i - 1] * t[i]) {
        from[i] = from[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) if ((LL)p[i] * t[i + 1] == (LL)p[i + 1] * t[i]) {
        to[i] = to[i + 1];
    }
    sum[0] = 0;
    REP(i, n) sum[i + 1] = sum[i] + t[i];
    REP(times, 70) {
        double c = 0.5 * (lo + hi);
        double best = -1;
        bool bad = false;
        for (int beg = 0; beg < n; ) {
            int end = beg + 1;
            while (end < n && p[ord[beg]] == p[ord[end]]) ++end;
            double newBest = -1;
            for (int ii = beg; ii < end; ++ii) {
                int i = ord[ii];
                if ((double)p[i] * (1 - c * sum[to[i] + 1] / T) < best) {
                    bad = true;
                    break;
                }
                newBest = max(newBest, (double)p[i] * (1 - c * (sum[from[i]] + t[i]) / T));
            }
            if (bad) break;
            best = max(best, newBest);
            beg = end;
        }
        if (bad) hi = c;
        else lo = c;
    }
    printf("%.12f\n", lo);
    return 0;
}