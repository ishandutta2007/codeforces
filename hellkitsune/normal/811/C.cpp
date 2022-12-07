#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
int a[5000], le[5001], ri[5001], d[5001];
bool was[5001];

int main() {
    forn(i, 5001) {
        le[i] = INF;
        ri[i] = -INF;
    }
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
        le[a[i]] = min(le[a[i]], i);
        ri[a[i]] = max(ri[a[i]], i);
    }
    forn(i, n + 1) {
        d[i] = -INF;
    }
    d[0] = 0;
    forn(i, n) if (d[i] != -INF) {
        d[i + 1] = max(d[i + 1], d[i]);
        int l = i;
        int r = i;
        int sum = 0;
        memset(was, 0, sizeof was);
        for (int j = i; j <= r; ++j) {
            l = min(l, le[a[j]]);
            r = max(r, ri[a[j]]);
            if (!was[a[j]]) {
                was[a[j]] = true;
                sum ^= a[j];
            }
        }
        if (l == i) {
            d[r + 1] = max(d[r + 1], d[i] + sum);
        }
    }
    cout << d[n] << endl;
    return 0;
}