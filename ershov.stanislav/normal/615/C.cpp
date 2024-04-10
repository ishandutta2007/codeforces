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

const int maxn = 8e3;

char s[maxn], t[maxn];
int n, m;
int dp[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%s %s", s, t);
    n = strlen(s);
    m = strlen(t);
    for (int i = 0; i < n; i++) {
        s[n + i + 1] = s[n - 1 - i];
    }
    n = n * 2 + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] != t[j]) {
                continue;
            }
            dp[i][j] = ((i > 0 && j > 0) ? (dp[i - 1][j - 1] + 1) : 1);
        }
    }
    vector<pair<int, int> > ans;
    for (int i = m - 1; i >= 0; ) {
        int step = 0, stepl = -1, stepr = -1;
        for (int j = 0; j < n; j++) {
            if (step < dp[j][i]) {
                step = dp[j][i];
                stepr = j;
                stepl = j - step + 1;
            }
        }
        if (step == 0) {
            cout << "-1" << endl;
            return 0;
        } else {
            if (stepl >= (n - 1) / 2) {
                stepl -= (n - 1) / 2 + 1;
                stepr -= (n - 1) / 2 + 1;
                stepl = (n - 1) / 2 - 1 - stepl;
                stepr = (n - 1) / 2 - 1 - stepr;
            }
            ans.eb(stepl, stepr);
            i -= step;
        }
    }
    reverse(all(ans));
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
    return 0;
}