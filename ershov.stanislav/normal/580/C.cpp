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

const int N = 5e5 + 100;

int n, m;
int a[N];
vector<int> tree[N];
int ans;

void dfs(int v, int par, int cnt, int mx) {
    cnt += a[v];
    if (!a[v]) {
        cnt = 0;
    }
    mx = max(mx, cnt);
    int nxt = 0;
    for (auto i : tree[v]) {
        if (par != i) {
            nxt++;
            dfs(i, v, cnt, mx);
        }
    }
    if (!nxt && mx <= m) {
        ans++;
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(0, -1, 0, 0);
    cout << ans << endl;

    return 0;
}