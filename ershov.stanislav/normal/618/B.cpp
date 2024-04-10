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

const int maxn = 100;

int used[maxn];
int can[maxn][maxn];
int ans[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            can[a][i] = 1;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n; j++) {
            if (!used[j] && can[i][j]) {
                used[j] = 1;
                ans[j] = i;
            }
        }
    }
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (flag && ans[i] == n - 1) {
            printf("%d%c", n, " \n"[i == n - 1]);
        } else printf("%d%c", ans[i], " \n"[i == n - 1]);
        if (ans[i] == n - 1) {
            flag = 1;
        }
    }
    return 0;
}