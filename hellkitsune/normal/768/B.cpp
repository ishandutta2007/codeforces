#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, from, to;

LL calc(LL x) {
    if (x < 2) {
        return 1;
    }
    return 2 * calc(x / 2) + 1;
}

LL solve(LL x, LL bound) {
    if (bound <= 0) {
        return 0;
    }
    if (x < 2) {
        return x;
    }
    LL cnt = calc(x / 2);
    if (bound <= cnt) {
        return solve(x / 2, bound);
    }
    return x / 2 + x % 2 + solve(x / 2, bound - cnt - 1);
}

int main() {
    cin >> n >> from >> to;
    cout << solve(n, to) - solve(n, from - 1) << endl;
    return 0;
}