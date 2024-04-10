#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 25;
const int MOD = 1e9 + 7;

int dist1[N][N], dist2[N][N], p[N], dist[N][N];
int used[N], way[N];
ll mn[N], u[N], v[N];
int n;

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &dist1[i][j]);
//            dist1[i][j] = i * j;
            dist1[i][j] = -dist1[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &dist2[i][j]);
//            dist2[i][j] = i * j;
            dist2[i][j] = -dist2[i][j];
        }
    }
    int ans = 0;
//    int cnt = 0;
    for (int prev = 0, R = 0; R < (1 << n); R++) {
        int mask = R ^ (R >> 1);
        if (__builtin_popcount(mask) == n / 2) {
            for (int i = 1; i <= n; i++) {
                if (((mask ^ prev) & (1 << (i - 1))) || prev == 0) {
//                    cnt++;
                    memcpy(dist[i], (mask & (1 << (i - 1)) ? dist1[i] : dist2[i]), (n + 1) * sizeof(int));
                    for (int j = 1; j < n + 1; j++) {
                        mn[j] = 1e18;
                        u[i] = min(u[i], v[j] - dist[i][j]);
                    }
                    for (int j = 0; j < n + 1; j++) {
                        if (p[j] == i) {
                            p[j] = 0;
                        }
                    }
                    memset(used, 0, (n + 1) * sizeof(int));
                    int j0 = 0;
                    p[j0] = i;
                    do {
                        int j1, i0 = p[j0];
                        ll delta = 1e18;
                        used[j0] = true;
                        for (int j = 1; j <= n; j++) {
                            if (!used[j]) {
                                ll cur = dist[i0][j] - u[i0] - v[j];
                                if (cur < mn[j]) {
                                    mn[j] = cur;
                                    way[j] = j0;
                                }
                                if (mn[j] < delta) {
                                    delta = mn[j];
                                    j1 = j;
                                }
                            }
                        }
                        for (int j = 0; j <= n; j++) {
                            if (used[j]) {
                                u[p[j]] += delta;
                                v[j] -= delta;
                            } else {
                                mn[j] -= delta;
                            }
                        }
                        j0 = j1;
                    } while (p[j0] != 0);
                    do {
                        int j1 = way[j0];
                        p[j0] = p[j1];
                        j0 = j1;
                    } while (j0 != 0);
                }
            }
            int curans = 0;
            for (int i = 1; i <= n; i++) {
                curans += dist[p[i]][i];
            }
            ans = max(ans, -curans);
            prev = mask;
        }
    }
    printf("%d\n", ans);
//    cerr << cnt << endl;
    return 0;
}