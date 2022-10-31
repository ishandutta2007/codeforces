#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 1e6;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef DEBUG
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

using namespace std;

const int N = 2200;

int n, m;
char s[N][N];
bool l[N][N], r[N][N], u[N][N], d[N][N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        l[i][0] = (s[i][0] == '.');
        for (int j = 1; j < m; j++) {
            l[i][j] = l[i][j - 1];
            if (s[i][j] == '#') {
                l[i][j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        r[i][m - 1] = (s[i][m - 1] == '.');
        for (int j = m - 2; j >= 0; j--) {
            r[i][j] = r[i][j + 1];
            if (s[i][j] == '#') {
                r[i][j] = false;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        u[0][i] = (s[0][i] == '.');
        for (int j = 1; j < n; j++) {
            u[j][i] = u[j - 1][i];
            if (s[j][i] == '#') {
                u[j][i] = false;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        d[n - 1][i] = (s[n - 1][i] == '.');
        for (int j = n - 2; j >= 0; j--) {
            d[j][i] = d[j + 1][i];
            if (s[j][i] == '#') {
                d[j][i] = false;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (r[i][0]) {
            ans++;
        }
    }
    for (int j = 1; j < m - 1; j++) {
        if (d[0][j]) {
            ans++;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            int cnt = 0;
            if (l[i][j] && u[i][j]) {
                ans++;
            }
            if (l[i][j] && d[i][j]) {
                ans++;
            }
            if (r[i][j] && u[i][j]) {
                ans++;
            }
            if (r[i][j] && d[i][j]) {
                ans++;
            }
        }
    }
    for (int i = 1; i < n - 1; i++) {
        int cnt = 0;
        for (int j = 1; j < m; j++) {
            if (j < m - 2) {
                if (u[i][j] && u[i][j + 1]) {
                    ans--;
                }
                if (d[i][j] && d[i][j + 1]) {
                    ans--;
                }
            }
            if (s[i][j] == '#' || j == m - 1) {
                cnt = 0;
            } else {
                if (d[i][j]) {
                    ans += cnt;
                }
                if (u[i][j]) {
                    ans += cnt;
                }
                if (u[i][j]) {
                    cnt++;
                }
                if (d[i][j]) {
                    cnt++;
                }
            }
        }
    }
    for (int j = 1; j < m - 1; j++) {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (i < n - 2) {
                if (l[i][j] && l[i + 1][j]) {
                    ans--;
                }
                if (r[i][j] && r[i + 1][j]) {
                    ans--;
                }
            }
            if (s[i][j] == '#' || i == n - 1) {
                cnt = 0;
            } else {
                if (r[i][j]) {
                    ans += cnt;
                }
                if (l[i][j]) {
                    ans += cnt;
                }
                if (l[i][j]) {
                    cnt++;
                }
                if (r[i][j]) {
                    cnt++;
                }
            }
        }
    }

    printf(LLD"\n", ans);
    return 0;
}