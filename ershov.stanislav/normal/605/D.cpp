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

const int maxn = 3e5 + 100;
int a[maxn], b[maxn], c[maxn], d[maxn];
vector<int> tree[maxn * 4];
int postree[maxn * 4];
int n;
vector<vector<int> > vect(maxn);
int pre[maxn];
int dist[maxn];
int used[maxn];
queue<int> q;

bool mycomp(int i, int j) {
    return b[i] < b[j];
}

void build(int v, int vl, int vr) {
    if (vr == vl + 1) {
        tree[v] = vect[vl];
    } else {
        int mid = (vl + vr) / 2;
        build(v * 2, vl, mid);
        build(v * 2 + 1, mid, vr);
        int i = 0, j = 0;
        for (; i < sz(tree[v * 2]) && j < sz(tree[v * 2 + 1]); ) {
            if (mycomp(tree[v * 2][i], tree[v * 2 + 1][j])) {
                tree[v].pb(tree[v * 2][i]);
                i++;
            } else {
                tree[v].pb(tree[v * 2 + 1][j]);
                j++;
            }
        }
        for (; i < sz(tree[v * 2]); i++) {
            tree[v].pb(tree[v * 2][i]);
        }
        for (; j < sz(tree[v * 2 + 1]); j++) {
            tree[v].pb(tree[v * 2 + 1][j]);
        }
    }
}

void make(int v, int vl, int vr, int l, int r, int tomax, int curdist, int start) {
    if (vr <= l || r <= vl) {
        return;
    }
    if (l <= vl && vr <= r) {
        for (int & i = postree[v]; i < sz(tree[v]); i++) {
            int cur = tree[v][i];
            if (b[cur] >= tomax) {
                break;
            }
            if (used[cur]) {
                continue;
            }
            dist[cur] = curdist + 1;
            used[cur] = 1;
            pre[cur] = start;
            q.push(cur);
        }
    } else {
        int mid = (vl + vr) / 2;
        make(v * 2, vl, mid, l, r, tomax, curdist, start);
        make(v * 2 + 1, mid, vr, l, r, tomax, curdist, start);
    }
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
    }
    vector<int> ac;
    {
        for (int i = 0; i < n; i++) {
            ac.pb(a[i]);
            ac.pb(c[i]);
        }
        sort(all(ac));
        ac.resize(distance(ac.begin(), unique(all(ac))));
        for (int i = 0; i < n; i++) {
            a[i] = (int) (lower_bound(all(ac), a[i]) - ac.begin());
            c[i] = (int) (lower_bound(all(ac), c[i]) - ac.begin());
        }
    }
    /*for (int i = 0; i < n; i++) {
        cout << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << d[i] <<     endl;
    }*/
    {
        for (int i = 0; i < n; i++) {
            vect[a[i]].pb(i);
        }
        for (int i = 0; i < sz(ac); i++) {
            sort(all(vect[i]), mycomp);
        }
    }
    build(1, 0, sz(ac));
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) {
            used[i] = 1;
            dist[i] = 1;
            pre[i] = -1;
            q.push(i);
        }
    }
    while (q.size()) {
        int cur = q.front();
        q.pop();
        make(1, 0, sz(ac), 0, c[cur] + 1, d[cur] + 1, dist[cur], cur);
    }
    if (dist[n - 1] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[n - 1]);
        vector<int> ans;
        for (int i = n - 1; i >= 0; i = pre[i]) {
            ans.pb(i + 1);
        }
        reverse(all(ans));
        for (int i = 0; i < sz(ans); i++) {
            printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
        }
    }
    return 0;
}