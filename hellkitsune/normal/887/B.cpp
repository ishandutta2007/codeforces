#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[3][6];
int ord[3];
int can[1111];
int ind[3];

void go(int x) {
    if (x == n) {
        int cur = 0;
        forn(i, n) {
            cur = 10 * cur + a[ord[i]][ind[i]];
        }
        can[cur] = 1;
        return;
    }
    forn(i, 6) {
        ind[x] = i;
        go(x + 1);
    }
}

void solve() {
    go(0);
}

int main() {
    int nn;
    cin >> nn;
    forn(i, nn) forn(j, 6) cin >> a[i][j];
    forn(mask, 1 << nn) if (mask) {
        n = 0;
        forn(i, nn) if (mask & (1 << i)) {
            ord[n++] = i;
        }
        do {
            solve();
        } while (next_permutation(ord, ord + n));
    }
    int ans = 0;
    while (can[ans + 1]) ++ans;
    cout << ans << endl;
    return 0;
}