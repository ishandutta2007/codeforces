#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, l, v1, v2, k;

int main() {
    cin >> n >> l >> v1 >> v2 >> k;
    double lo = 0, hi = l, mid;
    int tot = (n + k - 1) / k;
    REP(times, 200) {
        mid = 0.5 * (lo + hi);
        double delta = mid / v2 * v1;
        delta += (mid - delta) / (v1 + v2) * v1;
        double dist = delta * (tot - 1) + mid;
        if (dist > l) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%.12f\n", lo / v2 + (l - lo) / v1);
    return 0;
}