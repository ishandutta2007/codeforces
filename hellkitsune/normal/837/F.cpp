#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n;
LL k;
LL a[200000];

void easySolve() {
    int st = 0;
    while (a[st] == 0) ++st;
    int ans = 0;
    while (true) {
        ++ans;
        for (int i = st + 1; i < n; ++i) {
            a[i] += a[i - 1];
            if (a[i] >= k) {
                cout << ans << endl;
                return;
            }
        }
    }
}

bool solve(LL steps) {
    Double res = a[n - 1];
    forn(i, n - 1) {
        LL y = steps - 1;
        LL dif = n - 1 - i;
        LL x = y + dif;
        Double cur = 1;
        forn(j, dif) {
            cur *= x - j;
            cur /= j + 1;
        }
        res += cur * a[i];
    }
    if (res > 2e18) {
        return true;
    }

    unsigned long long rres = a[n - 1];
    forn(i, n - 1) {
        LL y = steps - 1;
        LL dif = n - 1 - i;
        LL x = y + dif;
        unsigned long long ccur = 1;
        forn(j, dif) {
            ccur *= x - j;
            ccur /= j + 1;
        }
        rres += ccur * a[i];
    }
    return rres >= (unsigned long long)k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    forn(i, n) cin >> a[i];
    forn(i, n) if (a[i] >= k) {
        cout << 0 << endl;
        return 0;
    }
    forn(i, n - 6) if (a[i] > 0) {
        easySolve();
        return 0;
    }
    int st = 0;
    while (a[st] == 0) ++st;
    forn(i, n - st) {
        a[i] = a[i + st];
    }
    n -= st;
    LL lo = 1, hi = LL(1e18), mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (solve(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
    return 0;
}