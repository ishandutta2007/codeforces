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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

struct magic {
    vector<unsigned> v;
    magic() {
        v = vector<unsigned> ();
    }
    magic(unsigned a) {
        v = vector<unsigned> ();
        a ^= (1u << 30);
        v.pb(a);
    }
    void add(int k) {
        for (int i = 0; i < sz(v); i++) {
            v[i] ^= k;
        }
    }
};

magic join(const magic & a, const magic & b) {
    magic ans;
    for (int i = 0; i < sz(a.v); i++) {
        ans.v.pb(a.v[i]);
    }
    for (int i = 0; i < sz(b.v); i++) {
        ans.v.pb(b.v[i]);
    }
    vector<unsigned> m(sz(ans.v));
    for (int i = 0; i < sz(ans.v); i++) {
        m[i] = ans.v[i];
    }
    int row = 0, col = 0;
    for (; row < sz(m) && col <= 30; col++) {
        int best = row;
        for (int i = row + 1; i < sz(m); i++) {
            if (m[i] & (1u << col)) {
                best = i;
                break;
            }
        }
        if (!(m[best] & (1u << col))) {
            continue;
        }
        swap(m[best], m[row]);
        swap(ans.v[best], ans.v[row]);
        for (int i = row + 1; i < sz(m); i++) {
            if (m[i] & (1u << col)) {
                m[i] ^= m[row];
            }
        }
        row++;
    }
    ans.v.resize(row);
    return ans;
}

const int N = 2e5 + 100;

int n, q, a[N];
int add[1 << 19];
magic val[1 << 19];

void build(int v, int vl, int vr) {
    if (vr == vl + 1) {
        val[v] = magic(a[vl]);
    } else {
        int mid = (vl + vr) / 2;
        build(v * 2 + 1, vl, mid);
        build(v * 2 + 2, mid, vr);
        val[v] = join(val[v * 2 + 1], val[v * 2 + 2]);
    }
}

void upd(int v, int vl, int vr, int l, int r, int num) {
    if (vl >= r || vr <= l) {
        return;
    }
    if (vl >= l && vr <= r) {
        add[v] ^= num;
        val[v].add(num);
    } else {
        int mid = (vl + vr) / 2;
        upd(v * 2 + 1, vl, mid, l, r, num);
        upd(v * 2 + 2, mid, vr, l, r, num);
        val[v] = join(val[v * 2 + 1], val[v * 2 + 2]);
        val[v].add(add[v]);
    }
}

magic get(int v, int vl, int vr, int l, int r) {
    if (vl >= r || vr <= l) {
        return magic();
    }
    if (vl >= l && vr <= r) {
        return val[v];
    } else {
        int mid = (vl + vr) / 2;
        magic ans = join(get(v * 2 + 1, vl, mid, l, r), get(v * 2 + 2, mid, vr, l, r));
        ans.add(add[v]);
        return ans;
    }
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    build(0, 0, n);
//        for (int i = 0; i < n; i++) {
//            cout << (get(0, 0, n, i, i + 1).v[0] ^ (1 << 30)) << ' ';
//        }
//        cout << endl;
    for (int i = 0; i < q; i++) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        l--;
        if (t == 1) {
            int k;
            scanf("%d", &k);
            upd(0, 0, n, l, r, k);
        } else {
            magic ans = join(get(0, 0, n, l, r), magic(0));
            int res = sz(ans.v);
            printf("%d\n", (1 << (res - 1)));
        }
//        for (int i = 0; i < n; i++) {
//            cout << (get(0, 0, n, i, i + 1).v[0] ^ (1 << 30)) << ' ';
//        }
//        cout << endl;
    }
    return 0;
}