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

const int INF = 1e9 + 100;
const ll lINF = 4e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, m, a[111], cnt0[111], cnt1[111], match[10000];
bool match_first[10000];
vector<pair<int, int> > graph;
vector<int> g[10000];
vector<vector<int> > facts[2];
bool used[10000];

vector<int> fact(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans.pb(i);
            n /= i;
        }
    }
    if (n > 1) {
        ans.pb(n);
    }
    return ans;
}

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (auto i : g[v]) {
        if (match[i] == -1) {
            match[i] = v;
            return true;
        }
    }
    for (auto i : g[v]) {
        if (dfs(match[i])) {
            match[i] = v;
            return true;
        }
    }
    return false;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    int graph_size = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        vector<int> factorization = fact(a[i]);
        facts[i % 2].pb(factorization);
        if (i % 2 == 0) {
            cnt0[i / 2 + 1] = cnt0[i / 2] + factorization.size();
            graph_size += factorization.size();
        } else {
            cnt1[i / 2 + 1] = cnt1[i / 2] + factorization.size();
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        if (a % 2) {
            swap(a, b);
        }
        graph.eb(a / 2, b / 2);
    }
//    for (auto i : graph) {
//        cout << i.fs << ' ' << i.sc << endl;
//    }
    for (int i = 0; i < m; i++) {
        vector<int> &v1 = facts[0][graph[i].fs], & v2 = facts[1][graph[i].sc];
        int d1 = cnt0[graph[i].fs], d2 = cnt1[graph[i].sc];
        for (int i = 0, j  = 0; i < (int) v1.size(); i++) {
            while (j < (int) v2.size() && v2[j] < v1[i]) {
                j++;
            }
            for (int k = j; k < (int) v2.size() && v2[k] == v1[i]; k++) {
                g[i + d1].pb(k + d2);
            }
        }
    }
    memset(match, -1, 10000 * sizeof (int));
    for (int run = 1; run; ) {
        run = 0;
        memset(used, false, graph_size * sizeof(bool));
        for (int i = 0; i < graph_size; i++) {
            if (!match_first[i] && dfs(i)) {
                run = 1;
                match_first[i] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 10000; i++) {
        if (match[i] != -1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}