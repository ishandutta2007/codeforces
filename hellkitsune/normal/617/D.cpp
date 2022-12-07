#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int x[3], y[3];

int main() {
    REP(i, 3) scanf("%d%d", x + i, y + i);
    int ans;
    if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2])) {
        ans = 1;
    } else {
        ans = 3;
        REP(i, 3) for (int j = i + 1; j < 3; ++j) {
            if (x[i] == x[j]) {
                REP(k, 3) if (k != i && k != j && (y[k] <= min(y[i], y[j]) || y[k] >= max(y[i], y[j]))) {
                    ans = 2;
                }
            }
            if (y[i] == y[j]) {
                REP(k, 3) if (k != i && k != j && (x[k] <= min(x[i], x[j]) || x[k] >= max(x[i], x[j]))) {
                    ans = 2;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}