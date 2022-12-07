#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int c[100][100];
int mn[100];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) REP(j, m) scanf("%d", c[i] + j);
    REP(i, n) {
        mn[i] = c[i][0];
        REP(j, m) mn[i] = min(mn[i], c[i][j]);
    }
    int mx = mn[0];
    REP(i, n) mx = max(mx, mn[i]);
    printf("%d\n", mx);
    return 0;
}