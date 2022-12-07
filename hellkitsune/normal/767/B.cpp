#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = LL(1e18);

LL from, to, t;
int n;
LL a[100000];
LL best = INF;
LL ans = 0;

int main() {
    cin >> from >> to >> t;
    scanf("%d", &n);
    forn(i, n) scanf("%I64d", a + i);
    if (n == 0) {
        cout << from << endl;
        return 0;
    }
    if (a[0] > 0) {
        best = from - (a[0] - 1);
        ans = min(from, a[0] - 1);
    }
    LL curT = max(from, a[0]) + t;
    for (int i = 1; i < n; ++i) {
        if (curT + t > to) {
            break;
        }
        if (a[i] > a[i - 1]) {
            if (a[i] - 1 >= curT) {
                cout << curT << endl;
                return 0;
            }
            if (curT - a[i] + 1 < best) {
                best = curT - a[i] + 1;
                ans = a[i] - 1;
            }
        }
        curT = max(curT, a[i]) + t;
    }
    if (curT + t <= to) {
        best = 0;
        ans = curT;
    }
    cout << ans << endl;
    return 0;
}