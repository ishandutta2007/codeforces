#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000];
bool pr[2000001];
vector<int> ans;

int main() {
    REP(i, 2000001) pr[i] = true;
    pr[0] = pr[1] = false;
    REP(i, 2005) if (pr[i]) {
        for (int j = i * i; j <= 2000000; j += i) {
            pr[j] = false;
        }
    }
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    if (n == 1) {
        ans.pb(a[0]);
    } else if (a[0] == 1 && a[1] == 1) {
        REP(i, n) if (a[i] == 1) {
            ans.pb(1);
        }
        REP(i, n) if (a[i] != 1 && pr[a[i] + 1]) {
            ans.pb(a[i]);
            break;
        }
    } else {
        bool done = false;
        REP(i, n) {
            for (int j = i + 1; j < n; ++j) if (pr[a[i] + a[j]]) {
                ans.pb(a[i]);
                ans.pb(a[j]);
                done = true;
                break;
            }
            if (done) break;
        }
        if (!done) ans.pb(a[0]);
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}