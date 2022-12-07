#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<LL> a[4];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        int w, c;
        scanf("%d%d", &w, &c);
        a[w].pb(c);
    }
    while ((int)a[1].size() <= m) {
        a[1].pb(0);
    }
    for (int i = 1; i <= 3; ++i) {
        a[i].pb(0);
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin() + 1, a[i].end());
        for (int j = 1; j < (int)a[i].size(); ++j) {
            a[i][j] += a[i][j - 1];
        }
    }
    LL ans = 0;
    int one = 0, two = 0;
    forn(i, m + 1) {
        int three = min((int)a[3].size() - 1, (m - i) / 3);
        ans = max(ans, a[1][one] + a[2][two] + a[3][three]);
        ++one;
        while (one >= 2 && two < (int)a[2].size() - 1 && a[2][two + 1] - a[2][two] > a[1][one] - a[1][one - 2]) {
            one -= 2;
            two += 1;
        }
    }
    cout << ans << endl;
    return 0;
}