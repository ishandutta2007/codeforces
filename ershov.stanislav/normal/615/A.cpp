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

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 1e5;

bool on[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int cnt;
        scanf("%d", &cnt);
        for (int i = 0; i < cnt; i++) {
            int cur;
            scanf("%d", &cur);
            on[cur - 1] = true;
        }
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
        ok = ok & on[i];
    }
    if (ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}