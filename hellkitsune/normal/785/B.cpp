#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int l[200000], r[200000];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", l + i, r + i);
    sort(l, l + n);
    sort(r, r + n);
    scanf("%d", &m);
    int ans = 0;
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to);
        ans = max(ans, l[n - 1] - to);
        ans = max(ans, from - r[0]);
    }
    cout << ans << endl;
    return 0;
}