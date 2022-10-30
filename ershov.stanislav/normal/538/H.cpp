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

vector<pair<int, int> > lr;
vector<vector<int> > g;
vector<bool> used;
vector<int> colors;
vector<pair<int, int> > segm;
vector<int> types;
int t, T;
int n, m;
int mn = -INF, mx = INF;

bool flag = true;

pair<int, int> intersect(pair<int, int> a, pair<int, int> b) {
    return mp(max(a.fs, b.fs), min(a.sc, b.sc));
}

void dfs(int v, int color) {
    if (used[v]) {
        if (colors[v] != color) {
            flag = false;
        }
        return;
    }
    used[v] = true;
    colors[v] = color;
    for (auto i : g[v]) {
        dfs(i, color ^ 1);
    }
    types[v] = segm.size() - 1 - color;
    segm[segm.size() - 1 - color] = intersect(segm[segm.size() - 1 - color], lr[v]);
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d%d%d", &t, &T, &n, &m);
    lr.resize(n + 1);
    g.resize(n + 1);
    used.resize(n + 1);
    types.resize(n + 1);
    colors.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &lr[i].fs, &lr[i].sc);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            segm.eb(-INF, INF);
            segm.eb(-INF, INF);
            dfs(i, 0);
        }
        mn = max(mn, min(segm.back().fs, segm[segm.size() - 2].fs));
        mx = min(mx, max(segm.back().sc, segm[segm.size() - 2].sc));
    }

//    for (auto i : segm) {
//        cout << i.fs << ' ' << i.sc << endl;
//    }

    if (!flag) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int mnr = INF, mxl = -INF;

    int n1, n2;

    for (int i = 0; i < segm.size(); i++) {
        mnr = min(mnr, segm[i].sc);
        mxl = max(mxl, segm[i].fs);
    }

    vector<pair<int, int> > segml, segmr;

//    cout << mnr << ' ' << mxl << endl;

    for (int i = 0; i < segm.size(); i++) {
        if (segm[i].fs > mnr) {
            segmr.pb(segm[i]);
        }
        if (segm[i].sc < mxl) {
            segml.pb(segm[i]);
        }
    }

    segml.eb(mn, mx);
    segmr.eb(mn, mx);

    flag = false;

    pair<int, int> inter(t - mnr, T - mnr);

    for (auto i : segmr) {
        inter = intersect(inter, i);
    }

    if (inter.fs <= inter.sc) {
        n1 = mnr;
        n2 = inter.sc;
        if (n1 >= 0 && n2 >= 0 && mnr >= mn && mnr <= mx) flag = true;
    }

    inter = make_pair(t - mxl, T - mxl);

    for (auto i : segml) {
        inter = intersect(inter, i);
    }

    if (inter.fs <= inter.sc) {
        n1 = mxl;
        n2 = inter.sc;
        if (n1 >= 0 && n2 >= 0 && mxl >= mn && mxl <= mx) flag = true;
    }

    if (flag) {
        vector<int> groups_types(segm.size());
        for (int i = 0; i < segm.size(); i += 2) {
            if (n1 >= segm[i].fs && n1 <= segm[i].sc && n2 >= segm[i + 1].fs && n2 <= segm[i + 1].sc) {
                groups_types[i] = 1;
                groups_types[i + 1] = 2;
            }
            if (n2 >= segm[i].fs && n2 <= segm[i].sc && n1 >= segm[i + 1].fs && n1 <= segm[i + 1].sc) {
                groups_types[i] = 2;
                groups_types[i + 1] = 1;
            }
        }

//        for (auto i : groups_types) {
//            cout << i << ' ';
//        }
//        cout << endl;

        printf("POSSIBLE\n");
        printf("%d %d\n", n1, n2);
        for (int i = 1; i <= n; i++) {
            printf("%d", groups_types[types[i]]);
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}