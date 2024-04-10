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

const int MOD = 1e9 + 7;

const int N = 55000;

struct matrix {
    int a, b, c, d;
    matrix(int a = 1, int b = 0, int c = 0, int d = 1) : a(a), b(b), c(c), d(d) {}
    print() {
        cout << a << ' ' << b << endl << c << ' ' << d << endl;
    }
};

int n, p, s[N];
ll k;

matrix operator*(const matrix & x, const matrix & y) {
    return matrix((x.a * 1ll * y.a + x.b * 1ll * y.c) % p, (x.a * 1ll * y.b + x.b * 1ll * y.d) % p, (x.c * 1ll * y.a + x.d * 1ll * y.c) % p, (x.c * 1ll * y.b + x.d * 1ll * y.d) % p);
}

matrix tree[N * 4];

void build(int v, int vl, int vr) {
    if (vr == vl + 1) {
        tree[v] = matrix(s[vl + 1], s[vl], 1, 0);
    } else {
        int mid = (vl + vr) / 2;
        build(v * 2 + 1, vl, mid);
        build(v * 2 + 2, mid, vr);
        tree[v] = tree[v * 2 + 2] * tree[v * 2 + 1];
    }
}

matrix get(int v, int vl, int vr, int l, int r) {
    if (l == r) {
        return matrix();
    }
    if (vr <= l || vl >= r) {
        return matrix();
    }
    if (vl >= l && vr <= r) {
        return tree[v];
    } else {
        int mid = (vl + vr) / 2;
        return get(v * 2 + 2, mid, vr, l, r) * get(v * 2 + 1, vl, mid, l, r);
    }
}

matrix power(matrix a, ll p) {
    matrix ans = matrix();
    while (p) {
        if (p & 1) {
            ans = ans * a;
        }
        p >>= 1;
        a = a * a;
    }
    return ans;
}

matrix magic(ll l, ll r) {
    assert(l <= r);
    ll block_l = l / n;
    ll block_r = r / n;
    if (block_l == block_r) {
        return get(0, 0, n, l % n, r % n);
    } else {
        return get(0, 0, n, 0, r % n) * power(tree[0], block_r - block_l - 1) * get(0, 0, n, l % n, n);
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    cin >> k >> p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    s[n] = s[0];
    build(0, 0, n);
    int m;
    scanf("%d", &m);
    vector<pair<ll, int> > bad;
    for (int i = 0; i < m; i++) {
        pair<ll, int> j;
        scanf(LLD "%d", &j.fs, &j.sc);
        bad.pb(j);
    }
    sort(all(bad));

    ll cur = 0;
    matrix mat = matrix(1, 0, 0, 0);
    int lst = 0;
    for (int ii = 0; ii < bad.size(); ii++) {
        pair<ll, int> i = bad[ii];
        if (i.fs > k) {
            break;
        }
        if (ii > 0 && bad[ii - 1].fs < i.fs - 1) {
            mat = matrix(s[(bad[ii - 1].fs + 1) % n], bad[ii - 1].sc, 1, 0) * mat;
            cur++;
        }
        mat = magic(cur, i.fs - 1) * mat;
//        mat.print();
        matrix mult = matrix(i.sc, s[(i.fs + n - 1) % n], 1, 0);
        if (ii > 0 && bad[ii - 1].fs == bad[ii].fs - 1) {
            mult.b = bad[ii - 1].sc;
        }
        mat = mult * mat;
//        mat.print();
        cur = i.fs;
        lst = ii;
    }
    if (bad.size() && bad[lst].fs < k) {
        pair<ll, int> i = bad[lst];
        matrix mult = matrix(s[(i.fs + 1) % n], i.sc, 1, 0);
        if (lst < (int) bad.size() - 1 && bad[lst + 1].fs == bad[lst].fs + 1) {
            mult.a = bad[lst + 1].sc;
        }
        mat = mult * mat;
        cur++;
//        mat.print();
    }
    mat = magic(cur, k) * mat;
//        mat.print();
    printf("%d\n", mat.c % p);

    return 0;
}