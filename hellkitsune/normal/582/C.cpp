#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[400005];
int g[200001];
bool f[200001] = {}, go[400005];
int d[400005], e[400005];
vector<int> all;

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    //n = 196560;
    //REP(i, n) a[i] = 1;
    REP(i, n + 3) a[n + i] = a[i];
    for (int i = 1; i <= n; ++i) {
        g[i] = gcd(i, n);
        f[g[i]] = true;
    }
    int N = 2 * n;
    LL ans = 0;
    for (int x = 1; x < n; ++x) if (f[x]) {
        REP(st, x) {
            int mx = 0;
            for (int i = st; i < N; i += x) {
                mx = max(mx, a[i]);
            }
            for (int i = st; i < N; i += x) {
                go[i] = a[i] == mx;
            }
        }
        for (int i = N - 1; i >= 0; --i) if (go[i]) {
            d[i] = min(d[i + 1] + 1, n);
        } else {
            d[i] = 0;
        }
        e[0] = 0;
        for (int i = 1; i <= n; ++i) {
            e[i] = e[i - 1] + (g[i] == x);
        }
        REP(i, n) ans += e[d[i]];
    }
    cout << ans << endl;
    return 0;
}