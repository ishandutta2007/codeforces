#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

#define next _next
#define prev _prev
#define hash _hash
#define all(s) s.begin(), s.end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

struct query {
    int x1, y1, x2, y2, i;
    query(int x1, int y1, int x2, int y2, int i) : x1(x1), y1(y1), x2(x2), y2(y2), i(i) {}
};

bool comp_xy(query a, query b) {
    return (a.x2 < b.x2);
}

bool comp_yx(query a, query b) {
    return (a.y2 < b.y2);
}

int n, m, k, Q;
int tree[500000];
bool good[220000];
vector<pair<int, int> > xy, yx;
vector<query> q;

int get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || vl >= r) {
        return INF;
    } else {
        if (vl >= l && vr <= r) {
            return tree[v];
        } else {
            int mid = (vl + vr) / 2;
            return min(get(v * 2 + 1, vl, mid, l, r), get(v * 2 + 2, mid, vr, l, r));
        }
    }
}

void upd(int v, int vl, int vr, int i, int n_val) {
    if (vr <= i || vl > i) {
        return;
    } else {
        if (vl == i && vr == i + 1) {
            tree[v] = n_val;
        } else {
            int mid = (vl + vr) / 2;
            upd(v * 2 + 1, vl, mid, i, n_val);
            upd(v * 2 + 2, mid, vr, i, n_val);
            tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
}

int main()
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &m, &k, &Q);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        xy.emplace_back(x, y);
        yx.emplace_back(y, x);
//        cout << x << ' ' << y << endl;
    }
    sort(all(xy));
    sort(all(yx));

    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        q.pb(query(x1, y1, x2, y2, i + 1));
    }

    sort(all(q), comp_xy);

    memset(tree, INF, 500000 * sizeof(int));

    int j = 0;
    for (auto i : q) {
//        cout << "i: " << i.i << endl;
//        cerr << i.x2 << endl;
        while (j < (int) xy.size() && xy[j].fs <= i.x2) {
            upd(0, 1, m + 1, xy[j].sc, xy[j].fs);
            j++;
        }
        int mn = get(0, 1, m + 1, i.y1, i.y2 + 1);
//        cout << mn << endl;
        if (mn >= i.x1) {
            good[i.i] = true;
        }
    }

    memset(tree, INF, 500000 * sizeof(int));

    sort(all(q), comp_yx);
    j = 0;
    for (auto i : q) {
//        cout << "i: " << i.i << endl;
        while (j < (int) yx.size() && yx[j].fs <= i.y2) {
            upd(0, 1, n + 1, yx[j].sc, yx[j].fs);
            j++;
        }
        int mn = get(0, 1, n + 1, i.x1, i.x2 + 1);
//        cout << mn << endl;
        if (mn >= i.y1) {
            good[i.i] = true;
        }
    }

    for (int i = 1; i <= Q; i++) {
        if (good[i]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
	return 0;
}