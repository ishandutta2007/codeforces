#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;
int c[1000000];
vector<int> p;
const LL INF = 1e18;
LL ans = INF;

void go(int y) {
    for (int x = c[y] - 1; x <= c[y] + 1; ++x) {
        int rem = x;
        for (int i = 2; i <= 40000; ++i) if (rem % i == 0) {
            rem /= i;
            p.pb(i);
            while (rem % i == 0) rem /= i;
        }
        if (rem > 1) p.pb(rem);
    }
}

LL le[2][1000001], ri[2][1000001];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &a, &b);
    REP(i, n) scanf("%d", c + i);
    go(0);
    if (n != 1) go(n - 1);
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for (int x : p) {
        le[0][0] = 0;
        le[1][0] = INF;
        REP(i, n) {
            if (c[i] % x == 0) {
                le[0][i + 1] = le[0][i];
            } else if ((c[i] - 1) % x == 0 || (c[i] + 1) % x == 0) {
                le[0][i + 1] = min(INF, le[0][i] + b);
            } else {
                le[0][i + 1] = INF;
            }
            if (i == 0) le[1][1] = INF;
            else le[1][i + 1] = min(INF, min(le[1][i] + a, le[0][i] + a));
        }
        ri[0][n] = 0;
        ri[1][n] = INF;
        for (int i = n - 1; i >= 0; --i) {
            if (c[i] % x == 0) {
                ri[0][i] = ri[0][i + 1];
            } else if ((c[i] - 1) % x == 0 || (c[i] + 1) % x == 0) {
                ri[0][i] = min(INF, ri[0][i + 1] + b);
            } else {
                ri[0][i] = INF;
            }
            if (i == n - 1) ri[1][i] = INF;
            else ri[1][i] = min(INF, min(ri[1][i + 1] + a, ri[0][i + 1] + a));
        }
        REP(i, n + 1) ans = min(ans, min(le[0][i], le[1][i]) + min(ri[0][i], ri[1][i]));
        LL cum = 0;
        REP(i, n) {
            if (c[i] % x == 0) {

            } else if ((c[i] - 1) % x == 0 || (c[i] + 1) % x == 0) {
                cum += b;
            } else {
                break;
            }
            ans = min(ans, cum + (LL)a * (n - i - 1));
        }
        cum = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (c[i] % x == 0) {

            } else if ((c[i] - 1) % x == 0 || (c[i] + 1) % x == 0) {
                cum += b;
            } else {
                break;
            }
            ans = min(ans, cum + (LL)a * i);
        }
    }
    cout << ans << endl;
    return 0;
}