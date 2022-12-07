#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
bool was[7] = {};

int main() {
    scanf("%d%d", &n, &m);
    int a = 0, b = 0;
    for (int i = n - 1; i > 0; i /= 7) ++a;
    for (int i = m - 1; i > 0; i /= 7) ++b;
    if (a == 0) a = 1;
    if (b == 0) b = 1;
    if (a + b > 7) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    REP(i, n) REP(j, m) {
        bool ok = true;
        REP(k, 7) was[k] = false;
        int cur = i;
        REP(times, a) {
            int val = cur % 7;
            cur /= 7;
            if (was[val]) {
                ok = false;
                break;
            }
            was[val] = true;
        }
        cur = j;
        if (ok) REP(times, b) {
            int val = cur % 7;
            cur /= 7;
            if (was[val]) {
                ok = false;
                break;
            }
            was[val] = true;
        }
        if (ok) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}