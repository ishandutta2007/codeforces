#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(2e9);

int n, m;
int p[200000], a[200000], b[200000];
vector<int> v[3][3];
int pos[3][3] = {};

int solve(int col) {
    int ii = -1, jj = -1, best = INF;
    forn(i, 3) forn(j, 3) if (i == col || j == col) {
        if (pos[i][j] < (int)v[i][j].size()) {
            if (v[i][j][pos[i][j]] < best) {
                best = v[i][j][pos[i][j]];
                ii = i;
                jj = j;
            }
        }
    }
    if (ii == -1) {
        return -1;
    }
    ++pos[ii][jj];
    return best;
}

vector<int> ans;

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", p + i);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", b + i);
    forn(i, n) {
        v[a[i] - 1][b[i] - 1].pb(p[i]);
    }
    forn(i, 3) forn(j, 3) {
        sort(v[i][j].begin(), v[i][j].end());
    }
    scanf("%d", &m);
    forn(i, m) {
        int col;
        scanf("%d", &col), --col;
        ans.pb(solve(col));
    }
    for (int x : ans) printf("%d ", x);
    puts("");
    return 0;
}