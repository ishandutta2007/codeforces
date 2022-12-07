#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200001];
LL sum[200001] = {};
LL num = -1, denom = 1;
int bestMid, bestCnt;
bool doubleMid;
vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    sum[0] = 0;
    REP(i, n) sum[i + 1] = sum[i] + a[i];
    REP(i, n) {
        int lo = 0, hi = min(i, n - 1 - i), mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (2ll * (sum[i + 1] - sum[i - mid + 1] + sum[n] - sum[n - mid + 1]) < (LL)(2 * mid - 1) * (a[i - mid] + a[n - mid])) lo = mid;
            else hi = mid - 1;
        }
        if ((sum[i + 1] - sum[i - lo] + sum[n] - sum[n - lo] - (LL)(2 * lo + 1) * a[i]) * denom > num * (2 * lo + 1)) {
            num = sum[i + 1] - sum[i - lo] + sum[n] - sum[n - lo] - (LL)(2 * lo + 1) * a[i];
            denom = 2 * lo + 1;
            bestMid = i;
            bestCnt = lo;
            doubleMid = false;
        }
    }
    REP(i, n - 1) {
        int lo = 0, hi = min(i, n - 2 - i), mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (2ll * (sum[i + 2] - sum[i - mid + 1] + sum[n] - sum[n - mid + 1]) < (LL)(2 * mid) * (a[i - mid] + a[n - mid])) lo = mid;
            else hi = mid - 1;
        }
        if ((sum[i + 2] - sum[i - lo] + sum[n] - sum[n - lo] - (LL)(lo + 1) * (a[i] + a[i + 1])) * denom > num * (2 * lo + 2)) {
            num = sum[i + 2] - sum[i - lo] + sum[n] - sum[n - lo] - (LL)(lo + 1) * (a[i] + a[i + 1]);
            denom = 2 * lo + 2;
            bestMid = i;
            bestCnt = lo;
            doubleMid = true;
        }
    }
    ans.pb(a[bestMid]);
    if (doubleMid) ans.pb(a[bestMid + 1]);
    REP(i, bestCnt) {
        ans.pb(a[bestMid - 1 - i]);
        ans.pb(a[n - 1 - i]);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}