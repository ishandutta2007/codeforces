#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int v[100005], t[100005];
LL sum[100005];
LL ans[100005], ans2[100005];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", v + i);
    forn(i, n) scanf("%d", t + i);
    sum[0] = 0;
    forn(i, n) sum[i + 1] = sum[i] + t[i];
    forn(i, n) {
        int lo = i, hi = n, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (sum[mid + 1] - sum[i] > v[i]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        ++ans[i];
        --ans[lo];
        ans2[lo] += v[i] - (sum[lo] - sum[i]);
    }
    forn(i, n) ans[i + 1] += ans[i];
    forn(i, n) ans[i] = t[i] * ans[i] + ans2[i];
    forn(i, n) printf("%I64d ", ans[i]);
    puts("");
    return 0;
}