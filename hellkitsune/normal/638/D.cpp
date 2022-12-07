#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    int a, b, c;
    S(int a, int b, int c) : a(a), b(b), c(c) {}
};

int n, m, k;
char f[100][100][105];
vector<S> from, to, moves;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) REP(j, m) {
        scanf("%s", f[i][j]);
    }
    int ans = 0;
    REP(p, n) REP(q, m) REP(r, k) if (f[p][q][r] == '1') {
        from.clear();
        to.clear();
        if (p > 0 && f[p - 1][q][r] == '1') from.pb(S(p - 1, q, r));
        if (q > 0 && f[p][q - 1][r] == '1') from.pb(S(p, q - 1, r));
        if (r > 0 && f[p][q][r - 1] == '1') from.pb(S(p, q, r - 1));
        if (p < n - 1 && f[p + 1][q][r] == '1') to.pb(S(p + 1, q, r));
        if (q < m - 1 && f[p][q + 1][r] == '1') to.pb(S(p, q + 1, r));
        if (r < k - 1 && f[p][q][r + 1] == '1') to.pb(S(p, q, r + 1));
        bool ok = false;
        for (S s : from) if (!ok) for (S t : to) {
            int cnt = 0;
            if (t.a > s.a && f[s.a + 1][s.b][s.c] == '1') ++cnt;
            if (t.b > s.b && f[s.a][s.b + 1][s.c] == '1') ++cnt;
            if (t.c > s.c && f[s.a][s.b][s.c + 1] == '1') ++cnt;
            if (cnt == 1) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}