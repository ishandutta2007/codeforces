#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL k, d, t;

int main() {
    cin >> k >> d >> t;
    LL rest = (d - k % d) % d;
    t *= 2;
    LL times = t / (2 * k + rest);
    t %= 2 * k + rest;
    long double ans = times * (k + rest);
    if (t <= 2 * k) {
        ans += (long double)t / 2;
    } else {
        ans += k;
        t -= 2 * k;
        ans += t;
    }
    printf("%.12f\n", (double)ans);
    return 0;
}