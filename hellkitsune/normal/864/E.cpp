#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int t[100], de[100], cost[100];
int d[101][2001], p[101][2001];
vector<int> ans;
int ord[100];

inline bool cmp(const int &lhs, const int &rhs) {
    return de[lhs] < de[rhs];
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d%d", t + i, de + i, cost + i), --de[i];
    forn(i, n + 1) forn(j, 2001) d[i][j] = -1;
    forn(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    d[0][0] = 0;
    forn(i, n) forn(j, 2001) if (d[i][j] >= 0) {
        int ind = ord[i];
        if (j + t[ind] <= de[ind] && d[i + 1][j + t[ind]] < d[i][j] + cost[ind]) {
            d[i + 1][j + t[ind]] = d[i][j] + cost[ind];
            p[i + 1][j + t[ind]] = 1;
        }
        if (d[i + 1][j] < d[i][j]) {
            d[i + 1][j] = d[i][j];
            p[i + 1][j] = 0;
        }
    }
    int best = 0;
    forn(i, 2001) if (d[n][i] > d[n][best]) {
        best = i;
    }
    printf("%d\n", d[n][best]);
    for (int i = n; i > 0; --i) {
        if (p[i][best] == 1) {
            ans.pb(ord[i - 1] + 1);
            best -= t[ord[i - 1]];
        }
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}