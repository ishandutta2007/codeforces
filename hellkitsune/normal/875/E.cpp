#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, s, t;
int x[100000];
bool need[100000];

bool solve(int dist) {
    if (abs(s - t) > dist) return false;
    memset(need, 0, sizeof need);
    forn(i, n - 1) if (abs(x[i] - x[i + 1]) > dist) {
        need[i + 1] = true;
    }
    int mn = x[n - 1];
    int mx = x[n - 1];
    for (int i = n - 1; i >= 1; --i) {
        if (need[i] || abs(mn - x[i - 1]) > dist || abs(mx - x[i - 1]) > dist) {
            mn = min(mn, x[i - 1]);
            mx = max(mx, x[i - 1]);
            need[i] = true;
        } else {
            mn = x[i - 1];
            mx = x[i - 1];
        }
    }
    if (abs(s - mn) <= dist && abs(s - mx) <= dist) {
        return true;
    }
    if (abs(t - mn) <= dist && abs(t - mx) <= dist) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &s, &t);
    forn(i, n) scanf("%d", x + i);
    int lo = 0, hi = int(1e9) + 123, mid;
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