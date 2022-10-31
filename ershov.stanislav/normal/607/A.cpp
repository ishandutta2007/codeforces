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

const int maxn = 1e5 + 100;
int n;
pair<int, int> v[maxn];
int dp[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    sort(v, v + n);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int j = (int) (lower_bound(v, v + n, mp(v[i].first - v[i].second, -INF)) - v);
        dp[i + 1] = dp[j] + 1;
        ans = min(ans, n - dp[i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}