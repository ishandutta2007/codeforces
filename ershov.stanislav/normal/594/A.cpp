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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 5e5 + 100;
int n;
int a[maxn];

int main() {
#ifdef LOCAL
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    {
        int ans = INF;
        for (int i = 0; i + n / 2 < n; i++) {
            ans = min(ans, a[i + n / 2] - a[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}