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

const int N = 9e5 + 100;

int n, last[N], used[N], bad[N];
int color[N];
vector<pair<int, int> > g[N];
map<pair<int, int>, int> m;
vector<int> ans;

void dfs(int v) {
    for (; last[v] < (int) g[v].size(); ) {
        last[v]++;
        if (!used[g[v][last[v] - 1].sc]) {
            used[g[v][last[v] - 1].sc] = true;
            dfs(g[v][last[v] - 1].fs);
        }
    }
    ans.pb(v);
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        y += 250000;
        g[x].eb(y, i);
        g[y].eb(x, i);
        m[mp(x, y)] = i;
        m[mp(y, x)] = i;
    }
    vector<int> odd;
    for (int i = 0; i < N; i++) {
        if ((int) g[i].size() % 2 == 1) {
            odd.pb(i);
        }
    }
    int t = 250000;
    while (odd.size()) {
        int a = odd.back();
        odd.pop_back();
        int b = odd.back();
        odd.pop_back();
        g[a].eb(b, ++t);
        g[b].eb(a, t);
        m[mp(a, b)] = t;
        m[mp(b, a)] = t;
        bad[t] = true;
    }
    for (int i = 0; i < N; i++) {
        ans.clear();
        dfs(i);

        int b = 0;
        for (int i = 0; i + 1 < (int) ans.size(); i++) {
            if (bad[m[mp(ans[i], ans[i + 1])]]) {
                b = i;
                break;
            }
        }

        vector<int> ans2;
        for (int i = b; i < ans.size(); i++) {
            ans2.pb(ans[i]);
        }
        for (int i = 1; i <= b; i++) {
            ans2.pb(ans[i]);
        }

        swap(ans, ans2);

        for (int i = 0; i + 1 < (int) ans.size(); i++) {
            color[m[mp(ans[i], ans[i + 1])]] = i % 2;
        }
    }

    for (int i = 0; i < n; i++) {
        if (color[i]) {
            printf("b");
        } else {
            printf("r");
        }
    }

    return 0;
}