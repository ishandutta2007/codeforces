#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[100][100], b[100][100];
vector<PII> ans;

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) forn(j, m) {
        scanf("%d", a[i] + j);
    }
    int x = n > m;
    if (x) {
        swap(n, m);
        forn(i, n) forn(j, m) {
            b[i][j] = a[j][i];
        }
        forn(i, n) forn(j, m) {
            a[i][j] = b[i][j];
        }
    }

    int mn = 1234;
    forn(i, m) mn = min(mn, a[0][i]);
    forn(i, m) if (a[0][i] != mn) {
        int cnt = a[0][i] - mn;
        forn(j, cnt) ans.pb(mp(1 ^ x, i));
        forn(j, n) {
            a[j][i] -= cnt;
        }
    }
    forn(i, n) forn(j, m - 1) {
        if (a[i][j] != a[i][j + 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    forn(i, n) forn(j, a[i][0]) {
        ans.pb(mp(0 ^ x, i));
    }
    printf("%d\n", (int)ans.size());
    for (PII x : ans) if (x.first == 0) {
        printf("row %d\n", x.second + 1);
    } else {
        printf("col %d\n", x.second + 1);
    }
    return 0;
}