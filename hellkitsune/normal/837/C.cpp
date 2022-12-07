#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;
int x[100], y[100];

int solve(int x, int y, int xx, int yy) {
    if (x > a || xx > a || y > b || yy > b) {
        return 0;
    }
    if (x + xx > a && y + yy > b) {
        return 0;
    }
    return x * y + xx * yy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    forn(i, n) cin >> x[i] >> y[i];
    int ans = 0;
    forn(i, n) forn(j, i) {
        ans = max(ans, solve(x[i], y[i], x[j], y[j]));
        ans = max(ans, solve(y[i], x[i], x[j], y[j]));
        ans = max(ans, solve(x[i], y[i], y[j], x[j]));
        ans = max(ans, solve(y[i], x[i], y[j], x[j]));
    }
    cout << ans << endl;
    return 0;
}