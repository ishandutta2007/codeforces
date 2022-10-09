#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

#define double long double

using namespace std;

map<pair<double, pair<double, int>>, double> dp;
const double eps = 1e-6;

double v;

double solve(double a, double b, int d) {
    if (dp.count({a, {b, d}}))
        return dp[{a, {b, d}}];
    // if (dp.count(make_pair(b, a)))
    //     return dp[make_pair(b, a)];

    double res = 0;
    // cout << setprecision(5) << a << ' ' << b << '\n';
    if (a > eps) {
        if (b <= eps) {
            if (a - v > eps) {
                res += a * solve(a - v, 0, d + 1);
            } else {
                res += a * solve(0, 0, d + 1);
            }
        } else {
            if (a - v > eps) {
                res += a * solve(a - v, b + v / 2, d + 1);
            } else {
                res += a * solve(0, b + a / 2, d + 1);
            }
        }
    }
    if (b > eps) {
        if (a <= eps) {
            if (b - v > eps) {
                res += b * solve(0, b - v, d + 1);
            } else {
                res += b * solve(0, 0, d + 1);
            }
        } else {
            if (b - v > eps) {
                res += b * solve(a + v / 2, b - v, d + 1);
            } else {
                res += b * solve(a + b / 2, 0, d + 1);
            }
        }
    }
    // cout << setprecision(5) << a << ' ' << b << ' ' << d << ':' << res + (1 - a - b) * d << '\n';
    // if (d > 4)
    //     return 0;
    dp[{a, {b, d}}] = res + (1 - a - b) * d;
    return res + (1 - a - b) * d;
}

void solve() {
    double a, b, c;
    cin >> a >> b >> c >> v;
    dp.clear();
    cout << setprecision(228) << solve(a, b, 1) << '\n';
    // cout << solve(a, b, 1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}