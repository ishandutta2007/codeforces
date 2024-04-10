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

const int maxn = 2e5 + 100;

int x, y;
int n;
vector<int> tree[maxn];

pair<int, int> dfs(int v, int par = -1) {
    vector<int> v1, v2;
    for (int i = 0; i < sz(tree[v]); i++) {
        int to = tree[v][i];
        if (to == par) {
            continue;
        } else {
            pair<int, int> cur = dfs(to, v);
            v1.pb(cur.fs);
            v2.pb(cur.sc);
        }
    }
    sort(all(v1));
    sort(all(v2));
    int sum = 0;
    for (int i = 0; i < sz(v1); i++) {
        sum += v1[i];
    }
    int ans1 = sum;
    if (sz(v2) >= 1) {
        ans1 = max(ans1, sum - v2[0] + 1);
    }
    int ans2 = ans1;
    if (sz(v2) >= 2) {
        ans2 = max(ans2, sum - v2[0] - v2[1] + 2);
    }
    return mp(ans2, ans2 - ans1);
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &x, &y);
    
    int cnt1 = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    
    if (x > y) {
        for (int i = 0; i < n; i++) {
            if (sz(tree[i]) == 1) {
                cnt1++;
            }
        }
        if (cnt1 >= n - 1) {
            printf(LLD "\n", (ll) (n - 2) * y + x);
        } else {
            printf(LLD "\n", (ll) (n - 1) * y);
        }
    } else {
        int ans = dfs(0).fs;
        printf(LLD "\n", (ll) ans * x + (ll) (n - 1 - ans) * y);
    }
    
    return 0;
}