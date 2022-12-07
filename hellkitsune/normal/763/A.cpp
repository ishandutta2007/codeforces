#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[100000];
int cnt[100000];
int col[100000];

int main() {
    scanf("%d", &n);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) {
        scanf("%d", col + i);
    }
    forn(i, n) {
        cnt[i] = 0;
        for (int to : g[i]) if (col[i] != col[to]) {
            ++cnt[i];
        }
    }
    int bad = 0;
    forn(i, n) if (cnt[i] > 0) {
        ++bad;
    }
    if (bad == 0) {
        printf("YES\n1\n");
        return 0;
    }
    forn(i, n) if (cnt[i] > 0) {
        int cur = 1;
        for (int to : g[i]) if (cnt[to] == 1) {
            ++cur;
        }
        if (cur == bad) {
            printf("YES\n%d\n", i + 1);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}