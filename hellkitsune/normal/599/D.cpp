#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef unsigned long long LL;
typedef pair<int, int> PII;

LL x;
vector<pair<long long, long long> > ans;

int main() {
    scanf("%I64u", &x);
    int lo = 0, hi = 1500000, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if ((LL)mid * (mid + 1) / 2 * (2 * mid + 1) / 3 >= x) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    for (int i = lo; i > 0; --i) {
        LL lo = 0, hi = x, mid;
        LL pre = (LL)i * (i + 1) / 2;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            LL val = 3 * mid + 2 * i + 1;
            if (val > 3 * x / pre) {
                hi = mid;
            } else if (pre * val / 3 >= x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (pre * (3 * lo + 2 * i + 1) / 3 == x) {
            ans.pb(mp(i, i + lo));
            if (lo) ans.pb(mp(i + lo, i));
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (auto x : ans) printf("%I64d %I64d\n", x.first, x.second);
    return 0;
}