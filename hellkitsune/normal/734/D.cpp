#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int xx, yy;
int x[500005], y[500005];
char c[500005];

bool check(int sgn, int val) {
    if (sgn < 0 && !(val < 0)) return false;
    if (sgn == 0 && !(val == 0)) return false;
    if (sgn > 0 && !(val > 0)) return false;
    return true;
}

const int INF = int(2e9) + 123;

int main() {
    scanf("%d", &n);
    scanf("%d%d", &xx, &yy);
    forn(i, n) {
        scanf(" %c%d%d", c + i, x + i, y + i);
        x[i] -= xx;
        y[i] -= yy;
    }
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int best = -1;
            int bestVal = INF;
            forn(k, n) {
                if (!check(i, x[k])) {
                    continue;
                }
                if (!check(j, y[k])) {
                    continue;
                }
                int cx = abs(x[k]);
                int cy = abs(y[k]);
                if (i != 0 && j != 0 && cx != cy) {
                    continue;
                }
                int val = max(cx, cy);
                if (val < bestVal) {
                    bestVal = val;
                    best = k;
                }
            }
            if (best != -1) {
                if (i == 0 || j == 0) {
                    if (c[best] == 'R' || c[best] == 'Q') {
                        cout << "YES" << endl;
                        return 0;
                    }
                } else {
                    if (c[best] == 'B' || c[best] == 'Q') {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}