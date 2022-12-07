#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9);

int n;
int lo[75000], hi[75000], loy[75000], a[75000], b[75000], hiy[75000];
int m;
int from, to, x;

struct S {
    int key;
    LL a, b, c;
    S(int key, LL a, LL b, LL c) : key(key), a(a), b(b), c(c) {}

    inline bool operator < (const S &rhs) const {
        return key < rhs.key;
    }
};

vector<S> sx1[1 << 18], sx2[1 << 18];
vector<int> ix1[1 << 18], ix2[1 << 18];
LL suma[1 << 18], sumb[1 << 18];
const int off = 1 << 17;

void stBuild() {
    forn(i, n) for (int j = off + i; j >= 1; j >>= 1) {
        sx1[j].pb(S(-lo[i], a[i], b[i], loy[i]));
        sx2[j].pb(S(hi[i], a[i], b[i], hiy[i]));
        suma[j] += a[i];
        sumb[j] += b[i];
    }
    forn(i, 2 * off) {
        sort(sx1[i].begin(), sx1[i].end());
        sort(sx2[i].begin(), sx2[i].end());
        LL pa = 0, pb = 0, pc = 0;
        for (S &s : sx1[i]) {
            ix1[i].pb(s.key);
            pa += s.a;
            pb += s.b;
            pc += s.c;
            s.a = pa;
            s.b = pb;
            s.c = pc;
        }
        pa = 0, pb = 0, pc = 0;
        for (S &s : sx2[i]) {
            ix2[i].pb(s.key);
            pa += s.a;
            pb += s.b;
            pc += s.c;
            s.a = pa;
            s.b = pb;
            s.c = pc;
        }
    }
}

LL xi;

LL stGet(int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (l == L && r == R) {
        LL sa = suma[v];
        LL sb = sumb[v];

        int ind = lower_bound(ix1[v].begin(), ix1[v].end(), -xi + 1) - ix1[v].begin();
        LL res = (ind == 0 ? 0ll : sx1[v][ind - 1].c);
        sa -= (ind == 0 ? 0ll : sx1[v][ind - 1].a);
        sb -= (ind == 0 ? 0ll : sx1[v][ind - 1].b);

        ind = lower_bound(ix2[v].begin(), ix2[v].end(), xi) - ix2[v].begin();
        res += (ind == 0 ? 0ll : sx2[v][ind - 1].c);
        sa -= (ind == 0 ? 0ll : sx2[v][ind - 1].a);
        sb -= (ind == 0 ? 0ll : sx2[v][ind - 1].b);

        res += sa * xi + sb;
        return res;
    }
    int mid = (L + R) >> 1;
    return stGet(2 * v, L, mid, l, min(r, mid)) +
        stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

LL solve(int from, int to, int x) {
    xi = x;
    return stGet(1, 0, off - 1, from, to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n) {
        cin >> lo[i] >> hi[i] >> loy[i] >> a[i] >> b[i] >> hiy[i];
    }
    stBuild();
    cin >> m;
    int last = 0;
    forn(i, m) {
        cin >> from >> to >> x;
        --from, --to;
        x = (x + last) % MOD;
        LL ans = solve(from, to, x);
        last = ans % MOD;
        cout << ans << '\n';
    }
    return 0;
}