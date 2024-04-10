#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, m;
int dp[1500000];
char s[22][22];
int ch[26], sum[26], a[22][22], sum2[26];
int mm[1500000];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i < (1 << n); i++) {
        dp[i] = INF;
        mm[i] = INF;
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < 26; i++) {
            ch[i] = sum[i] = 0;
            sum2[i] = INF;
        }
        for (int i = 0; i < n; i++) {
            ch[s[i][j] - 'a'] |= 1 << i;
            sum[s[i][j] - 'a'] += a[i][j];
            mm[1 << i] = min(mm[1 << i], a[i][j]);
        }
        for (int i = 0; i < n; i++) {
            sum2[s[i][j] - 'a'] = min(sum2[s[i][j] - 'a'], sum[s[i][j] - 'a'] - a[i][j]);
        }
        for (int i = 0; i < 26; i++) {
            mm[ch[i]] = min(mm[ch[i]], sum2[i]);
        }
    }
    vector<pair<int, int> > v;
    for (int i = 0; i < (1 << n); i++) {
        if (mm[i] != INF) {
            v.eb(i, mm[i]);
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (auto i : v) {
            dp[mask | i.fs] = min(dp[mask | i.fs], dp[mask] + i.sc);
        }
    }

    printf("%d", dp[(1 << n) - 1]);

    return 0;
}