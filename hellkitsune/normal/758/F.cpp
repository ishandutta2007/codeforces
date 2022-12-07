#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, l, r;
LL ans = 0;

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

void solve(int num, int denom) {
    int x = denom;
    forn(i, n - 2) {
        x *= denom;
    }
    int mn = (l + x - 1) / x;
    int mx = r / x;

    int y = num;
    forn(i, n - 2) {
        y *= num;
    }
    mn = max(mn, (l + y - 1) / y);
    mx = min(mx, r / y);
    if (mx >= mn) {
        //cerr << num << '/' << denom << ": " << mn << " to " << mx << endl;
        ans += mx - mn + 1;
    }
}

int main() {
    cin >> n >> l >> r;
    if (n == 1) {
        cout << r - l + 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << (LL)(r - l + 1) * (r - l) << endl;
        return 0;
    }
    for (int num = 1; ; ++num) {
        bool ok = true;
        LL x = 1;
        forn(i, n - 1) {
            x *= num;
            if (x > r) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            break;
        }
        for (int denom = 1; denom <= num; ++denom) {
            if (gcd(num, denom) != 1 || (num == 1 && denom == 1)) {
                continue;
            }
            solve(num, denom);
            if (num != denom) {
                solve(denom, num);
            }
        }
    }
    cout << ans << endl;
    return 0;
}