#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const int P = 1e9+7;
const ll lINF = 1e18;

using namespace std;

int n, m, q;
unordered_map<int, int> prv[111111];
map<int, int> sz[111111];
map<pair<int, int>, int> answers;

int get(int v, int c) {
    if (!prv[v].count(c) || prv[v][c] == v) {
        return v;
    } else {
        return prv[v][c] = get(prv[v][c], c);
    }
}

void unite(int v1, int v2, int c) {
    int r1 = get(v1, c);
    int r2 = get(v2, c);
    if (!sz[v1][c]) {
        sz[v1][c] = 1;
    }
    if (!sz[v2][c]) {
        sz[v2][c] = 1;
    }
    if (sz[r1][c] > sz[r2][c]) {
        swap(r1, r2);
    }
    prv[r1][c] = r2;
    prv[r2][c] = r2;
    sz[r2][c] = sz[r1][c]+sz[r2][c];
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        unite(a, b, c);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (answers.count({u, v})) {
            printf("%d\n", answers[{u, v}]);
            continue;
        }
        if (prv[u].size() > prv[v].size()) {
            swap(u, v);
        }
        int ans = 0;
        for (auto i : prv[u]) {
            if (i.sc != 0 && get(u, i.fs) == get(v, i.fs)) {
                ans++;
            }
        }
        answers[{u, v}] = ans;
        answers[{v, u}] = ans;
        printf("%d\n", ans);
    }
    return 0;
}