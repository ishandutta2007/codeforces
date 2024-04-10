#include<bits/stdc++.h>

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
#define rank _rank

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

const int N = 5100;

int n, sz[N];
vector<int> tree[N];
int dp[N][N];

vector<int> get(int v) {
    vector<int> ans(sz[v] + 1);
    for (int i = 0; i <= sz[v]; i++) {
        ans[i] = dp[v][i];
    }
    for (int i = 0; i <= sz[v]; i++) {
        ans[i] = min(ans[i], 1 + dp[v][sz[v] - i]);
    }
    return ans;
}

void dfs(int v, int par) {
    if ((int) tree[v].size() == 1) {
        dp[v][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[v][i] = INF;
        }
        sz[v] = 1;
        return;
    }
    for (auto i : tree[v]) {
        if (par != i) {
            dfs(i, v);
            sz[v] += sz[i];
        }
    }
    vector<int> ans(n + 1, INF);
    sz[v] = 0;
    ans[0] = 0;
//    cout << v << endl;
    for (auto i : tree[v]) {
        if (par != i) {
            vector<int> cur = get(i);
//            for (auto i : cur) {
//                cout << i << ' ';
//            }
//            cout << endl;
            for (int k = sz[v] + sz[i]; k >= 0; k--) {
                for (int j = max(1, k - sz[v]); j <= k && j <= sz[i]; j++) {
                    ans[k] = min(ans[k], ans[k - j] + cur[j]);
                }
            }
//            for (auto i : ans) {
//                cout << i << ' ';
//            }
//            cout << endl;
            sz[v] += sz[i];
        }
    }
    for (int i = 0; i <= n; i++) {
        dp[v][i] = ans[i];
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        tree[x].pb(y);
        tree[y].pb(x);
    }
    int root = 0;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if ((int) tree[i].size() >= 2) {
            root = i;
            break;
        }
    }
    dfs(root, 0);
    assert(sz[root] % 2 == 0);
    cout << dp[root][sz[root] / 2] << endl;
    return 0;
}